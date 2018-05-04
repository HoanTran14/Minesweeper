#include "Player.h"



Player::Player(sf::RenderWindow* window) {
	this->mWindow = window;
	


	this->mTextture.loadFromFile("Assets/drawable/main.png");

	this->mTextture.setSmooth(true);// khu rang cua
	this->mSprite.setTexture(this->mTextture);
	this->mSprite.setOrigin(this->mTextture.getSize().x / 2, this->mTextture.getSize().y / 2);
	this->mSprite.setPosition(40, 40);
}
void Player::update() {

	sf::Vector2f main_position = this->mSprite.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {


		main_position.y -= 10;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {


		main_position.y += 10;
	}

	if (main_position.y <= 40) {
		main_position.y = 40;
	}
	if (main_position.y >= 280) {
		main_position.y = 280;
	}
	this->mSprite.setPosition(main_position.x, main_position.y);

}

void Player::draw() {
	this->mWindow->draw(this->mSprite);
}
sf::Vector2f Player::getPostion() {
	return this->mSprite.getPosition();
}
