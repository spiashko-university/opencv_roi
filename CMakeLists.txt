cmake_minimum_required(VERSION 3.9)
project(opencv_roi)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package( OpenCV REQUIRED )
set(SOURCE_FILES main.cpp)
add_executable(opencv_roi ${SOURCE_FILES})
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries( opencv_roi ${OpenCV_LIBS} )

configure_file(ocean.jpg ocean.jpg COPYONLY)
configure_file(opencv-logo.png opencv-logo.png COPYONLY)
