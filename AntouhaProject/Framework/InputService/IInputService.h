	#pragma once

	namespace Ant {
		class IInputService {
			public:
				virtual ~IInputService() = default;
				virtual bool isKeyPressed() = 0;
		};
	}