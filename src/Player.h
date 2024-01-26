#include "Vector2D.h"
#include "Entity.h"

class Player : public Entity {
private:
	unsigned int score = 4;
	float speed;

public:
	Player(sf::CircleShape player, float speed);
	~Player();

	sf::CircleShape* move(Vector2D vec, int wWidth, int wHeight);

	sf::CircleShape& getPlayer();

	void handleCollision(EntityType type) override;

	void changeScore(int i);

	int getScore();

	float getSpeed();
};