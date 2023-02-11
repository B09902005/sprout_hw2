#include <iostream>
#include <list>
#include <cstdlib>
#include "model.hpp"
#include "../object/object.hpp"
#include "../object/player.hpp"
#include "../object/bullet.hpp"
#include "../object/asteroid.hpp"
#include "../object/potion.hpp"
#include <allegro5/allegro.h>

void Model::initial(){
    return;
}

int *Model::update_ans(std::list<Object*> object_list, int board[], Player *player){
    // To check if player is an opponent.
    /*
    bool opponent = false;
    for (auto it = object_list.begin() ; it != object_list.end() ; it ++){
        if (dynamic_cast <Player*> (*it)){
            if (player == dynamic_cast<Player*> (*it)){
                if (player->y <= height / 2 - 3 ) opponent = true;
                if (player->y >= height / 2) opponent = false;
            }
        }
    }
     */
    /*
    if (opponent == false){
    for (int i=0 ; i<ALLEGRO_KEY_MAX ; i++){
        int temp = 1;
        if (opponent) temp = 10;
        if (rand()%temp == 0) board[i] = 1;
        else board[i] = 0;
    }
        return board;
    }
     */
    // init
    for (int i=0 ; i<ALLEGRO_KEY_MAX ; i++) board[i] = 0;
    //bool safe[5] = {true, true, true, true, true};
    
    for (auto it = object_list.begin() ; it != object_list.end() ; it ++){
        // if an opponent is in the front, then attack.
        if (dynamic_cast <Player*> (*it)){
            auto py = dynamic_cast<Player*> (*it);
            if (player == py) continue;
            if ((player->y - height / 2) * (py->y >= height / 2) < 0 && abs(player->x - py->x) <= 1) board[ALLEGRO_KEY_SPACE] = 1;
        }
        
        // if a bullet is dangerous, then dodge.
        if (dynamic_cast <Bullet*> (*it)){
            auto bu = dynamic_cast<Bullet*> (*it);
            if ((player->y - bu->y)*(bu->speedY) > 0 && abs(player->y - bu->y) <= 3){
                if (player->x <= bu->x && player->x >= bu->x-3) board[ALLEGRO_KEY_A] = 1;
                if (player->x >= bu->x && player->x <= bu->x+3) board[ALLEGRO_KEY_D] = 1;
            }
            //if (player->x-1 == bu->x) safe[1] = false;
            //if (player->x+3 == bu->x) safe[2] = false;
        }
        
        // if an asteroid is dangerous, then dodge.
        if (dynamic_cast <Asteroid*> (*it)){
            auto as = dynamic_cast<Asteroid*> (*it);
            if ((player->y - as->y)*(as->speedY) > 0 && abs(player->y+1 - as->y) <= 2){
                if (player->x+1 <= as->x && player->x+2 >= as->x) board[ALLEGRO_KEY_A] = 1;
                if (player->x+1 > as->x && player->x <= as->x) board[ALLEGRO_KEY_D] = 1;
                if (player->x+1 == as->x) board[ALLEGRO_KEY_SPACE] = 1;
                //if (player->x-1 == as->x && abs(player->y+1 - as->y) <= 2) safe[1] = false;
                //if (player->x+3 == as->x && abs(player->y+1 - as->y) <= 2) safe[2] = false;
            }if ((player->x - as->x)*(as->speedX) > 0 && abs(player->x+1 - as->x) <= 2){
                if (player->y+1 <= as->y && player->y+2 >= as->y) board[ALLEGRO_KEY_W] = 1;
                if (player->y+1 > as->y && player->y <= as->y) board[ALLEGRO_KEY_S] = 1;
                //if (player->y-1 == as->y && abs(player->x+1 - as->x) <= 2) safe[3] = false;
                //if (player->y+3 == as->y && abs(player->x+1 - as->x) <= 2) safe[4] = false;
            }
        }
    }
    /*
    if (board[ALLEGRO_KEY_W] == 0 && board[ALLEGRO_KEY_S] == 0){
        int temp = rand()%5;
        if (temp == 0 && safe[3]) board[ALLEGRO_KEY_W] = 1;
        if (temp == 1 && safe[4]) board[ALLEGRO_KEY_S] = 1;
    }
    if (board[ALLEGRO_KEY_A] == 0 && board[ALLEGRO_KEY_D] == 0){
        int temp = rand()%5;
        if (temp == 0 && safe[1]) board[ALLEGRO_KEY_A] = 1;
        if (temp == 1 && safe[2]) board[ALLEGRO_KEY_D] = 1;
    }
    if (rand()%20 == 0) board[ALLEGRO_KEY_SPACE] = 1;
     */
    if (rand()%20 == 0) board[ALLEGRO_KEY_SPACE] = 1;
    return board;
}

