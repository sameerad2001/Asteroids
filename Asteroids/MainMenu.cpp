#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow* window)
{
	ui = new UI("DS-DIGI.ttf", 30, sf::Color::White, sf::Vector2f(0, 0));
	this->window = window;
    EventEmitter::RegisterForEvent(GAME_START, this);
}

MainMenu::~MainMenu() {
    delete ui;
}

void MainMenu::Update(float dt)
{
    if (isTransitioningScene) {
        EventEmitter::RemoveListner(this);
        SceneManager* sceneManger = SceneManager::GetInstance(window);
        sceneManger->ChangeScene(GAME);
        return;
    }

	sf::Vector2u windowSize = window->getSize();

    std::string titleText = "Asteroids";
    ui->SetText(titleText);
    ui->SetCharacterSize(80);
    ui->SetColor(sf::Color::Cyan);
    float titleLength = titleText.length() * ui->GetCharecterSize();
    ui->SetPosition(sf::Vector2f((windowSize.x - titleLength / 2) / 2.0f, windowSize.y / 2.0f - 100));  // Adjusted position
    ui->Draw(window);

    std::string firstLine = "Press ENTER To Start";
    ui->SetText(firstLine);
    ui->SetCharacterSize(30);
    ui->SetColor(sf::Color::White);
    float firstLineLength = firstLine.length() * ui->GetCharecterSize();
    ui->SetPosition(sf::Vector2f((windowSize.x - firstLineLength / 2) / 2.0f, windowSize.y / 2.0f - 15));
    ui->Draw(window);

    std::string secondLine = "created by Sameer Ahmed";
    ui->SetText(secondLine);
    ui->SetCharacterSize(30);
    ui->SetColor(sf::Color::White);
    float secondLineLength = secondLine.length() * ui->GetCharecterSize();
    ui->SetPosition(sf::Vector2f((windowSize.x - secondLineLength / 2) / 2.0f, windowSize.y / 2.0f + 20));
    ui->Draw(window);

}

void MainMenu::ReceiveEvent(EventType type)
{
    if (type == GAME_START) {
        isTransitioningScene = true;
    }
}
