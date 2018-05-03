#include "GamePlay.h"



GamePlay::GamePlay(sf::RenderWindow* window)
{
	this->mWindow = window;
	this->mPlayer = new Player(this->mWindow);
}


void GamePlay::update() {
	this->mPlayer->update();
}

void GamePlay::draw() {
	this->mPlayer->draw();

}
