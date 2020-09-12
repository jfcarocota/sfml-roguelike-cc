#include<iostream>
#include<math.h>
#include <SFML/Graphics.hpp>
#include "Character.hh"
#include "Input.hh"

#define GAME_NAME "Roguelike game"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define MOVE_SPEED 0.2f
#define FPS 60
#define SPRITE_SCALE 4.f

int main()
{
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
    sf::Event event;
    window->setFramerateLimit(FPS);
    sf::Font font;
    font.loadFromFile("assets/fonts/PixelGameFont.ttf");
    sf::Text textFPS;
    textFPS.setFont(font);
    textFPS.setCharacterSize(14);

    //w = wall sprite
    //g = ground sprite
    char** maze
    {
        new char*[10]
        {
            new char[10]{'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},
            new char[10]{'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g'},
            new char[10]{'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g'},
            new char[10]{'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g'},
            new char[10]{'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g'},
            new char[10]{'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g'},
            new char[10]{'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g'},
            new char[10]{'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g'},
            new char[10]{'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g'},
            new char[10]{'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g'}
        }
    };

    sf::Texture* tilesTexture = new sf::Texture();
    tilesTexture->loadFromFile("assets/sprites/tiles2.png");
    sf::Sprite* wallSprite = new sf::Sprite(*tilesTexture, sf::IntRect(16 * 0, 16 * 1, 32, 16));
    wallSprite->setScale(SPRITE_SCALE, SPRITE_SCALE);
    //wallSprite->setPosition(0, 0);
    sf::Sprite* groundSprite = new sf::Sprite(*tilesTexture, sf::IntRect(32 * 0, 32 * 2, 32, 16));
    groundSprite->setScale(SPRITE_SCALE, SPRITE_SCALE);
    //groundSprite->setPosition(0, 64);
    std::vector<sf::Sprite> mazeSprites;

    //Maze logic
    for(int i{}; i < 10; i++)
    {
        for(int j{}; j < 10; j++)
        {
            std::cout << *(*(maze + i) + j) << "\t";
            if(*(*(maze + i) + j) == 'w')
            {
                mazeSprites.push_back(*wallSprite);
                mazeSprites.back().setPosition(64 * j, 64 * i);
            }
            if(*(*(maze + i) + j) == 'g')
            {
                mazeSprites.push_back(*groundSprite);
                mazeSprites.back().setPosition(64 * j, 64 * i);
            }
        }
        std::cout << std::endl;
    }

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

    /*player->SetStateMachine( new StateMachine(new std::vector<Animation*>*()
    {
        new Animation(1, 5, 80.f, sprite, spriteScale, 1, 5),
        new Animation(1, 5, 80.f, sprite, spriteScale, 1, 6)
    }));*/

    sf::Clock clock;
    sf::Time time;

    float deltaTime{};

    Input input;

    Vec2* axis;

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

        if(sf::Joystick::isConnected(0))
        {   
            player->Movement(deltaTime, input.JoystickAxis());
        }

        
        time = clock.restart();
        deltaTime = time.asMilliseconds();
        window->clear();
        //window->draw(*wallSprite);
        //window->draw(*groundSprite);

        for(auto& tile : mazeSprites)
        {
            window->draw(tile);
        }

        window->draw(*player->GetSprite());

        //window->draw(textFPS);
        window->display();
        if(std::abs(input.JoystickAxis()->x) > 0 || std::abs(input.JoystickAxis()->y) > 0)
        {
            player->GetAnimation(1)->Play(deltaTime);
        }else
        {
            player->GetAnimation(0)->Play(deltaTime);
        }
    }

    return 0;
}