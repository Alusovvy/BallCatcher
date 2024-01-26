#include "Vector2D.h"
#include "Entity.h"

class Enemy : public Entity {
private:
	int m_Speed;
	EntityType type;
public:
	Enemy(sf::CircleShape& enemy, int speed);
	~Enemy();

	void moveInPlayerDirection(sf::CircleShape& enemy, sf::CircleShape playerPosition);

	sf::CircleShape& getEnemy();

	int getSpeed() const;

	void setSpeed(int speed);

	EntityType getType() const;

	void handleCollision(EntityType type) override;

	void relocate();
};