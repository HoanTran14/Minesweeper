#include "Player.h"



Player::Player(sf::RenderWindow* window) {
	this->mWindow = window;
	


	this->mTextture.loadFromFile("Assets/drawable/1.png");

	this->mTextture.setSmooth(true);// khu rang cua
	this->mSprite.setTexture(this->mTextture);
	this->mSprite.setOrigin(this->mTextture.getSize().x / 2, this->mTextture.getSize().y / 2);
}
void Player::update() {
	sf::Vector2i mouse_pos = sf::Mouse::getPosition(*this->mWindow);
	if (mouse_pos.x <= 0) {
		mouse_pos.x = 0;
	}
	if (mouse_pos.y <= 0) {
		mouse_pos.y = 0;
	}
	if (mouse_pos.x > 800) {
		mouse_pos.x = 800;
	}
	if (mouse_pos.y > 600) {
		mouse_pos.y = 600;
	}


	this->mSprite.setPosition(mouse_pos.x, mouse_pos.y);


}

void Player::draw() {
	this->mWindow->draw(this->mSprite);
}

