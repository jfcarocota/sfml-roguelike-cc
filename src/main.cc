#include<iostream>
#include<math.h>
#include <SFML/Graphics.hpp>
#include "Character.hh"

#define MOVE_SPEED 0.2f
#define FPS 60
#define SPRITE_SCALE 4.f

void FlipSprite(float&, sf::Sprite&);

int main()
{
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "Platform Game");
    sf::Event event;
    window->setFramerateLimit(FPS);
    sf::Font font;
    font.loadFromFile("assets/fonts/PixelGameFont.ttf");
    sf::Text textFPS;
    textFPS.setFont(font);
    textFPS.setCharacterSize(14);

    Character* player
    {
        new Character(
        "assets/sprites/tiles3.png", 
        new Vec2(16, 16), 
        new Vec2(SPRITE_SCALE, SPRITE_SCALE), 
        new Vec2(window->getSize().x / 2.f, window->getSize().y / 2.f),
        MOVE_SPEED,
        1, 5)
    };

    sf::Clock clock;
    sf::Time time;

    float deltaTime{};

    /*unsigned int first{1};
    unsigned int last{5};
    unsigned int frame{first};
    float delay{80};
    float currentTime{};*/

    while(window->isOpen())
    {
        sf::Time time = clock.getElapsedTime();

        textFPS.setString(std::to_string(llround((1.f / time.asSeconds()))) + "FPS");

        while (window->pollEvent(event))
        {
            
            if(event.type == sf::Event::Closed)
            {
                window->close();
            }
            
        }

        player->Movement(deltaTime);
        time = clock.restart();
        deltaTime = time.asMilliseconds();
        window->clear();
        window->draw(textFPS);
        window->draw(*player->GetSprite());
        window->display();

        player->GetAnimation(1)->Play(deltaTime);
    }

    return 0;
}