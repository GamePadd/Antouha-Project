#pragma once

#include "../../Framework/FrameworkH.h"

class IButton {
	public:
		virtual ~IButton() = default;
		virtual bool getInited() = 0;

		virtual void setText(std::string _text, SDL_Color _color) = 0;
		virtual void setFont(std::string font) = 0;
		virtual void setBackground(std::string textureName) = 0;
		virtual void setSizeMul(float mul) = 0;
		virtual void setSize(Ant::Vec2f size) = 0;
		virtual void setPos(Ant::Vec2f pos) = 0;

		using ButtonCallback = std::function<void()>;

		virtual void setOnClick(ButtonCallback callback) = 0;

		virtual void setOnHover(ButtonCallback callback) = 0;
		virtual void setOnLeave(ButtonCallback callback) = 0;

		virtual void updateState() = 0;
		virtual void render(int layer) = 0;
};