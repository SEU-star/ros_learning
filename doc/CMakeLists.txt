cmake_minimum_required(VERSION 3.0.2)
project(package_name)

add_compile_options(-std=c++11)
 
#此功能包用到的其他功能包放在此处  指定依赖
find_package(catkin REQUIRED COMPONENTS

)
#添加自定义的msg文件   			   写在此处 
 add_message_files(
   FILES
   #eg:
   message1.msg
 )
#自己定义的msg文件生成对应的头文件  关键
generate_messages(DEPENDENCIES std_msgs)

catkin_package(

)
#指定C++头文件的路径
include_directories(
 #include是指功能包创建后,自己生成的文件夹,在此文件夹下的头文件可以被直接在CPP文件中引用
 include
  ${catkin_INCLUDE_DIRS}
)
#生成可执行目标文件
	#并且同时编译多个cpp文件
add_executable(${PROJECT_NAME}_node src/_math.cpp 
                                    src/path_track.cpp
                                    src/pc_stm32.cpp
                                    src/record_path.cpp)

add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES})
