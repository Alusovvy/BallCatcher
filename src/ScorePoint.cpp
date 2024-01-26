#include "ScorePoint.h"
#include <iostream>

ScorePoint::ScorePoint(sf::CircleShape shape)
	: Entity(shape, EntityType::pointType)
{
}

ScorePoint::~ScorePoint()
{
}

void ScorePoint::handleCollisionWith(EntityType type)
{
	if (type == EntityType::playerType) {
		relocate();
	}
}

void ScorePoint::relocate()
{
	std::cout << "Score point relocating..." << std::endl;
}
