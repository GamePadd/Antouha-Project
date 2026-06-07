#include "../IResource.h"

namespace Ant {
	class Texture : public IResource {
		private:

		public:
			bool load(const std::string& path) override;
			void free() override;
	};
}