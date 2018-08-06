#pragma once

#include "Object.h"
#include "Sprite.h"
#include "Path.h"

class Box : public Object {
private:
    static uint     _maxParts;
    static SDL_Rect _croppedParts[9];
    static int      _switchSignX[4];
    static int      _switchSignY[4];
    static int      _switchSignW[4];
    static int      _switchSignH[4];
    Sprite**        _sprites;
protected:
    virtual void onMousePressed();
	virtual void onMouseHovered();
	virtual void onMouseLeft();
	virtual void onMouseReleased();
	virtual void onKeyPressed(SDL_Event* event);
	virtual void onKeyReleased(SDL_Event* event);

    void _draw();
public:
    Box();
    Box(int x, int y, int w, int h);
    Box(const Box& box);
    virtual ~Box();

    void update();
    void setColor(SDL_Color color);
};
