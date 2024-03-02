#include "EndScreen.h"

EndScreen::EndScreen(sf::RenderWindow* window, int score)
{
    ui = new UI("DS-DIGI.ttf", 30, sf::Color::White, sf::Vector2f(0, 0));
    this->window = window;
    this->score = score;
    EventEmitter::RegisterForEvent(FIRE, this);
}

EndScreen::~EndScreen() {
    EventEmitter::RemoveListner(this);
    delete ui;
}

void EndScreen::Update(float dt)
{
    sf::Vector2u windowSize = window->getSize();

    std::string titleText = "Score : " + std::to_string(score);
    ui->SetText(titleText);
    ui->SetCharacterSize(80);
    ui->SetColor(sf::Color::Cyan);
    float titleLength = titleText.length() * ui->GetCharecterSize();
    ui->SetPosition(sf::Vector2f((windowSize.x - titleLength / 2) / 2.0f, windowSize.y / 2.0f - 100));
    ui->Draw(window);

    std::string firstLine = "Press SPACE";
    ui->SetText(firstLine);
    ui->SetCharacterSize(30);
    ui->SetColor(sf::Color::White);
    float firstLineLength = firstLine.length() * ui->GetCharecterSize();
    ui->SetPosition(sf::Vector2f((windowSize.x - firstLineLength / 2) / 2.0f, windowSize.y / 2.0f - 15));
    ui->Draw(window);
}

void EndScreen::ReceiveEvent(EventType type)
{
    if (type == FIRE) {
        isTransitioning = true;
    }
}

void EndScreen::TransitionScene()
{
    SceneManager* sceneManger = SceneManager::GetInstance();
    sceneManger->PopScene();
}
