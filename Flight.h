//
// Created by Marius on 27/12/2022.
//

#ifndef ASTEROIDS_FLIGHT_H
#define ASTEROIDS_FLIGHT_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "GameManager.h"

class Flight : public Entity {
public:
    Flight(GameManager& game_manager, float position_x, float position_y);
    void move(float delta_time) override;
private:
    void handlePlayerInputs(float delta_time);
    void shoot();
    void reactCollision(const Entity& other) override;
    void checkHealth();

    const float ACCELERATION = 70.f;
    const float ANGLE_SPEED = 200.f;
    const float FRICTION= 3.f;
    short health = 3;

    bool damaged = false;
    sf::Clock damage_clock;
    sf::Time damage_invincibility = sf::seconds(2);
    sf::Clock blink_clock;
    sf::Time blink_duration = sf::milliseconds(100);

    sf::Clock shoot_clock;
    sf::Time time_since_last_shoot = sf::Time::Zero;
    sf::Time shoot_cooldown = sf::milliseconds(300);

    GameManager& game_manager;
};


#endif //ASTEROIDS_FLIGHT_H
