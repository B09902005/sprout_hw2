#ifndef _MODEL_HPP
#define _MODEL_HPP

#include <iostream>
#include <list>
#include "model.hpp"
#include "../object/object.hpp"
#include "../object/player.hpp"
#include "../object/bullet.hpp"
#include "../object/asteroid.hpp"
#include "../object/potion.hpp"

extern const int width;
extern const int height;


class Model{
	public:
		// called by game start
		virtual void initial();
		// called by every update time
		// GameMap is current game status
		// return integer array is as same as the key_state array
		virtual int *update(std::list<Object*> object_list, int board[], Player *player);
        virtual int *update_ans(std::list<Object*> object_list, int board[], Player *player);
};

#endif
