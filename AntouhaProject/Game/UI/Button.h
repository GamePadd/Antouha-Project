#pragma once
#include "../../Framework/FrameworkH.h"
#include "IButton.h"

class Button : public IButton {
	private:
		Ant::InputService* inputService;
		Ant::IRenderer* renderer;
		Ant::IWindow* window;
		Ant::ResourceManager<Ant::Texture>* textureManager;
		Ant::ResourceManager<Ant::Text>* textManager;

		Ant::Texture* background;
		Ant::Text* text;

		Ant::Vec2f pos;
		Ant::Vec2f size;

		float sizeMul;

		ButtonCallback onClick;
		ButtonCallback onHover;
		ButtonCallback onLeave;

		float mx;
		float my;

		float mxPrev;
		float myPrev;

		bool isServicesInited;
	public:
		Button(const Ant::GameServices& services, std::string textResourceName, std::string _text = "", SDL_Color color = SDL_Color(255, 255, 255, 255), std::string textureName = "", std::string fontPath = "arialmt.ttf");

		bool getInited() override { return isServicesInited; }

		void setText(std::string _text, SDL_Color _color) override;
		void setBackground(std::string textureName) override;
		void setFont(std::string font) override;
		void setSizeMul(float mul) override;
		void setSize(Ant::Vec2f size) override;
		void setPos(Ant::Vec2f pos) override;

		void setOnClick(ButtonCallback callback) override;
		void setOnHover(ButtonCallback callback) override;
		void setOnLeave(ButtonCallback callback) override;

		void updateState() override;

		void render(int layer) override;
};