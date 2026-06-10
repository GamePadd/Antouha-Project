#pragma once

#include <functional>

namespace Ant {
	class IWindow {
		public:
			virtual ~IWindow() = default;
			virtual bool init() = 0;

			virtual int getWidth() const = 0;
			virtual int getHeight() const = 0;

			virtual void swapBuffers() = 0;
			virtual void pollEvents() = 0;

			using CloseCallback = std::function<void()>;

			virtual void setOnClose(CloseCallback callback) = 0;
	};
}