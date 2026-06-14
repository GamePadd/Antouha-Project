set(SOURCES
	"Framework/ResourceManager/Resources/Texture.cpp"
	"Framework/ResourceManager/Resources/Text.cpp"
	"Framework/Event/EventBus.cpp"
	"Framework/Window/SDLWindow.cpp"
	"Framework/Renderer/SDLRenderer.cpp"
	"Framework/Core/Framework.cpp"
	"Framework/InputService/InputService.cpp"
	"Framework/ScreenManager/ScreenManager.cpp"

	"Game/main.cpp"
	"Game/BulletSystem/BulletManager.cpp"
	"Game/BulletSystem/BulletPool.cpp"
	"Game/Levels/Level1.cpp"
	"Game/Game.cpp"
)

set(HEADERS
	"Framework/ResourceManager/ResourceManager.h"
	"Framework/ResourceManager/IResource.h"
	"Framework/ResourceManager/Resources/Texture.h"
	"Framework/ResourceManager/Resources/Text.h"
	"Framework/Event/EventBus.h"
	"Framework/Event/IEvent.h"
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

	"Game/Game.h"
	"Game/Events.h"
	"Game/Context.h"
	"Game/GameStructures.h"
	"Game/BulletSystem/BulletManager.h"
	"Game/BulletSystem/BulletPool.h"
	"Game/UI/Button.h"
	"Game/UI/IButton.h"
	"Game/Levels/Level1.h"
)

add_executable (AntouhaProject ${SOURCES} ${HEADERS})
target_include_directories(AntouhaProject PRIVATE "${CMAKE_SOURCE_DIR}/thirdparty/GLM")
target_link_libraries(AntouhaProject PRIVATE SDL3::SDL3 SDL3_image::SDL3_image SDL3_ttf::SDL3_ttf)