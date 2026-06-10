#pragma once

#include "GameServices.h"
 
namespace Ant {
	class IGameLogic {
		public:
			virtual ~IGameLogic() = default;

			virtual void init(const GameServices& services) = 0;
			virtual void onUpdate(float dt) = 0;
			virtual void onQuit() = 0;
	};
}