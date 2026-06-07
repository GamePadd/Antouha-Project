set(SOURCES
	"Game/Game.cpp"
	"ResourceManager/Resources/Texture.cpp"
)

set(HEADERS
	"Game/Game.h"
	"ResourceManager/ResourceManager.h"
	"ResourceManager/IResource.h"
	"ResourceManager/Resources/Texture.h"
)

add_executable (AntouhaProject WIN32 ${SOURCES} ${HEADERS})
target_link_libraries(AntouhaProject PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)