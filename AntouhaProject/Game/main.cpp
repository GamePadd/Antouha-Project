#include "../Engine/EngineH.h"
#include <SDL3/SDL_main.h>

int main(int argc, char* argv[])
{
	int exitCode{ 0 };

	Ant::Engine engine(Ant::EngineConfig(Ant::WindowRenderer::SDL, Ant::RendererAPI::SDL, "Test", 640, 480));
	engine.run();

	return exitCode;
}
