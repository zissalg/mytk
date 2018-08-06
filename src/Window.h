#pragma once

#include "Object.h"
#include "Sprite.h"


class Window {
private:
	SDL_Renderer* 		_renderer;
	SDL_Window* 		_window;
	Resource* 			_resource;
	std::list<Object*> 	_lObjects;
	int 				_delay;
	bool				_running;
	unsigned 			_startTicks;
	unsigned			_runTicks;
	void update();
	void handle();
	void begin();
	void end();
public:
	Window();
	Window(std::string title, int x, int y, int w, int h);
	~Window();
	void  	run();
	Object* addObject(Object*);
	void 	removeObject(Object*);
};
