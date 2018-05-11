
#ifndef _Game_H_
#define _Game_H_
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Node.h"
#include <list>
#include <string>
#include <SFML/Window.hpp>
#include "Common_f.h"
using namespace std;
using namespace  sf;

class GamePlay
{
	
	
		private: sf::RenderWindow*   mWindow;
				 sf::Texture Node9, Node0, Node1, Node2, Node3, Node4, Node5, Node6, Node7, Node8,  Flag, Mine,Win;
				 const string PathImage = "Assets/drawable/";
				 static const int m = N;
				 static const int n = M;
				 bool start;
				 int countBoom;
				 int countLat;
				 Node node[m+2][n+2];
				 bool keyUp;
		public: GamePlay(sf::RenderWindow* window);
				
		void  update();
		void draw();
		
		void stop();
		void win();
		void setup();

	
};

#endif// _Game_H_