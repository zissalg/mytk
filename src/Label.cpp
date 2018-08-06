#include "Label.h"

Label::Label(std::string text, int x, int y, int s)
	: Object(x, y, 0, 0)
	, _texture(nullptr)
	, _centered(true)
	, _renderer(Resource::instance()->getRenderer())
{
	LOG_DEBUG("Create new Label " + ptr2Str(this));
	setText(text);
	setSize(s);
}

Label::Label()
	: Label("", 0, 0, 0)
{}

Label::~Label() {
	LOG_DEBUG("Delete Label " + ptr2Str(this));
	SDL_DestroyTexture(_texture);
}

void Label::_draw() {
	SDL_Rect rect = getRect();
	if (_centered) {
		rect.x -= ((_size / 2) + rect.w) / 2;
		rect.y -= ((_size / 2) + rect.h) / 2;
	}

	SDL_RenderCopy(_renderer, _texture, NULL, &rect);
}

void Label::update() {
	LOG_DEBUG("Update Label " + ptr2Str(this));

	SDL_DestroyTexture(_texture);

	TTF_Font* font = TTF_OpenFont(PATH_FONT_DEFAULT, _size);

	SDL_Surface* surf = TTF_RenderText_Blended(font, _text.c_str(), _color);

	_texture = SDL_CreateTextureFromSurface(
		_renderer,
		surf
	);

	setW(surf->w);
	setH(surf->h);

	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
}

void Label::center(bool centered) {
	_centered = centered;
}

void Label::setText(std::string text) {
	_text = text;
	update();
}

void Label::setSize(int size) {
	_size = size;
	update();
}
