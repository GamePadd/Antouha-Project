set(SOURCES
	"Game/Game.cpp"
	"Engine/ResourceManager/Resources/Texture.cpp"
	"Engine/Event/EventBus.cpp"
	"Game/main.cpp"
	"Engine/Window/SDLWindow.cpp"
	"Engine/Renderer/SDLRenderer.cpp"
	"Engine/Core/Engine.cpp"
	"Engine/InputService/InputService.cpp"
)

set(HEADERS
	"Game/Game.h"
	"Engine/ResourceManager/ResourceManager.h"
	"Engine/ResourceManager/IResource.h"
	"Engine/ResourceManager/Resources/Texture.h"
	"Engine/Event/EventBus.h"
	"Engine/Event/IEvent.h"
	"Game/Events.h"
	"Engine/Window/SDLWindow.h"
	"Engine/Window/IWindow.h"
	"Engine/Renderer/SDLRenderer.h"
	"Engine/Core/Engine.h"
	"Engine/Core/IGameLogic.h"
	"Engine/InputService/InputService.h"
	"Engine/InputService/KeyCodes.h"
	"Engine/InputService/IInputService.h"
)

add_executable (AntouhaProject WIN32 ${SOURCES} ${HEADERS})
target_link_libraries(AntouhaProject PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)