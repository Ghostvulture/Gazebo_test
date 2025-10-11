#!/bin/bash

echo "============================================"
echo "Bipedal Robot Balance Control Test Script"
echo "============================================"

# Color codes for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to print colored output
print_status() {
    echo -e "${GREEN}[INFO]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARN]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

print_info() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

# Check if ROS is installed and sourced
check_ros() {
    if [ -z "$ROS_DISTRO" ]; then
        print_error "ROS is not sourced. Please source your ROS setup.bash"
        print_info "Example: source /opt/ros/humble/setup.bash"
        exit 1
    else
        print_status "ROS $ROS_DISTRO detected"
    fi
}

# Function to show usage
show_usage() {
    echo "Usage: $0 [option]"
    echo ""
    echo "Options:"
    echo "  build     - Build the ROS package"
    echo "  sim       - Start Gazebo simulation only"
    echo "  control   - Start balance controller only"
    echo "  full      - Start full system (Gazebo + controller)"
    echo "  test      - Run manual control test"
    echo "  clean     - Clean build files"
    echo "  help      - Show this help message"
    echo ""
}

# Build the ROS package
build_package() {
    print_status "Building ROS package..."
    
    # Check if we're in a catkin workspace
    if [ ! -f "CMakeLists.txt" ]; then
        print_error "Not in a ROS package directory"
        exit 1
    fi
    
    # Create symbolic link to package in catkin workspace if needed
    CATKIN_WS="$HOME/catkin_ws"
    if [ ! -d "$CATKIN_WS/src" ]; then
        print_warning "Catkin workspace not found. Creating one..."
        mkdir -p $CATKIN_WS/src
        cd $CATKIN_WS
        catkin_make
        print_info "Created catkin workspace at $CATKIN_WS"
    fi
    
    # Link package to catkin workspace
    PKG_LINK="$CATKIN_WS/src/bipedal_balance_control"
    if [ ! -L "$PKG_LINK" ]; then
        ln -s "$(pwd)" "$PKG_LINK"
        print_status "Linked package to catkin workspace"
    fi
    
    # Build
    cd $CATKIN_WS
    catkin_make
    
    if [ $? -eq 0 ]; then
        print_status "Build successful!"
        print_info "Don't forget to source: source $CATKIN_WS/devel/setup.bash"
    else
        print_error "Build failed!"
        exit 1
    fi
}

# Start Gazebo simulation
start_simulation() {
    print_status "Starting Gazebo simulation..."
    print_info "Loading bipedal robot model..."
    
    # Start Gazebo with the SDF file
    ign gazebo ../urdf.sdf &
    
    print_status "Gazebo started. Robot should be loaded."
    print_info "Use 'rosrun bipedal_balance_control balance_controller.py' to start control"
}

# Start balance controller
start_controller() {
    print_status "Starting balance controller..."
    
    # Check if ROS package is built and sourced
    if ! command -v rosrun &> /dev/null; then
        print_error "ROS commands not available. Make sure ROS is properly installed and sourced."
        exit 1
    fi
    
    # Start the controller
    rosrun bipedal_balance_control balance_controller.py
}

# Start full system
start_full_system() {
    print_status "Starting full balance control system..."
    
    # Start roscore if not running
    if ! pgrep -x "roscore" > /dev/null; then
        print_status "Starting roscore..."
        roscore &
        sleep 3
    fi
    
    # Start Gazebo
    print_status "Starting Gazebo..."
    ign gazebo ../urdf.sdf &
    sleep 5
    
    # Start controller
    print_status "Starting balance controller..."
    rosrun bipedal_balance_control balance_controller.py
}

# Manual control test
manual_test() {
    print_status "Starting manual control test..."
    print_info "This will publish test velocity commands"
    
    echo "Available test commands:"
    echo "1. Forward motion"
    echo "2. Backward motion" 
    echo "3. Turn left"
    echo "4. Turn right"
    echo "5. Stop"
    echo "6. Exit"
    
    while true; do
        read -p "Enter command (1-6): " cmd
        case $cmd in
            1)
                print_info "Publishing forward motion..."
                rostopic pub /cmd_vel geometry_msgs/Twist "linear: {x: 0.2, y: 0.0, z: 0.0}
angular: {x: 0.0, y: 0.0, z: 0.0}" -1
                ;;
            2)
                print_info "Publishing backward motion..."
                rostopic pub /cmd_vel geometry_msgs/Twist "linear: {x: -0.2, y: 0.0, z: 0.0}
angular: {x: 0.0, y: 0.0, z: 0.0}" -1
                ;;
            3)
                print_info "Publishing turn left..."
                rostopic pub /cmd_vel geometry_msgs/Twist "linear: {x: 0.0, y: 0.0, z: 0.0}
angular: {x: 0.0, y: 0.0, z: 0.3}" -1
                ;;
            4)
                print_info "Publishing turn right..."
                rostopic pub /cmd_vel geometry_msgs/Twist "linear: {x: 0.0, y: 0.0, z: 0.0}
angular: {x: 0.0, y: 0.0, z: -0.3}" -1
                ;;
            5)
                print_info "Publishing stop..."
                rostopic pub /cmd_vel geometry_msgs/Twist "linear: {x: 0.0, y: 0.0, z: 0.0}
angular: {x: 0.0, y: 0.0, z: 0.0}" -1
                ;;
            6)
                print_status "Exiting manual test"
                break
                ;;
            *)
                print_warning "Invalid command"
                ;;
        esac
    done
}

# Clean build files
clean_build() {
    print_status "Cleaning build files..."
    
    CATKIN_WS="$HOME/catkin_ws"
    if [ -d "$CATKIN_WS" ]; then
        cd $CATKIN_WS
        catkin_make clean
        print_status "Cleaned catkin workspace"
    fi
    
    # Remove any local build artifacts
    rm -rf build/ devel/
    print_status "Cleaned local build files"
}

# Main script logic
main() {
    check_ros
    
    case "$1" in
        build)
            build_package
            ;;
        sim)
            start_simulation
            ;;
        control)
            start_controller
            ;;
        full)
            start_full_system
            ;;
        test)
            manual_test
            ;;
        clean)
            clean_build
            ;;
        help|--help|-h)
            show_usage
            ;;
        *)
            print_error "Unknown option: $1"
            show_usage
            exit 1
            ;;
    esac
}

# Run main function with all arguments
main "$@"
