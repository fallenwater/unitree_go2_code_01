cmake_minimum_required(VERSION 3.5)
project(go2_tutorial)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(unitree_go REQUIRED)
find_package(unitree_api REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)        # 速度参数依赖
find_package(go2_tutorial_inter REQUIRED)   # 创建依赖


add_executable(go2_ctrl src/go2_ctrl.cpp)
add_executable(go2_state src/go2_state.cpp)
add_executable(go2_cruising_client src/go2_cruising_client.cpp)
add_executable(go2_cruising_service src/go2_cruising_service.cpp)

target_include_directories(go2_ctrl PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

target_include_directories(go2_state PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

target_include_directories(go2_cruising_client PUBLIC     
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

target_include_directories(go2_cruising_service PUBLIC        # 通过这个代码就可以使用include里面的头文件了，原理等待查找ing三
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

ament_target_dependencies(
  go2_ctrl
  "rclcpp"
  "unitree_go"
  "unitree_api"
)

ament_target_dependencies(
  go2_state
  "rclcpp"
  "unitree_go"
  "unitree_api"
  "nav_msgs"
)

ament_target_dependencies(
  go2_cruising_client
  "rclcpp"
  "unitree_go"
  "unitree_api"
  "nav_msgs"
  "geometry_msgs"
  "go2_tutorial_inter"
)

ament_target_dependencies(
  go2_cruising_service
  "rclcpp"
  "unitree_go"
  "unitree_api"
  "nav_msgs"
  "geometry_msgs"
  "go2_tutorial_inter"
)

install(TARGETS go2_ctrl
      DESTINATION lib/${PROJECT_NAME})

install(TARGETS go2_state
      DESTINATION lib/${PROJECT_NAME})
      
install(TARGETS go2_cruising_client
      DESTINATION lib/${PROJECT_NAME})
      
install(TARGETS go2_cruising_service
      DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY include/
  DESTINATION include
)

# 安装个人导入的文件夹 用于 install 的读取
install(DIRECTORY launch params 
        DESTINATION share/${PROJECT_NAME})

        
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
