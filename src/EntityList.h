#include<iostream>
#include "EntitySpawner.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"

class EntityList
{
public:
	EntityList(EntitySpawner& spawner);
	~EntityList();

	void addEntity(Entity* entity);
	void removeEntity(Entity* entity);
	void populateSpawner();
	void detectCollision();

	int count() const;
private:
	std::vector<Entity*> entitiesVector;
	EntitySpawner& spawner;
	bool pointerInList(Entity* entity);
	bool isColliding(sf::CircleShape& shapeOne, sf::CircleShape& shapeTwo) const;
	void onCollisionDetected(Entity* entity1, Entity* entity2);
	void relocateEntity(Entity* entity);
	void removeFromScreen(Entity* entity);
	void checkIfAddEnemimes();

};

