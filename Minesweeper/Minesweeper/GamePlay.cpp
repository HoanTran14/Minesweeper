#include "GamePlay.h"



GamePlay::GamePlay(sf::RenderWindow* window)
{
	this->mWindow = window;
	this->mPlayer = new Player(this->mWindow);
}


void GamePlay::update() {
	this->mPlayer->update();
	if (this->mItem.size() > 0) {
		for (std::list<Item>::iterator it = this->mItem.begin(); it != this->mItem.end();it++) {
			it->update();
		}
	}
}

void GamePlay::draw() {
	this->mPlayer->draw();
	if (this->mItem.size() > 0) {
		for (std::list<Item>::iterator it = this->mItem.begin(); it != this->mItem.end(); it++) {
			it->draw();
		}
	}
}
