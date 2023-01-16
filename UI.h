//
// Created by Marius on 13/01/2023.
//

#ifndef ASTEROIDS_UI_H
#define ASTEROIDS_UI_H

#include <SFML/Graphics.hpp>

class UI {
public:
    explicit UI(sf::RenderWindow& window);
    void draw();
    void setScore(int score);
    void setHealth(short health);
private:
    sf::RenderWindow& window;

    sf::Font font;
    sf::Text text_score;

    sf::Texture texture;
    sf::Sprite sprite;
    int sprite_width_size{};
};


#endif //ASTEROIDS_UI_H
