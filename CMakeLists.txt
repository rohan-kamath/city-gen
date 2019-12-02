cmake_minimum_required(VERSION 3.1)
project(City-gen)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(OpenMesh REQUIRED)
include_directories(${OPENMESH_INCLUDE_DIRS})
add_subdirectory(OpenMesh-8.0)

# Add your project files
file(GLOB SRCFILES src/*.cpp)
file(GLOB HDRFILES src/*.h)
add_executable(city-gen ${SRCFILES} ${HDRFILES})

target_link_libraries(city-gen OpenMeshCore OpenMeshTools)
