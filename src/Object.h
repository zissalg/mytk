#ifndef OBJECT_H
#define OBJECT_H

#include "Misc.h"
#include "Logger.h"
#include "Resource.h"

class Object {
protected:
	SDL_Rect  	  _rect;
	SDL_Color 	  _color;
	bool	  	  _mouseHovered;
	bool	  	  _mouseClicked;
	bool 		  _hidden;
	bool 		  _disabled;
	SDL_Renderer* _renderer;
protected:
	virtual void onMousePressed() {};
	virtual void onMouseHovered() {};
	virtual void onMouseLeft() {};
	virtual void onMouseReleased() {};
	virtual void onKeyPressed(SDL_Event* event)	{};
	virtual void onKeyReleased(SDL_Event* event) {};

	virtual bool checkHover(SDL_Event* event);
	virtual void mouseHoverEvent(SDL_Event* event);
	virtual void mousePressEvent();
	virtual void mouseReleaseEvent();

	virtual void _draw() {};
public:
	Object();
	Object(int x, int y, int w, int h);
	virtual ~Object();

	virtual void move(int range, double angle);
	void 		 handleEvent(SDL_Event* event);
	void 		 setX(int k);
	void 		 setY(int k);
	void 		 setW(int k);
	void 		 setH(int k);
	int  		 getX();
	int  		 getY();
	int  		 getW();
	int  		 getH();
	void 		 hide(bool hidden = true);
	void 		 disable(bool disabled = true);
	void 		 setRect(SDL_Rect r);
	void 		 setRect(int x, int y, int w, int h);
	SDL_Rect 	 getRect();
	void 		 setColor(std::string hex);
	void 		 setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
	virtual void setColor(SDL_Color color);
	SDL_Color 	 getColor();
	void 		 draw();
	virtual void update() = 0;
};

#endif // OBJECT_H
