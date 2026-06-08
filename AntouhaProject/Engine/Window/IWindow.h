#pragma once

namespace Ant {
	class IWindow {
		public:
			virtual ~IWindow() = default;
			virtual bool init() = 0;
			virtual int getWidth() const = 0;
			virtual int getHeight() const = 0;
	};
}