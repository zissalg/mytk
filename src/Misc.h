#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include <list>
#include <random>
#include <cmath>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

struct Vector2I {
	int x;
	int y;
	Vector2I(int xx, int yy) : x(xx), y(yy) {}
};

int randomInt(int from, int to);
int hex2Dec(std::string hex);

template <class T>
std::string any2Str(T o) {
	return std::to_string(o);
}

// Convert pointer to string
// @param: T is pointer type T (Object or Premitive Type pointer)
// @output: return a std::string
template <class T>
std::string	ptr2Str(T* o) {
	std::stringstream ss;
	ss << o;
	return ss.str();
}
