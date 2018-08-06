#include "Sprite.h"

Sprite::Sprite(std::string path, int x, int y, int w, int h)
	: Object(x, y, w, h)
	, _texture(SearchTexture(path))
	, _crop({0, 0, 0, 0})
	, _imgSize(0, 0)
	, _degree(0)
{
	LOG_DEBUG("Create new Sprite " + ptr2Str(this));

	SDL_QueryTexture(_texture , NULL, NULL, &_imgSize.x, &_imgSize.y);

	_crop.w = _imgSize.x;
	_crop.h = _imgSize.y;

	_originCrop = _crop;
	_originRect = _rect;
}

Sprite::Sprite()
	: Sprite("", 0, 0, 0, 0) {

}

Sprite::~Sprite() {
	LOG_DEBUG("Delete Sprite " + ptr2Str(this));
	_texture = nullptr;
}

void Sprite::_draw() {
	SDL_SetTextureColorMod(_texture, _color.r, _color.g, _color.b);
	SDL_SetTextureAlphaMod(_texture, _color.a);
	SDL_SetTextureBlendMode(_texture, SDL_BLENDMODE_BLEND);
	SDL_RenderCopyEx(_renderer, _texture,
		&_crop, &_rect,
		_degree, NULL,
		SDL_FLIP_NONE);
}

void Sprite::reset() {
	crop(_originCrop);
	setRect(_originRect);
	setColor(255, 255, 255, 255);
}

void Sprite::update() {

}

void Sprite::crop(int x, int y, int w, int h) {	_crop = {x, y, w, h}; }

void Sprite::crop(SDL_Rect crop) { _crop = crop; }

Vector2I Sprite::getImgSize() { return _imgSize; }

void Sprite::setDegree(double deg) { _degree = deg; }

double Sprite::getDegree() { return _degree; }
