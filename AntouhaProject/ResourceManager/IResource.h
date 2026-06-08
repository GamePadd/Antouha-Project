#pragma once

#include <string>

namespace Ant {
	class IResource {
		public: 
			virtual bool load() = 0;
			virtual bool isLoaded() = 0;
			virtual void free() = 0;
			virtual ~IResource() = default;
	};
}