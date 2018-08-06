#include "Resource.h"

Resource* Resource::_instance = nullptr;

Resource::Resource() {
	LOG_DEBUG("Create new Resource " + ptr2Str(this));
}

Resource::~Resource() {
	for (auto t : _textures) {
		LOG_DEBUG("Delete Texture " + t.path + " " + ptr2Str(t.texture));
		SDL_DestroyTexture(t.texture);
	}

	LOG_DEBUG("Delete Resource " + ptr2Str(this));
}

/* * * * * * * * * * * *
 *      TEXTURES       *
 * * * * * * * * * * * */

 void Resource::addTexture(std::string path, SDL_Texture* texture) {
 	LOG_DEBUG("Add Texture " + path);

 	instance()->_textures.push_back({path, texture});
 }

SDL_Texture* Resource::loadTexture(std::string path) {
	if (path.length() == 0)
		path = PATH_UNKNOWN_PNG;

	LOG_DEBUG("Loading Texture from file " + path);

	if (_renderer == nullptr)
		LOG_WARN("Resource was not initialized!");

	SDL_Texture* texture = IMG_LoadTexture(_renderer, path.c_str());

	if (texture == nullptr) {
		LOG_ERROR("Could not load " + path);
		return searchTexture(PATH_UNKNOWN_PNG);
	}

	addTexture(path, texture);

	return texture;
}

SDL_Texture* Resource::searchTexture(std::string path) {
	LOG_DEBUG("Searching " + path);

	for (auto et : instance()->_textures) {
		if (et.path == path) {
			LOG_DEBUG("Texture found " + ptr2Str(et.texture));
			return et.texture;
		}
	}
	LOG_DEBUG("Texture " + path + " not found");

	return loadTexture(path);
}

// * * * * * * * * * * *
//  Renderer and Window
// * * * * * * * * * * *

void Resource::setWindow(SDL_Window* window) {
	_window = window;
}

void Resource::setRenderer(SDL_Renderer* renderer) {
	_renderer = renderer;
}

SDL_Renderer* Resource::getRenderer() {
	return _renderer;
}

SDL_Window* Resource::getWindow() {
	return _window;
}

// * * * * * * * * * * * * * * *
// * * * * STATIC MEMBERS  * * *
// * * * * * * * * * * * * * * *

Resource* Resource::instance() {
	if (_instance == nullptr)
		_instance = new Resource();

	return _instance;
}

void Resource::destroy() {
	delete _instance;
}
