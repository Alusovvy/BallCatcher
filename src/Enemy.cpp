#include "Enemy.h"
#include <iostream>

Enemy::Enemy(sf::CircleShape& enemy, int speed)
	: Entity(enemy, EntityType::enemyType), m_Speed(speed)
{
}
Enemy::~Enemy()
{
}
sf::CircleShape& Enemy::getEnemy()
{
	return Entity::getShape();
}

int Enemy::getSpeed() const
{
	return m_Speed;
}

void Enemy::setSpeed(int speed)
{
	m_Speed = speed;
}

EntityType Enemy::getType() const
{
	return Entity::getType();
}

void Enemy::handleCollision(EntityType type) {
	if (type == EntityType::playerType) {
		relocate();
	}
}

void Enemy::relocate()
{
	std::cout << "Relocating..." << std::endl;
}

void Enemy::moveInPlayerDirection(sf::CircleShape& enemy, sf::CircleShape playerPosition) {
	int speed = rand() % 3;

	if (playerPosition.getPosition().x < enemy.getPosition().x) {
		enemy.setPosition(enemy.getPosition().x - 0.5f * speed, enemy.getPosition().y);
	}
	else {
		enemy.setPosition(enemy.getPosition().x + 0.5f * speed, enemy.getPosition().y);
	}

	if (playerPosition.getPosition().y < enemy.getPosition().y) {
		enemy.setPosition(enemy.getPosition().x, enemy.getPosition().y - 0.5f * speed);
	}
	else {
		enemy.setPosition(enemy.getPosition().x, enemy.getPosition().y + 0.5f * speed);
	}
}
