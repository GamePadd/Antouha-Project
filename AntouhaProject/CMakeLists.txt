set(SOURCES
	"Game/Game.cpp"
	"Engine/ResourceManager/Resources/Texture.cpp"
	"Engine/Event/EventBus.cpp"
	"Game/main.cpp"
	"Engine/Window/Window.cpp"
	"Engine/Renderer/Renderer.cpp"
)

set(HEADERS
	"Game/Game.h"
	"Engine/ResourceManager/ResourceManager.h"
	"Engine/ResourceManager/IResource.h"
	"Engine/ResourceManager/Resources/Texture.h"
	"Engine/Event/EventBus.h"
	"Engine/Event/IEvent.h"
	"Game/Events.h"
	"Engine/Window/Window.h"
	"Engine/Window/IWindow.h"
	"Engine/Renderer/Renderer.h"
)

add_executable (AntouhaProject WIN32 ${SOURCES} ${HEADERS})
target_link_libraries(AntouhaProject PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)