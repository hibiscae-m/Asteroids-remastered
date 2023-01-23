//
// Created by Marius on 23/01/2023.
//

#include "TextScore.h"
#include "AirAmericana.h"

TextScore::TextScore(int value, sf::Vector2f position) : Entity() {
    if (!font.loadFromMemory(Air_Americana_ttf, Air_Americana_ttf_size)) {
        throw std::runtime_error("Unable to access font");
    }
    text_score.setFont(font);
    text_score.setPosition(position.x + 25, position.y - 45);
    text_score.setString("+" + std::to_string(value));
}

void TextScore::move(float delta_time) {
    if (clock.getElapsedTime().asSeconds() < life_time.asSeconds() / 5)
        text_score.move(0, -2);
    else if (clock.getElapsedTime() < life_time)
            text_score.setFillColor(sf::Color(text_score.getFillColor().r,
                                                  text_score.getFillColor().g,
                                                   text_score.getFillColor().b,
                                                  text_score.getFillColor().a - 5));
    else
        destructed = true;
}

void TextScore::draw(sf::RenderWindow& window) const {
    window.draw(text_score);
}
