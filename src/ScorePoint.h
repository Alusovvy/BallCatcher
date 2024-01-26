#pragma once
#include "Entity.h"

class ScorePoint : public Entity
{
public:
	ScorePoint(sf::CircleShape shape);
	~ScorePoint();

	void handleCollisionWith(EntityType type);

private:

	void relocate();
};

