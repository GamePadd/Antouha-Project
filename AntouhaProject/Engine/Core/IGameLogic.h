#pragma once

namespace Ant {
	class IGameLogic {
		public:
			virtual ~IGameLogic() = default;

			virtual void init() = 0;
			virtual void update() = 0;
			virtual void render() = 0;
			virtual void quit() = 0;
	};
}