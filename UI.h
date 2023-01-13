//
// Created by Marius on 13/01/2023.
//

#ifndef ASTEROIDS_UI_H
#define ASTEROIDS_UI_H

#include <SFML/Graphics.hpp>

class UI {
public:
    UI();
    void addScore(int value);
    void draw(sf::RenderWindow& window);
private:
    void refresh();

    int score{};
    sf::Font font;
    sf::Text text_score;
};


#endif //ASTEROIDS_UI_H
