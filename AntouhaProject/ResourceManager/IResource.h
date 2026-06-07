#include <string>

namespace Ant {
	class IResource {
		public: 
			virtual bool load(const std::string& path) = 0;
			virtual void free() = 0;
			virtual ~IResource() = default;
	};
}