#include<iostream>
#include<string.h>
#include <SFML/Graphics.hpp>
#include "Character.hh"

#define SCALE_SS 16
#define MOVE_SPEED 0.2f
#define FPS 60
#define SPRITE_SCALE 3.f

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
        "assets/sprites/tiles.png", 
        new Vec2(SCALE_SS, SCALE_SS), 
        new Vec2(SPRITE_SCALE, SPRITE_SCALE), 
        new Vec2(window->getSize().x / 2.f, window->getSize().y / 2.f),
        MOVE_SPEED)
    };

    sf::Clock clock;
    sf::Time time;

    float deltaTime{};

    while(window->isOpen())
    {
        sf::Time time = clock.getElapsedTime();

        textFPS.setString(std::to_string((1.f / time.asSeconds())) + "FPS");

        while (window->pollEvent(event))
        {
            
            if(event.type == sf::Event::Closed)
            {
                window->close();
            }
            
        }

        //sprite.setScale(sf::Vector2(SPRITE_SCALE, SPRITE_SCALE));
        //sprite.setOrigin(0.f, 0.f);

        /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            sprite.move(sf::Vector2(-1.f, 0.f) * MOVE_SPEED * deltaTime);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            sprite.move(sf::Vector2(1.f, 0.f) * MOVE_SPEED * deltaTime);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            sprite.move(sf::Vector2(0.f, -1.f) * MOVE_SPEED * deltaTime);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            sprite.move(sf::Vector2(0.f, 1.f) * MOVE_SPEED * deltaTime);
        }*/
        player->Movement(deltaTime);

        //sprite.move(sf::Vector2(-1.f, 0.f) * MOVE_SPEED); //left
        time = clock.restart();
        deltaTime = time.asMilliseconds();
        window->clear();
        window->draw(textFPS);
        window->draw(*player->GetSprite());
        window->display();
    }

    return 0;
}

/*void FlipSprite(float& x, sf::Sprite& sprite)
{
    if(x > 0.f)
    {
        sprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
        sprite.setOrigin(0.f, 0.f);
    }
    if(x < 0.f)
    {
        sprite.setScale(-SPRITE_SCALE, SPRITE_SCALE);
        sprite.setOrigin(sprite.getGlobalBounds().width / SPRITE_SCALE, 0.f);
    }
}*/