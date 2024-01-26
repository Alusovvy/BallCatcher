#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<memory>
#include <thread>
#include "Vector2D.h"
#include "EntityTypes.h"
#include "EntitySpawner.h"
#include "EntityList.h"
#include "ScorePoint.h"
#include <SFML/Audio.hpp>

using namespace std;



// top-left of the window is (0,0) and bottom-right is (w,h)
const int wWidth = 1280;
const int wHeight = 720;
sf::CircleShape circle(50);				// creater a cricle shape with radius 50
sf::CircleShape collectableCircle(30);
sf::CircleShape enemy(30);

EntitySpawner *spawner = new EntitySpawner;
//add destructor for this spawner
EntityList entityList(*spawner);
Enemy realEnemy(enemy, rand() % 3);
Player player(circle, 6.0f);
ScorePoint scorePoint(collectableCircle);



float circleMoveSpeedY = 0.0f;			// we will use this to move the cricle later
float circleMoveSpeedX = 0.0f;

//player movement (move it somewhere else later on after collision refactor
Vector2D vecUp(0.0f, player.getSpeed() * -1);
Vector2D vecDown(0.0f, player.getSpeed());
Vector2D vecLeft(player.getSpeed() * -1, 0.0f);
Vector2D vecRight(player.getSpeed(), 0.0f);



int main(int argc, char* argv[]) {
	

	sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Zielona kuleczka");
	window.setFramerateLimit(60);

	sf::SoundBuffer buffer;

	if (!buffer.loadFromFile("music/msc.wav")) {
		return -1;
	}

	sf::Sound sound;

	sound.setBuffer(buffer);
	sound.play();

	sf::Font myFont;
	// attempt to load the font from the file
	if (!myFont.loadFromFile("fonts/SpaceCrusaders-x3DP0.ttf")) {

		std::cerr << "Could not load font!\n";
		exit(-1);
	}

	//load all object to EntityList
	entityList.addEntity(&player);
	entityList.addEntity(&scorePoint);
	entityList.addEntity(&realEnemy);
	entityList.populateSpawner();

	sf::Text victory("YOU WON, YOU GO THE 5 SCORES", myFont, 32);
	victory.setPosition(0, wHeight / 2);

	sf::Text defeat("YOU LOST", myFont, 32);
	defeat.setPosition(0, wHeight / 2);

	sf::Text text("Score: ", myFont, 24);
	text.setPosition(0, wHeight - (float)text.getCharacterSize());
	

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

				spawner->getCircleVector().at(0) = player.move(vecUp, wWidth, wHeight);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				spawner->getCircleVector().at(0) = player.move(vecDown, wWidth, wHeight);

			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				spawner->getCircleVector().at(0) = player.move(vecLeft, wWidth, wHeight);

			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				spawner->getCircleVector().at(0) = player.move(vecRight, wWidth, wHeight);

			}

		}

		for (int i = 0; i < spawner->getCircleVector().size(); i++) {
			if (spawner->getCircleVector().at(i)->getFillColor() == sf::Color::Red) {
				realEnemy.moveInPlayerDirection(*spawner->getCircleVector().at(i), player.getPlayer());
			}
		}

		entityList.detectCollision();




		text.setString("Score: " + std::to_string(player.getScore()));

		if (player.getScore() < 50 && player.getScore() >= 0) {
			window.clear(sf::Color::Black);
			for (auto& shape : *spawner->getCircleVectorPointer()) {
				window.draw(*shape);
			}
			window.draw(text);
			window.display();
		}
		else if(player.getScore() >= 49) {
			window.clear(sf::Color::Black);
			window.draw(victory);
			window.display();
		} else {
			window.clear(sf::Color::Black);
			window.draw(defeat);
			window.display();
			while (true) {
				int i = 1;
				cout << "Type 0 to exit" << endl;
				cin >> i;

				if (i == 0) {
					window.close();
					break;
				}
			}
		}
	}

	return 0;
}