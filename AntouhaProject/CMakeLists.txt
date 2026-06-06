set(SOURCES
	AntouhaProject.cpp
)

set(HEADERS
	AntouhaProject.h
)

add_executable (AntouhaProject WIN32 ${SOURCES} ${HEADERS})
target_link_libraries(AntouhaProject PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)