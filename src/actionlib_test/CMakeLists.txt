cmake_minimum_required(VERSION 2.8.3)
project(actionlib_test)

find_package(catkin REQUIRED COMPONENTS
  actionlib
  actionlib_msgs
  roscpp
  rospy
  std_msgs
  message_generation
)

 add_action_files(
   DIRECTORY action
   FILES
   DoDishes.action
 )

 generate_messages(
   DEPENDENCIES
   actionlib_msgs
 )

include_directories(
  #include 
  ${catkin_INCLUDE_DIRS}
)

add_executable(actionlib_client_node src/actionlib_client.cpp)
add_dependencies(actionlib_client_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(actionlib_client_node ${catkin_LIBRARIES})

add_executable(actionlib_server_node src/actionlib_server.cpp)
add_dependencies(actionlib_server_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(actionlib_server_node ${catkin_LIBRARIES})
