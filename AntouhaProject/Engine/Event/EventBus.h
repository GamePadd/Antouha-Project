#include <unordered_map>
#include <functional>
#include <typeinfo>
#include <typeindex>
#include <vector>
#include <queue>
#include <memory>
#pragma once

#include "IEvent.h"

namespace Ant {
	class EventBus {
		using Callback = std::function<void(const IEvent&)>;
		private:
			std::unordered_map<size_t, std::vector<Callback>> handlers;
			std::queue<std::unique_ptr<IEvent>> eventQueue;
		public:
			template <typename T>
			void subscribe(std::function<void(const T&)> callback) {
				size_t id = typeid(T).hash_code();

				handlers[id].push_back([callback](const IEvent& data) {
					callback((*(const T*)&data));
				});
			}

			template <typename T>
			void queueEvent(T&& event) {
				eventQueue.push(std::make_unique<T>(std::forward<T>(event)));
			}

			void process();
	};
}