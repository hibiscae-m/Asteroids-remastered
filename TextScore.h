//
// Created by Marius on 23/01/2023.
//

#ifndef ASTEROIDS_TEXTSCORE_H
#define ASTEROIDS_TEXTSCORE_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

class TextScore : public Entity{
public:
    TextScore() = delete;
    TextScore(int value, sf::Vector2f position);
    void move(float delta_time) override;
    void draw(sf::RenderWindow& window) const override;
private:
    sf::Font font;
    sf::Text text_score;
    sf::Clock clock;
    sf::Time life_time = sf::seconds(1);
};


#endif //ASTEROIDS_TEXTSCORE_H
