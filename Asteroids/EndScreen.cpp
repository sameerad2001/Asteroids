#include "EndScreen.h"

EndScreen::EndScreen(sf::RenderWindow* window, int score)
{
    ui = new UI("DS-DIGI.ttf", 30, sf::Color::White, sf::Vector2f(0, 0));
    this->window = window;
    this->score = score;
}

EndScreen::~EndScreen() {
    delete ui;
}

void EndScreen::Update(float dt)
{
    endScreenDisplayTime -= dt;
    if (endScreenDisplayTime <= 0) {
        isTransitioning = true;
        return;
    }

    sf::Vector2u windowSize = window->getSize();

    std::string deathText = "You Died!";
    ui->SetText(deathText);
    ui->SetCharacterSize(80);
    ui->SetColor(sf::Color::Red);
    float deathTextLength = deathText.length() * ui->GetCharecterSize();
    ui->SetPosition(sf::Vector2f((windowSize.x - deathTextLength / 2) / 2.0f, windowSize.y / 2.0f - 100));
    ui->Draw(window);

    std::string scoreText = "Score : " + std::to_string(score);
    ui->SetText(scoreText);
    ui->SetCharacterSize(30);
    ui->SetColor(sf::Color::White);
    float scoreTextLength = scoreText.length() * ui->GetCharecterSize();
    ui->SetPosition(sf::Vector2f((windowSize.x - scoreTextLength / 2) / 2.0f, windowSize.y / 2.0f - 15));
    ui->Draw(window);
}

void EndScreen::TransitionScene()
{
    SceneManager* sceneManger = SceneManager::GetInstance();
    sceneManger->PopScene();
}
