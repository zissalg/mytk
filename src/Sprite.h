#ifndef SPRITE_H
#define SPRITE_H

#include "Misc.h"
#include "Resource.h"
#include "Object.h"

class Sprite : public Object {
protected:
	SDL_Texture*  _texture;
	SDL_Rect	  _crop;
	Vector2I	  _imgSize;
	double		  _degree;

	SDL_Rect 	  _originRect;
	SDL_Rect 	  _originCrop;

	void 	 	  _draw();
public:
	Sprite();
	Sprite(std::string path, int x, int y, int w, int h);
	~Sprite();

	void 	 	update();
	void 	 	reset();
	void 	 	crop(int x, int y, int w, int h);
	void 	 	crop(SDL_Rect crop);
	void   	 	setDegree(double deg);
	double	 	getDegree();
	Vector2I 	getImgSize();
};

#endif
