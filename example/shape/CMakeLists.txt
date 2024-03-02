
cmake_minimum_required(VERSION 3.20)

project("generated_code")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find requirements
find_package(fastcdr REQUIRED)
find_package(fastrtps 2.12 REQUIRED)


message(STATUS "Configuring Shape...")
add_library(Shape_lib Shape.cxx)
target_link_libraries(Shape_lib fastcdr fastrtps)

add_executable(Shape ShapePubSubTypes.cxx ShapePublisher.cxx ShapeSubscriber.cxx ShapePubSubMain.cxx)
target_link_libraries(Shape fastcdr fastrtps
        Shape_lib )


