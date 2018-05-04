
#ifndef _Game_H_
#define _Game_H_
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Node.h"
#include <list>
#include <string>
using namespace std;
class GamePlay
{
	
	
		private: sf::RenderWindow*   mWindow;
				 sf::Texture Node9, Node0, Node1, Node2, Node3, Node4, Node5, Node6, Node7, Node8, simle, Flag, Mine;
				 const string PathImage = "Assets/drawable/";
				 sf::Sprite Simle;
				 Node node[12][8];
		public: GamePlay(sf::RenderWindow* window);
				
		void  update();
		void draw();
		

		void start();

	
};

#endif// _Game_H_