
#ifndef _Game_H_
#define _Game_H_
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Item.h"
#include <list>
class GamePlay
{
		private: sf::RenderWindow*   mWindow;
				 Player* mPlayer;
				 std::list<Item> mItem;
		public: GamePlay(sf::RenderWindow* window);
				Player* mPlayer;
		void  update();
		void draw();

	
};

#endif// _Game_H_