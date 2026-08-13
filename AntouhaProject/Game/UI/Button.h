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
		Button(const Ant::GameServices& services, std::string textResourceName, std::string _text = "", std::string fontPath = "Resources/UI/Fonts/pixel.ttf", SDL_Color color = SDL_Color(255, 255, 255, 255), std::string backgroundName = "");
		bool isHovered;
		bool getInited() override { return isServicesInited; }
		//ÍÀÊÎÑÒÛËßË ÁËßÒÜ ÓÁËÞÄÎÊ
		Ant::Vec2f* getSize() override { return &size; }
		Ant::Vec2f* getPos() override { return &pos; }
		float* getFontSize() override { return text->getSize(); }

		void setText(std::string _text, SDL_Color _color, int size) override;
		void setFontSize(int size) override;
		void setBackground(std::string textureName) override;
		void setFont(std::string font, int size) override;
		void setSizeMul(float mul) override;
		void setSize(Ant::Vec2f size) override;
		void setPos(Ant::Vec2f pos) override;

		void setOnClick(ButtonCallback callback) override;
		void setOnHover(ButtonCallback callback) override;
		void setOnLeave(ButtonCallback callback) override;

		void updateState() override;

		void render(int layer) override;
};