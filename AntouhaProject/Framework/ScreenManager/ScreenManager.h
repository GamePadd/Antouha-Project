#pragma once

#include <stack>
#include <memory>
#include <utility>
#include <queue>

#include "IScreen.h"

namespace Ant {
	enum class ScreenOpType {Push,Pop};

	class ScreenManager {
	private:
		using OperationsPair = std::pair<ScreenOpType, std::unique_ptr<IScreen>>;

		std::stack<std::unique_ptr<IScreen>> screenStack;
		std::queue<OperationsPair> opQueue;

		friend class Framework;

		void Process();
	public:
		~ScreenManager();

		void pushScreen(std::unique_ptr<IScreen> screen);
		void popScreen();

		IScreen* getTop() { return screenStack.top().get(); }
		size_t getScreenCount() { return screenStack.size(); }
	};
}