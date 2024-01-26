#include "Player.h"
#include <iostream>
Player::Player(sf::CircleShape player, float playerSpeed = 6.0f)
	: Entity(player, EntityType::playerType), speed(playerSpeed)
{
}

Player::~Player()
{
}

sf::CircleShape* Player::move(Vector2D vec, int wWidth, int wHeight)
{
	sf::CircleShape& m_Player = Entity::getShape();

	std::cout << vec.x << " " << vec.y << std::endl;
	std::cout << "\n" << std::endl;
	if ((m_Player.getPosition().x + m_Player.getRadius() * 2 > wWidth && vec.x > 0.0f) || (m_Player.getPosition().x < 0 && vec.x < 0.0f)) {
		return &m_Player;
	}
	else if ((m_Player.getPosition().y + m_Player.getRadius() * 2 > wHeight && vec.y > 0.0f) || (m_Player.getPosition().y < 0 && vec.y < 0.0f)) {
		return &m_Player;
	}
	m_Player.setPosition(m_Player.getPosition().x + vec.x, m_Player.getPosition().y + vec.y);

	std::cout << m_Player.getPosition().x << " " << m_Player.getPosition().y << std::endl;

	return &m_Player;
}

sf::CircleShape& Player::getPlayer()
{
	return Entity::getShape();
}

int Player::getScore()
{
	return score;
}

float Player::getSpeed() {
	return speed;
}

void Player::handleCollision(EntityType type)
{
	switch (type) {
	case EntityType::enemyType:
		changeScore(-1);
		break;
	case EntityType::pointType:
		changeScore(+1);
		break;
	default:
		break;
	}

	std::cout << "Player score: " << score << std::endl;
}

void Player::changeScore(int i)
{
	//increase player speed if he collected a point
	if (i > 0) {
		speed += 0.25f;
	}
	score += i;
}

