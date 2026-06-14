#include "Button.h"

//TODO: добавь систему выбора размера текста отдельно, + загляни в Framework Text, там тоже поработай над выбором размера текста

Button::Button(const Ant::GameServices& services, std::string textResourceName, std::string _text, SDL_Color color, std::string backgroundName, std::string fontPath) : isServicesInited{false} {
	inputService = services.input;
	renderer = services.renderer;
	textureManager = services.textures;
	textManager = services.text;
	window = services.window;

	isServicesInited = true;

	if (text = textManager->get(textResourceName); text != nullptr) {
		text->updateText(_text, color);
	}
	else {
		textManager->load(textResourceName, (SDL_Renderer*)window->getNativeHandle(), _text, color, fontPath);
		text = textManager->get(textResourceName);
	}

	if (backgroundName != "") { background = textureManager->get(backgroundName); }
	else { background = nullptr; }

	sizeMul = 1.0f;

	pos = Ant::Vec2f(0.0f, 0.0f);
	size = Ant::Vec2f(256.0f, 64.0f);
}

void Button::setFont(std::string font) {text->setFont(font);}

void Button::setText(std::string _text, SDL_Color _color) {text->updateText(_text, _color);}

void Button::setSizeMul(float mul) {sizeMul = mul;}

void Button::setSize(Ant::Vec2f _size) {size = _size;}

void Button::setBackground(std::string resourceName) {background = textureManager->get(resourceName);}

void Button::setPos(Ant::Vec2f _pos) {pos = _pos;}

void Button::render(int layer) {
	if (background != nullptr) {
		renderer->QueueTexture(background, pos, size*sizeMul, layer);
	}

	if (text != nullptr) {
		renderer->QueueText(text, pos, Ant::Vec2f(text->getWidth() * sizeMul/2.0f, text->getHeight() * sizeMul/2.0f), layer);
	}
}

void Button::setOnClick(ButtonCallback callback) { onClick = callback; }
void Button::setOnHover(ButtonCallback callback) { onHover = callback; }
void Button::setOnLeave(ButtonCallback callback) { onLeave = callback; }

void Button::updateState() {
	mxPrev = mx;
	myPrev = my;

	mx = inputService->getMouseX();
	my = inputService->getMouseY();

	//SDL_Log("Button center XY: %f %f, Mouse XY: %f %f", pos.x, pos.y, mx, my);

	if ((mx >= pos.x - (size.x * sizeMul) / 2 && mx <= pos.x + (size.x * sizeMul) / 2) &&
		(my >= pos.y - (size.y * sizeMul) / 2 && my <= pos.y + (size.y * sizeMul) / 2)) {
		if (onHover != nullptr) { onHover(); }

		if (inputService->isMousePressed(ANT_BUTTON_LEFT)) {
			if (onClick != nullptr) { onClick(); }
		}
	}
	else {
		if ((mxPrev >= pos.x - (size.x * sizeMul) / 2 && mxPrev <= pos.x + (size.x * sizeMul) / 2) &&
			(myPrev >= pos.y - (size.y * sizeMul) / 2 && myPrev <= pos.y + (size.y * sizeMul) / 2)) {
			if (onLeave != nullptr) { onLeave(); }
		}
	}
}