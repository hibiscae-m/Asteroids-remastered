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
    text_score.setPosition(0, 30);
}

void UI::addScore(int value) {
    score += value;
}

void UI::draw(sf::RenderWindow& window) {
    refresh();
    window.draw(text_score);
}

void UI::refresh() {
    text_score.setString("Score: " + std::to_string(score));
}