int *Model::update(std::list<Object*> object_list, int board[], Player *player){
    // To check if player is an opponent.
    bool opponent = false;
    for (auto it = object_list.begin() ; it != object_list.end() ; it ++){
        if (dynamic_cast <Player*> (*it)){
            if (player == dynamic_cast<Player*> (*it)){
                if (player->y <= height / 2 - 3 ) opponent = true;
                if (player->y >= height / 2) opponent = false;
            }
        }
    }
    /*
    if (opponent == false){
    for (int i=0 ; i<ALLEGRO_KEY_MAX ; i++){
        int temp = 1;
        if (opponent) temp = 10;
        if (rand()%temp == 0) board[i] = 1;
        else board[i] = 0;
    }
        return board;
    }
     */
    // init
    for (int i=0 ; i<ALLEGRO_KEY_MAX ; i++) board[i] = 0;
    int distance;
    
    for (auto it = object_list.begin() ; it != object_list.end() ; it ++){
        // if an opponent is in the front, then attack.
        if (dynamic_cast <Player*> (*it)){
            auto py = dynamic_cast<Player*> (*it);
            if (player == py) continue;
            if ((player->y - height / 2) * (py->y >= height / 2) < 0 && abs(player->x - py->x) <= 1) board[ALLEGRO_KEY_SPACE] = 1;
            distance = player->x - py->x;
        }
        
        // if a bullet is dangerous, then dodge.
        if (dynamic_cast <Bullet*> (*it)){
            auto bu = dynamic_cast<Bullet*> (*it);
            if ((player->y - bu->y)*(bu->speedY) > 0 && abs(player->y - bu->y) <= 3){
                if (player->x <= bu->x && player->x >= bu->x-3) board[ALLEGRO_KEY_A] = 1;
                if (player->x >= bu->x && player->x <= bu->x+3) board[ALLEGRO_KEY_D] = 1;
            }
        }
        
        // if an asteroid is dangerous, then dodge.
        if (dynamic_cast <Asteroid*> (*it)){
            auto as = dynamic_cast<Asteroid*> (*it);
            if ((player->y - as->y)*(as->speedY) > 0 && abs(player->y+1 - as->y) <= 2){
                if (player->x+1 <= as->x && player->x+2 >= as->x) board[ALLEGRO_KEY_A] = 1;
                if (player->x+1 > as->x && player->x <= as->x) board[ALLEGRO_KEY_D] = 1;
                if (player->x+1 == as->x) board[ALLEGRO_KEY_SPACE] = 1;
            }if ((player->x - as->x)*(as->speedX) > 0 && abs(player->x+1 - as->x) <= 2){
                if (player->y+1 <= as->y && player->y+2 >= as->y) board[ALLEGRO_KEY_W] = 1;
                if (player->y+1 > as->y && player->y <= as->y) board[ALLEGRO_KEY_S] = 1;
            }
        }
    }
    // I want to keep the airplanes moving.
    if (board[ALLEGRO_KEY_W] == 0 && board[ALLEGRO_KEY_S] == 0){
        int temp = rand()%5;
        if (temp == 0) board[ALLEGRO_KEY_W] = 1;
        if (temp == 1) board[ALLEGRO_KEY_S] = 1;
    }
    if (board[ALLEGRO_KEY_A] == 0 && board[ALLEGRO_KEY_D] == 0){
        int temp = rand()%20;
        if (temp%5 == 0) board[ALLEGRO_KEY_A] = 1;
        if (temp%5 == 1) board[ALLEGRO_KEY_D] = 1;
        if (temp == 2 && distance < 0) board[ALLEGRO_KEY_D] = 1;
        if (temp == 2 && distance > 0) board[ALLEGRO_KEY_A] = 1;
    }
    // I want to keep the airplanes shooting.
    if (rand()%5 == 0) board[ALLEGRO_KEY_SPACE] = 1;
    
    return board;
}

