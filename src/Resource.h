#ifndef RESOURCES_H
#define RESOURCES_H

#include "Misc.h"
#include "Logger.h"
#include "Path.h"

#define SearchTexture(path) Resource::instance()->searchTexture(path)

struct ExTexture {
	std::string	 path;
	SDL_Texture* texture;
};

class Resource {
private:

	static Resource*     _instance;
	SDL_Renderer* 		 _renderer;
	SDL_Window* 	 	 _window;
	std::list<ExTexture> _textures;
private:
	Resource();
	~Resource();
public:
	// Texture
	SDL_Texture*	 loadTexture(std::string path);
	void			 addTexture(std::string path, SDL_Texture* texture);
	SDL_Texture*	 searchTexture(std::string path);

	// Window and Renderer
	void 			 setRenderer(SDL_Renderer* renderer);
	void 			 setWindow(SDL_Window* window);
	SDL_Renderer*	 getRenderer();
	SDL_Window* 	 getWindow();

	void  		 	 destroy();

	// Static members
	static Resource* instance();
};

#endif
