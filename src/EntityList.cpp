#include "EntityList.h"

EntityList::EntityList(EntitySpawner& spawner)
	: spawner(spawner)
{
}

EntityList::~EntityList()
{
}

void EntityList::addEntity(Entity* entity)
{
	if (!pointerInList(entity)) {
		entitiesVector.push_back(entity);
	}
}

void EntityList::removeEntity(Entity* entity)
{
	if (pointerInList(entity)) {
		for (int i = 0; i < entitiesVector.size(); i++) {
			if (entitiesVector[i] == entity) {
				entitiesVector[i] = nullptr;
			}
		}
	}

}

void EntityList::populateSpawner()
{
	for (int i = 0; i < entitiesVector.size(); i++) {
		spawner.getCircleVectorPointer()->push_back(&entitiesVector[i]->getShape());
		spawner.spawnEntities(&entitiesVector[i]->getShape(), 1, entitiesVector[i]->getType());
	}

	

}

void EntityList::detectCollision()
{
	for (int i = 0; i < entitiesVector.size(); i++) {
		for (int y = 0; y < entitiesVector.size(); y++) {
			if (isColliding(entitiesVector[i]->getShape(), entitiesVector[y]->getShape()) && entitiesVector[i]-> getType() != entitiesVector[y]->getType()) {
				onCollisionDetected(entitiesVector[i], entitiesVector[y]);
				std::cout << "Object " << entitiesVector[i]->getType() << " Collided with object " << entitiesVector[y]->getType() << std::endl;
			}
		}
	}
}

bool EntityList::isColliding(sf::CircleShape& shapeOne, sf::CircleShape& shapeTwo) const  {
	return shapeOne.getGlobalBounds().intersects(shapeTwo.getGlobalBounds());
}

void EntityList::onCollisionDetected(Entity* entity1, Entity* entity2) {
	entity1->handleCollision(entity2->getType());
	entity2->handleCollision(entity1->getType());

	if (entity1->getType() == EntityType::enemyType || entity1->getType() == EntityType::pointType) {
		relocateEntity(entity1);
		checkIfAddEnemimes();
	}
	else if (entity2->getType() == EntityType::enemyType || entity2->getType() == EntityType::pointType) {
		relocateEntity(entity2);
		checkIfAddEnemimes();
	}

}

void EntityList::removeFromScreen(Entity* entity) {
	for (int i = 0; i < spawner.getCircleVector().size(); i++) {
		if ((*spawner.getCircleVectorPointer())[i] == &entity->getShape()) {
			(*spawner.getCircleVectorPointer())[i] = nullptr;
		}
	}
}

void EntityList::checkIfAddEnemimes() {
	for (int i = 0; i < entitiesVector.size(); i++) {
		if (entitiesVector[i]->getType() == EntityType::playerType) {
			Player* player = (Player*)entitiesVector[i];
			if (player->getScore() % 5 == 0) {
				sf::CircleShape shape(30);
				Enemy* enemy = new Enemy(shape, 2);
				spawner.spawnEntities(&enemy->getShape(), 1, EntityType::enemyType);
			}
		}
	}
}

void EntityList::relocateEntity(Entity* entity) {
	spawner.spawnEntities(&entity->getShape(), 1, entity->getType());
}

int EntityList::count() const {
	return entitiesVector.size();
}

bool EntityList::pointerInList(Entity* pointer)
{
	for (int i = 0; i < entitiesVector.size(); i++) {
		if (entitiesVector[i] == pointer) return true;
	}
	return false;
}
