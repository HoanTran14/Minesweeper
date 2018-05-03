#include <SFML/Graphics.hpp>
#include <iostream>
#include "GamePlay.h"
using namespace std;


int main()
{
	bool checkwindowselected = true;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper!",sf::Style::Close);
	window.setFramerateLimit(60);//FPS
	GamePlay game(&window);


	


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)     window.close();


			if (event.type==sf::Event::LostFocus)    checkwindowselected = false;
			if (event.type == sf::Event::GainedFocus)    checkwindowselected = true;
			
		}
		if (checkwindowselected) {
			window.setMouseCursorVisible(false);//invisiable mouse
			window.clear();
			game.update();
			game.draw();
			
		}
		else {
			window.setMouseCursorVisible(true);
		}
		window.display();
	return 0;
}