#pragma once

#include "Object.h"

class Label : public Object {
private:
	SDL_Texture*  _texture;
	SDL_Renderer* _renderer;
	bool 		  _centered;
	std::string   _text;
	int 		  _size;

	void 		  _draw();
public:
	Label();
	Label(std::string text, int x, int y, int s);
	~Label();

	void center(bool centered = true);
	void update();
	void setText(std::string text);
	void setSize(int size);
};
