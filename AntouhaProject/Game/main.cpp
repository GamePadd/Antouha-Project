#include "../Framework/FrameworkH.h"
#include <SDL3/SDL_main.h>
#include "Game.h"

int main(int argc, char* argv[])
{
	int exitCode{ 0 };
	
	AntouhaProject* game = new AntouhaProject();
	Ant::Framework framework(Ant::FrameworkConfig(Ant::WindowRenderer::SDL, Ant::RendererAPI::SDL, "Antouha Project", Ant::Vec2i(640,480),Ant::Vec2i(640,480)), game);
	framework.run();

	return exitCode;
}
