
#ifndef _Node_H_
#define _Node_H_
#pragma once
#include <SFML\Graphics.hpp>
#include <SFML/Graphics.hpp>


#include <iostream>
class Node
{
public:
	sf::Sprite FirstLayer;   
	sf::Sprite LastLayer;    
	int kinds;           //-1
	float x;
	float y;
	bool lat;          
	bool flag;          
	Node()
	{
		lat = false;
		flag = false;
	}
	void setData(sf::Texture &texture);
};

#endif