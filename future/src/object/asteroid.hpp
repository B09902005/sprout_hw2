#ifndef _ASTEROID_HPP
#define _ASTEROID_HPP

#include "object.hpp"
#include <string>

class Asteroid : public Object{
	public:
		Asteroid(float _x, float _y, float _speedX, float _speedy, std::string path, int w, int h);
};

#endif