#pragma once
#include "GameObject.h"
#include "UISystem.h"
#include "EventSystem.h"
#include "Game.h"

class LevelUI : public GameObject {
public:
	LevelUI(Game* game) {
		ui = new UI("DS-DIGI.ttf", 30, sf::Color::White, sf::Vector2f(0, 0));
		this->game = game;
	}
	~LevelUI() override {
		delete ui;
	}
	void Update(float dt) override {
		score = game->GetScore();
		lives = game->GetLives();
	};
	void Draw(sf::RenderWindow* window) override {
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
	int score = 0;
	int lives = 0;
};