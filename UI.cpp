//
// Created by Marius on 13/01/2023.
//

#include "UI.h"
#include "AirAmericana.h"

UI::UI(sf::RenderWindow& window) : window(window) {
    if (!font.loadFromMemory(Air_Americana_ttf, Air_Americana_ttf_size)) {
        throw std::runtime_error("Unable to access font");
    }
    text_score.setFont(font);
    text_score.setScale(2, 2);
    text_score.setPosition(30, 30);
    text_score.setString("Score: " + std::to_string(0));

    text_level.setFont(font);
    text_level.setScale(1.5, 1.5);
    text_level.setPosition(30, 100);
    text_level.setString("Level: " + std::to_string(1));

    if (!texture.loadFromFile("resources/hearts.png")) {
        // Handle loading error
    }
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getLocalBounds().width, 0);
    sprite.setScale(0.3, 0.3);
    sprite.setPosition(static_cast<float>(window.getSize().x) - 30, 30);
    sprite_width_size = static_cast<int>(sprite.getLocalBounds().width / 3);
}

void UI::setScore(int score) {
    text_score.setString("Score: " + std::to_string(score));
}

void UI::setLevel(int level) {
    text_level.setString("Level: " + std::to_string(level));
}

void UI::draw() {
    window.draw(text_score);
    window.draw(sprite);
    window.draw(text_level);
}

void UI::setHealth(short health) {
    if (health > 3)
        throw std::invalid_argument("health");
    sprite.setTextureRect(sf::IntRect(0,0,
                                      (sprite_width_size * health),
                                      static_cast<int>(sprite.getLocalBounds().height)));
}
