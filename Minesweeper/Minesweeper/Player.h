#ifndef _Player_H_
#define _Player_H_
#include <SFML/Graphics.hpp>
#include <iostream>

#pragma once
class Player
{
	private:sf::RenderWindow* mWindow;
			sf::Texture mTextture;
			sf::Sprite mSprite;



	public:Player(sf::RenderWindow* window);
	 void update();
	 void draw();
	 sf::Vector2f getPostion();


};
#endif
