
#ifndef _Item_H_
#define _Item_H_
#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once
class Item
{


private:sf::RenderWindow* mWindow;
		sf::Texture mTextture;
		sf::Sprite mSprite;



public:
	Item(sf::RenderWindow* window);
	   void update();
	   void draw();
	   sf::Vector2f getPostion();
};

#endif//_Item_H_