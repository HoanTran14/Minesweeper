
#ifndef _Node_H_
#define _Node_H_
#pragma once
#include <SFML\Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
class Node
{
public:
	sf::Sprite FirstLayer;   // Lớp trên cùng
	sf::Sprite LastLayer;    // Lớp cuối cùng (lớp dưới)
	int kinds;           // Xác định có phải là boom hay không
						 // -1 là boom
	float x;
	float y;
	bool lat;            // true là đã lật
	bool flag;           // true là đã cắm
	Node()
	{
		lat = false;
		flag = false;
	}
	void setData(sf::Texture &texture);
};

#endif