#include "../Engine/EngineH.h"
#include <SDL3/SDL_main.h>
#include "Game.h"

int main(int argc, char* argv[])
{
	int exitCode{ 0 };

	TestGame* game = new TestGame();
	Ant::Engine engine(Ant::EngineConfig(Ant::WindowRenderer::SDL, Ant::RendererAPI::SDL, "Test", 640, 480), game);
	engine.run();

	return exitCode;
}
