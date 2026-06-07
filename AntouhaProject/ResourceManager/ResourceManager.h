#include <concepts>
#include <unordered_map>
#include <string>
#include <iterator>

namespace Ant {
	template <typename T>
	concept Resource = requires(T res, const std::string& path) {
		{ res.load(path) } -> std::same_as<bool>;
		{ res.free() } -> std::same_as<void>;
	};

	template <Resource T>
	class ResourceManager {
		private:
			std::unordered_map<std::string, T*> resources;
		public:
			void load(const std::string& resourceName, const std::string& filePath) {
				T* resource = new T();
				if (resource->load(filePath)) {
					resources[resourceName] = std::move(resource);
				}
				else {
					delete resource;
				}
			}

			void remove(const std::string& resourceName) {
				auto it = resources.find(resourceName);
				if (it == resources.end()) { return; }
				it->second->free();
				resources.erase(it);
			}

			void removeAll() {
				auto iter = resources.begin();
				while (iter != resources.end()) {
					iter->second->free();
					iter = resources.erase(iter);
				}
			}
	};
}