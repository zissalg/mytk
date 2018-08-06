#include "Logger.h"
#include "Window.h"
#include "Label.h"
#include "Box.h"
#include "Button.h"

int main() {
	Window *window = new Window("Test", 100, 100, 800, 600);
	window->addObject(new Sprite("assets/background.png", 0, 0, 1920, 1080));
	window->addObject(new Label("WHAT THE FUCK", 0, 100, 20));
	window->addObject(new Button("WTF", 100, 200, 200, 42));
	window->run();
	delete window;

	Resource::instance()->destroy();
	Logger::close();
	return 0;
}
