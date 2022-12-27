//
// Created by Marius on 27/12/2022.
//

#ifndef ASTEROIDS_FLIGHT_H
#define ASTEROIDS_FLIGHT_H

#include <SFML/Graphics.hpp>

class Flight {
public:
    Flight();
    void handlePlayerInputs(float deltaTime);
    void draw(sf::RenderWindow& window);
private:
    static sf::Vector2f acquire_movement(float speed, float angle_rotation);
    sf::Sprite sprite;
    sf::Texture texture;
    const float ACCELERATION{70.f};
    const float ANGLE_SPEED{200.f};
    const float FRICTION{3.f};
    float speed{};
};


#endif //ASTEROIDS_FLIGHT_H
