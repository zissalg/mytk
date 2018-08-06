#include "Object.h"

Object::Object(int x, int y, int w, int h)
	: _rect({x, y, w, h})
	, _color({255, 255, 255, 255})
	, _hidden(false)
	, _disabled(false)
	, _mouseHovered(false)
	, _mouseClicked(false)
	, _renderer(Resource::instance()->getRenderer())
{
	LOG_DEBUG("Create new Object " + ptr2Str(this));
}

Object::Object()
	: Object(0, 0, 0, 0)
{

}

Object::~Object() {
	LOG_DEBUG("Delete Object " + ptr2Str(this));
}

void Object::draw() {
	if (_hidden) return;

	_draw();
}

bool Object::checkHover(SDL_Event* event) {
	int iX = _rect.x - (_rect.w / 2);
	int iY = _rect.y - (_rect.h / 2);
	return	event->button.x > iX &&
			event->button.y > iY &&
			event->button.x < iX + _rect.w &&
			event->button.y < iY + _rect.h;
}

void Object::handleEvent(SDL_Event* event) {
	if (_disabled) return;

	switch (event->type) {
		case SDL_KEYDOWN: onKeyPressed(event); break;
		case SDL_KEYUP: onKeyReleased(event); break;
		case SDL_MOUSEBUTTONDOWN: mousePressEvent(); break;
		case SDL_MOUSEBUTTONUP: mouseReleaseEvent(); break;
		case SDL_MOUSEMOTION: mouseHoverEvent(event); break;
	}
}

void Object::mouseHoverEvent(SDL_Event* event) {
	if (!_mouseHovered) {
		if (checkHover(event)) {
			_mouseHovered = true;
			onMouseHovered();
		}
	} else {
		if (!checkHover(event)) {
			_mouseHovered = false;
			onMouseLeft();
		}
	}
}

void Object::mousePressEvent() {
	if (_mouseHovered) {
		_mouseClicked = true;
		onMousePressed();
	}
}

void Object::mouseReleaseEvent() {
	if (_mouseHovered && _mouseClicked) {
		onMouseReleased();
	}
}

// @FIXME: wrong converting method
void Object::setColor(std::string hexColor) {
	if (hexColor.length() != 7 && hexColor.length() != 9) return;
	if (hexColor[0] != '#') return;

	Uint8 red = hex2Dec(hexColor.substr(1, 2));
	Uint8 green = hex2Dec(hexColor.substr(3, 2));
	Uint8 blue = hex2Dec(hexColor.substr(5, 2));
	Uint8 alpha = 255;

	if (hexColor.length() == 9)
		alpha = hex2Dec(hexColor.substr(7, 2));

	setColor(red, green, blue, alpha);
}

void Object::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
	SDL_Color color = {r, g, b, a};
	setColor(color);
}

void Object::setColor(SDL_Color color) {
	_color = color;
	update();
}

SDL_Color Object::getColor() {
	return _color;
}

void Object::setX(int k) {
	_rect.x = k;
	//update();
}

void Object::setY(int k) {
	_rect.y = k;
	//update();
}

void Object::setW(int k) {
	_rect.w = k;
	//update();
}

void Object::setH(int k) {
	_rect.h = k;
	//update();
}

int Object::getX() {
	return _rect.x;
}

int Object::getY() {
	return _rect.y;
}

int Object::getW() {
	return _rect.w;
}

int Object::getH() {
	return _rect.h;
}

void Object::setRect(int x, int y, int w, int h) {
	_rect = {x, y, w, h};
}

void Object::setRect(SDL_Rect r) {
	_rect = r;
}

SDL_Rect Object::getRect() {
	return _rect;
}

void Object::move(int range, double angle) {
	//Polar projection
	_rect.x += range * cos(angle);
	_rect.y += range * sin(angle);
}

void Object::hide(bool hidden) {
	_hidden = hidden;
}
void Object::disable(bool disabled) {
	_disabled = disabled;
}
