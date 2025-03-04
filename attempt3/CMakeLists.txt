cmake_minimum_required(VERSION 3.8)

project(attempt3)


include_directories(${CMAKE_SOURCE_DIR}/include)



find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


include_directories("C:/dlib-19.24")


set(DLIB_LIB "C:/dlib-19.24/build/dlib/Debug/dlib19.24.0_debug_64bit_msvc1943.lib")


add_executable(attempt3 
    "src/main.cpp" 
    "include/main.h" 
    "include/FaceDetector.h" 
    "src/FaceDetector.cpp" 
    "include/FaceRecognizer.h" 
    "src/FaceRecognizer.cpp"
    "C:/dlib-19.24/dlib/all/source.cpp"
)

target_compile_options(attempt3 PRIVATE "/bigobj")



target_link_libraries(attempt3 ${OpenCV_LIBS} ${DLIB_LIB})


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET attempt3 PROPERTY CXX_STANDARD 20)
endif()

message(STATUS "Project source directory: ${CMAKE_SOURCE_DIR}")
