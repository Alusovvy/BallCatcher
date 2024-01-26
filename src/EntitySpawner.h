#pragma once
#include<SFML/Graphics.hpp>
#include "EntityTypes.h"
#include "Vector2D.h"

class EntitySpawner {
public:
	EntitySpawner();
	~EntitySpawner();

	void spawnEntities(sf::CircleShape* shape, int ammount, EntityType type);

	bool checkIfSpaceEmpty(sf::CircleShape& shape);

	std::vector<sf::CircleShape*> getCircleVector() const;

	std::vector<sf::CircleShape*>* getCircleVectorPointer();

	Vector2D calcPostionForRespawn();

	unsigned int getEnemyCount() const;
private:
	std::vector<sf::CircleShape*> m_circleVector;
	unsigned int enemyCount;
};