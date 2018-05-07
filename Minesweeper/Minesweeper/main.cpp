#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include "GamePlay.h"
using namespace std;

const string PathImage = "Assets/drawable/";

void Menu(sf::RenderWindow &window);
int main()
{
	bool checkwindowselected = true;
	sf::RenderWindow window(sf::VideoMode(400, 340), "Minesweeper!",sf::Style::Close);
	window.setFramerateLimit(30);//FPS
	srand(time(NULL));
	
	Menu(window);
	return 0;
}

void Menu(sf::RenderWindow &window)
{
	sf::Texture background, play,  exit;

	background.loadFromFile(PathImage + "Backgrounds/Menu_Background.png");
	play.loadFromFile(PathImage + "Backgrounds/Play.png");
	exit.loadFromFile(PathImage + "Backgrounds/Exit.png");

	sf::Sprite Background(background), Play(play), Exit(exit);

	Play.setOrigin(50, 20);
	
	Exit.setOrigin(50, 20);

	Play.setPosition(200, 130);
	Exit.setPosition(200, 180);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}
		window.clear();
		window.draw(Background);
		window.draw(Play);
		window.draw(Exit);
		window.display();

		if (sf::Mouse::getPosition(window).x >= 150 && sf::Mouse::getPosition(window).x <= 250 && sf::Mouse::getPosition(window).y >= 110 && sf::Mouse::getPosition(window).y <= 150)
		{
			Play.setColor(sf::Color::Green);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) GamePlay game(&window);;
		}
		else Play.setColor(sf::Color::Red);

		if (sf::Mouse::getPosition(window).x >= 150 && sf::Mouse::getPosition(window).x <= 250 && sf::Mouse::getPosition(window).y >= 160 && sf::Mouse::getPosition(window).y <= 210)
		{
			Exit.setColor(sf::Color::Green);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) return;
		}
		else Exit.setColor(sf::Color::Red);

		
	}
}
