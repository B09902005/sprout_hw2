#ifndef _MAINGAME_HPP
#define _MAINGAME_HPP


#include <list>
#include "../object/object.hpp"
#include "scene.hpp"
#include "../object/player.hpp"

class MainGame : public Scene{
	private:
		std::list<Object*> object_list;
		Player *P1, *P2;
	public:
		MainGame();
		~MainGame();
		ALLEGRO_FONT *font;
		ALLEGRO_BITMAP *asteroid_img;
		ALLEGRO_BITMAP *bullet_img;
		void draw(void) override;
		void destroy(void) override;
		void update(void) override;
		void initial(void);
};

#endif