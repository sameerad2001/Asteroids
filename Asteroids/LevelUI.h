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
		ui->SetText("Score " + std::to_string(score));
		ui->SetPosition(sf::Vector2f(10, 10));
		ui->Draw(window);

		ui->SetText("Lives " + std::to_string(lives));
		ui->SetPosition(sf::Vector2f(10, 35));
		ui->Draw(window);
	}
	void OnCollision(GameObject* other) override {};

protected:
	UI* ui;
	Game* game;
	int score = 0;
	int lives = 0;
};