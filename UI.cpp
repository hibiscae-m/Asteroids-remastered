//
// Created by Marius on 13/01/2023.
//

#include "UI.h"
#include "AirAmericana.h"

UI::UI() {
    if (!font.loadFromMemory(Air_Americana_ttf, Air_Americana_ttf_size)) {
        throw std::runtime_error("Unable to access font");
    }
    text_score.setFont(font);
    text_score.setScale(2, 2);
    text_score.setPosition(30, 30);
}

void UI::setScore(int score) {
    text_score.setString("Score: " + std::to_string(score));
}

void UI::draw(sf::RenderWindow& window) {
    window.draw(text_score);
}
