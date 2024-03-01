#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class UI {
private:
    sf::Text text;
    sf::Font font;

public:
    UI(const std::string& fontPath, unsigned int fontSize, const sf::Color& textColor, const sf::Vector2f& position) {
        if (!font.loadFromFile("Assets/" + fontPath)) {
            std::cerr << "Font file not found\n";
            return; 
        }

        text.setFont(font);
        text.setCharacterSize(fontSize);
        text.setFillColor(textColor);
        text.setPosition(position);
    }

    void SetText(const std::string& newText) {
        text.setString(newText);
    }

    void SetPosition(const sf::Vector2f& newPosition) {
        text.setPosition(newPosition);
    }

    void SetColor(const sf::Color& newColor) {
        text.setFillColor(newColor);
    }

    void SetCharacterSize(unsigned int newSize) {
        text.setCharacterSize(newSize);
    }

    unsigned int GetCharecterSize() {
        return text.getCharacterSize();
    }

    void Draw(sf::RenderWindow* window) {
        window->draw(text);
    }
};