#include "Window.h"

Window::Window()
	: Window("Unknown", 100, 100, 800, 600)
{}

Window::Window(std::string title, int x, int y, int w, int h)
	: _renderer(nullptr)
	, _window(nullptr)
	, _delay(1000 / 120)
	, _running(true)
{
	LOG_DEBUG("Create new Window " + ptr2Str(this));

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	IMG_Init(IMG_INIT_PNG);

	_window = SDL_CreateWindow(title.c_str(), x, y, w, h, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	_resource = Resource::instance();
	_resource->setWindow(_window);
	_resource->setRenderer(_renderer);
}

Window::~Window() {
	for (auto obj : _lObjects)
		delete obj;

	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);

	IMG_Quit();
	TTF_Quit();
	SDL_Quit();

	LOG_DEBUG("Delete Window " + ptr2Str(this));
}

Object* Window::addObject(Object* obj) {
	_lObjects.push_back(obj);
	return obj;
}

void Window::removeObject(Object* obj) {
	_lObjects.remove(obj);
	delete obj;
}

void Window::run() {
	LOG_DEBUG("Loop window");

	while (_running) {
		handle();
		begin();
		update();
		end();
	}
}

void Window::update() {
	//LOG_DEBUG("Update");
	for (auto obj : _lObjects)
		obj->draw();
}

void Window::begin() {
	_startTicks = SDL_GetTicks();

	SDL_RenderClear(_renderer);
}

void Window::end() {
	SDL_RenderPresent(_renderer);

	_runTicks = SDL_GetTicks() - _startTicks;
	if (_runTicks >= _delay)
		return;

	SDL_Delay(_delay - _runTicks);
}

void Window::handle() {
	SDL_Event event;

	while(SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			_running = false;
			return;
		}

		for (auto obj : _lObjects)
			obj->handleEvent(&event);
	}
}
