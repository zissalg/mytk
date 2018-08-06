#pragma once

#include "Box.h"
#include "Label.h"

class Button : public Object {
private:
	Box* 	_box;
	Label* 	_label;
	void 	_draw();
protected:
	virtual void onMousePressed();
	virtual void onMouseHovered();
	virtual void onMouseLeft();
	virtual void onMouseReleased();
	virtual void onKeyPressed(SDL_Event* event);
	virtual void onKeyReleased(SDL_Event* event);
public:
	Button(std::string text, int x, int y, int w, int h);
	~Button();

	void update();
};
