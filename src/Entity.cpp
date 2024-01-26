#include "Entity.h"

Entity::Entity(sf::CircleShape& shape, EntityType type)
	:shape(shape), type(type)
{
}

Entity::~Entity()
{
}

sf::CircleShape& Entity::getShape()
{
	return shape;
}

EntityType Entity::getType() const
{
	return type;
}

void Entity::handleCollision(EntityType type)
{
}

