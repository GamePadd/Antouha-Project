#pragma once

#include <stack>
#include "IScreen.h"

namespace Ant {
	class ScreenManager {
		private:
			std::stack<IScreen*> screenStack;

		public:
			~ScreenManager();

			void pushScreen(IScreen* screen);
			void popScreen();

			IScreen* getTop() { return screenStack.top(); }
			size_t getScreenCount() { return screenStack.size(); }
	};
}