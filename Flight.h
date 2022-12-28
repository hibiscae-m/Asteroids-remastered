//
// Created by Marius on 27/12/2022.
//

#ifndef ASTEROIDS_FLIGHT_H
#define ASTEROIDS_FLIGHT_H

#include <SFML/Graphics.hpp>
#include <string_view>
#include "Entity.h"

class Flight : public Entity {
public:
    Flight();
    void handlePlayerInputs(float deltaTime);
    void move(float deltaTime) override;
private:
    const float ACCELERATION{70.f};
    const float ANGLE_SPEED{200.f};
    const float FRICTION{3.f};
};


#endif //ASTEROIDS_FLIGHT_H
