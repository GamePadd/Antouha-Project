#pragma once

#include <concepts>
#include <unordered_map>
#include <string>
#include <iterator>

namespace Ant {
	template <typename T>
	concept Resource = requires(T res) {
		{ res.load() } -> std::same_as<bool>;
		{ res.free() } -> std::same_as<void>;
	};

	template <Resource T>
	class ResourceManager {
		private:
			std::unordered_map<std::string, T*> resources;
		public:
			~ResourceManager() { removeAll(); }

			template <typename... Args>
			void load(const std::string& resourceName, Args&&... args) {
				auto it = resources.find(resourceName);
				if (it != resources.end()) { return; }

				T* resource = new T (std::forward<Args>(args)...);

				if (resource->load()) {
					resources[resourceName] = std::move(resource);
				}
				else {
					delete resource;
				}
			}

			T* get(const std::string& resourceName) {
				auto it = resources.find(resourceName);
				if (it == resources.end()) { return nullptr; }
				return it->second;
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