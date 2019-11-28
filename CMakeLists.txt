cmake_minimum_required(VERSION 3.1)
project(City-gen)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# qt5
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
	set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

add_definitions(-O2 -D_FILE_OFFSET_BITS=64 -fPIC)

find_package(PkgConfig)
find_package(Qt5Widgets)
find_package(Qt5OpenGL)
find_package(Qt5Gui)
find_package(OpenGL)
set(plugins Qt5::OpenGL Qt5::Gui)

# libigl
option(LIBIGL_WITH_OPENGL            "Use OpenGL"         ON)
option(LIBIGL_WITH_OPENGL_GLFW       "Use GLFW"           ON)

find_package(LIBIGL REQUIRED QUIET)

# Add your project files
file(GLOB SRCFILES src/*.cpp)
file(GLOB HDRFILES src/*.h)
add_executable(city-gen ${SRCFILES} ${HDRFILES})

#qt5_use_modules(city-gen Core Gui Widgets OpenGL)

target_link_libraries(city-gen igl::core igl::opengl_glfw ${QT_LIBRARIES} ${OPENGL_LIBRARIES})
