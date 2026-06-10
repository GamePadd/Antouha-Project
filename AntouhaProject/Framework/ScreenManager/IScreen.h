#pragma once


namespace Ant {
	struct GameServices;

	class IScreen {
		public:
			virtual ~IScreen() = default;

			virtual void init(const GameServices& services) = 0;
			virtual void onUpdate(float dt) = 0;
			virtual void onRender() = 0;
			virtual void onClose() = 0;
	};
}