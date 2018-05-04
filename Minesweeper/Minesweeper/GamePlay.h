
#ifndef _Game_H_
#define _Game_H_
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Node.h"
#include <list>
#include <string>
using namespace std;
using namespace  sf;

class GamePlay
{
	
	
		private: sf::RenderWindow*   mWindow;
				 sf::Texture Node9, Node0, Node1, Node2, Node3, Node4, Node5, Node6, Node7, Node8,  Flag, Mine;
				 const string PathImage = "Assets/drawable/";
				 static const int m = 10;
				 static const int n = 6;
				 Node node[m+2][n+2];
		public: GamePlay(sf::RenderWindow* window);
				
		void  update();
		void draw();
		

		void setup();

	
};

#endif// _Game_H_