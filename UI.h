//
// Created by Marius on 13/01/2023.
//

#ifndef ASTEROIDS_UI_H
#define ASTEROIDS_UI_H

#include <SFML/Graphics.hpp>

enum HomeChoices {
    Play,
    Quit
};

class UI {
public:
    explicit UI(sf::RenderWindow& window);
    void drawGameUi();
    void drawHomeUi();
    void setScore(int score);
    void setHighscore(int score);
    void setHealth(short health);

    inline short getChoice() const { return choice; };
    void increment();
    void decrement();

private:
    sf::RenderWindow& window;

    sf::Sprite home_screen;

    sf::Font font;
    sf::Text text_score;
    sf::Text text_highscore;
    sf::Text text_choice;

    short choice = 0;
    std::string_view textChoiceUpdate() const;

    sf::Texture texture;
    sf::Sprite sprite;
    int sprite_width_size{};
};


#endif //ASTEROIDS_UI_H
