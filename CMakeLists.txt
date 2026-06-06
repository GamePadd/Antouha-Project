cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 23)

project ("AntouhaProject")

set(SDLIMAGE_VENDORED OFF)

add_subdirectory ("AntouhaProject")
add_subdirectory("thirdparty/SDL3")
add_subdirectory("thirdparty/SDL3_Image")