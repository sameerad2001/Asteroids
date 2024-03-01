#pragma once
#include "GameObject.h"
#include "UISystem.h"
#include "EventSystem.h"
#include "Game.h"

class LevelUI : public GameObject {
public:
	LevelUI(sf::RenderWindow* window, Game* game) {
		ui = new UI("DS-DIGI.ttf", 30, sf::Color::White, sf::Vector2f(0, 0));
		this->window = window;	
		this->game = game;
	}
	~LevelUI() override {
		delete ui;
	}
	void Update(float dt) override {
		score = game->GetScore();
		score = game->GetLives();
	};
	void Draw() override {
		ui->setText("Score " + std::to_string(score));
		ui->setPosition(sf::Vector2f(10, 10));
		ui->draw(window);

		ui->setText("Lives " + std::to_string(lives));
		ui->setPosition(sf::Vector2f(10, 35));
		ui->draw(window);
	}
	void OnCollision(GameObject* other) override {};

protected:
	UI* ui;
	Game* game;
	sf::RenderWindow* window;
	int score = 0;
	int lives = 0;
};