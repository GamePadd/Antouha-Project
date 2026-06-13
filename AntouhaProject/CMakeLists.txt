set(SOURCES
	"Framework/ResourceManager/Resources/Texture.cpp"
	"Framework/ResourceManager/Resources/Text.cpp"
	"Framework/Event/EventBus.cpp"
	"Game/main.cpp"
	"Framework/Window/SDLWindow.cpp"
	"Framework/Renderer/SDLRenderer.cpp"
	"Framework/Core/Framework.cpp"
	"Framework/InputService/InputService.cpp"
	"Framework/ScreenManager/ScreenManager.cpp"
)

set(HEADERS
	"Game/Game.h"
	"Framework/ResourceManager/ResourceManager.h"
	"Framework/ResourceManager/IResource.h"
	"Framework/ResourceManager/Resources/Texture.h"
	"Framework/ResourceManager/Resources/Text.h"
	"Framework/Event/EventBus.h"
	"Framework/Event/IEvent.h"
	"Game/Events.h"
	"Framework/Window/SDLWindow.h"
	"Framework/Window/IWindow.h"
	"Framework/Renderer/SDLRenderer.h"
	"Framework/Core/Framework.h"
	"Framework/Core/IGameLogic.h"
	"Framework/InputService/InputService.h"
	"Framework/InputService/KeyCodes.h"
	"Framework/Event/Events.h"
	"Framework/FrameworkH.h"
	"Framework/ScreenManager/ScreenManager.h"
	"Framework/ScreenManager/IScreen.h"
	"Framework/Math/Math.h"
)

add_executable (AntouhaProject ${SOURCES} ${HEADERS})
target_include_directories(AntouhaProject PRIVATE "${CMAKE_SOURCE_DIR}/thirdparty/GLM")
target_link_libraries(AntouhaProject PRIVATE SDL3::SDL3 SDL3_image::SDL3_image SDL3_ttf::SDL3_ttf)