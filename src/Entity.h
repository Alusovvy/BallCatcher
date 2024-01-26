#pragma once
#include<SFML/Graphics.hpp>
#include "EntityTypes.h"

class Entity
{
public:
	Entity(sf::CircleShape& shape, EntityType type);
	virtual ~Entity();

	sf::CircleShape& getShape();

	EntityType getType() const;

	virtual void handleCollision(EntityType type);

private: 
	sf::CircleShape shape;
	EntityType type;
};

