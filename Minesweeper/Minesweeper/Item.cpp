#include "Item.h"

Item::Item(sf::RenderWindow* window) {
	this->mWindow = window;
	
}

void Item::update(){
	
}
void Item::draw() {
	this->mWindow->draw(this->mSprite);
}
sf::Vector2f Item::getPostion() {
	return this->mSprite.getPosition();
}

