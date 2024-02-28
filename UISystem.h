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

    void setText(const std::string& newText) {
        text.setString(newText);
    }

    void setPosition(const sf::Vector2f& newPosition) {
        text.setPosition(newPosition);
    }

    void draw(sf::RenderWindow* window) {
        window->draw(text);
    }
};