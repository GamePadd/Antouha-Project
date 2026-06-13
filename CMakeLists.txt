cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 23)

project ("AntouhaProject")

set(SDL3IMAGE_AVIF OFF CACHE BOOL "" FORCE)
set(SDL3IMAGE_WEBP OFF CACHE BOOL "" FORCE) 

add_subdirectory ("AntouhaProject")
add_subdirectory("thirdparty/SDL3")
add_subdirectory("thirdparty/SDL3_Image")
add_subdirectory("thirdparty/SDL3_ttf")