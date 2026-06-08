set(SOURCES
	"Game/Game.cpp"
	"ResourceManager/Resources/Texture.cpp"
	"Event/EventBus.cpp"
	"Game/main.cpp"
	"Window/Window.cpp"
)

set(HEADERS
	"Game/Game.h"
	"ResourceManager/ResourceManager.h"
	"ResourceManager/IResource.h"
	"ResourceManager/Resources/Texture.h"
	"Event/EventBus.h"
	"Event/IEvent.h"
	"Game/Events.h"
	"Window/Window.h"
)

add_executable (AntouhaProject WIN32 ${SOURCES} ${HEADERS})
target_link_libraries(AntouhaProject PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)