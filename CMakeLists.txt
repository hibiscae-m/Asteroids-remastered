cmake_minimum_required(VERSION 3.24)
project(Asteroids)

set(CMAKE_CXX_STANDARD 20)

add_executable(Asteroids main.cpp Game.cpp Game.h Flight.cpp Flight.h Asteroid.cpp Asteroid.h Vector.cpp Vector.h
               Entity.cpp Entity.h GameManager.cpp GameManager.h Missile.cpp Missile.h LivingSpace.cpp LivingSpace.h
               Explosion.cpp Explosion.h UI.cpp UI.h AirAmericana.h TextScore.cpp TextScore.h Heart.cpp Heart.h ResourcesManager.cpp ResourcesManager.h Bonus.cpp Bonus.h ShootSpeed.cpp ShootSpeed.h Shield.cpp Shield.h MultipleShots.cpp MultipleShots.h)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(Asteroids sfml-graphics sfml-audio)
