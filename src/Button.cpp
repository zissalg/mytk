#include "Button.h"

Button::Button(std::string text, int x, int y, int w, int h)
	: Object(x, y, w, h)
	, _box(new Box(x, y, w, h))
	, _label(new Label(text, x, y, 16))
{
	LOG_INFO("Create new Button " + ptr2Str(this));

	onMouseLeft();
}

Button::~Button() {
	LOG_INFO("Delete Button " + ptr2Str(this));

	delete _box;
	delete _label;
}

void Button::_draw() {
	_box->draw();
	_label->draw();
}

void Button::update() {}

void Button::onMousePressed() {
	_label->setColor(255, 255, 255);
}

void Button::onMouseHovered() {
	_label->setColor(150, 180, 255);
}

void Button::onMouseLeft() {
	_label->setColor(70, 150, 255);
}

void Button::onMouseReleased() {
	onMouseHovered();
}

void Button::onKeyPressed(SDL_Event* event) {}

void Button::onKeyReleased(SDL_Event* event) {}
