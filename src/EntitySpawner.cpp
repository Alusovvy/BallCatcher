#include "EntitySpawner.h"

EntitySpawner::EntitySpawner()
	: m_circleVector(), enemyCount(0)
{
}

EntitySpawner::~EntitySpawner()
{

}
void EntitySpawner::spawnEntities(sf::CircleShape* shape, int ammount, EntityType type) {

	if (type == EntityType::enemyType) {
		shape->setFillColor(sf::Color::Red);
		enemyCount += ammount;
	}
	else if (type == EntityType::pointType) {
		shape->setFillColor(sf::Color::Green);
		shape->setPosition(calcPostionForRespawn().x, calcPostionForRespawn().y);
	}
	else {
		shape->setFillColor(sf::Color::Yellow);	// set the circle color to green
		shape->setPosition(calcPostionForRespawn().x, calcPostionForRespawn().y);// set the top-left position of the cricle
	}

	for (int i = 0; i < ammount; i++) {
		if (type == EntityType::enemyType) {
			shape->setPosition(rand() % 1000, rand() % 600);
			while (!checkIfSpaceEmpty(*shape)) {
				shape->setPosition(rand() % 1000, rand() % 600);
			}
		}
		m_circleVector.push_back(shape);
	}
}

bool EntitySpawner::checkIfSpaceEmpty(sf::CircleShape& shape)
{
	for (int i = 0; i < m_circleVector.size(); i++) {
		if (m_circleVector[i]->getGlobalBounds() == shape.getGlobalBounds() &&  m_circleVector[i] != &shape) {
			return false;
		}
	}

	return true;
}

Vector2D EntitySpawner::calcPostionForRespawn() {
	Vector2D vector = Vector2D(0, 0);

	vector.x = rand() % 1000;
	vector.y = rand() % 600;

	return vector;
}

std::vector<sf::CircleShape*> EntitySpawner::getCircleVector() const
{
	return m_circleVector;
}

std::vector<sf::CircleShape*>* EntitySpawner::getCircleVectorPointer()
{
	return &m_circleVector;
}

unsigned int EntitySpawner::getEnemyCount() const
{
	return enemyCount;
}
