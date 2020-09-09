#include<SFML/Graphics.hpp>
#include<Character.hh>

Character::Character(const char* spriteSheet, Vec2* spriteScale, Vec2* transformScale, Vec2* position, float moveSpeed)
{
    this->spriteSheet = spriteSheet;
    this->spriteScale = spriteScale;
    this->transformScale = transformScale;
    this->position = position;
    this->moveSpeed = moveSpeed;

    InitSprite(spriteSheet, spriteScale, transformScale, position);
}

Character::~Character(){}

void Character::InitSprite(const char*& spriteSheet, Vec2*& spriteScale, Vec2*& transformScale, Vec2*& position)
{
    texture.loadFromFile(spriteSheet);
    sprite = new sf::Sprite(texture, sf::IntRect(spriteScale->x * 11, spriteScale->y * 15, spriteScale->x, spriteScale->y));
    sprite->setScale(sf::Vector2(transformScale->x, transformScale->y));
    sprite->setPosition(sf::Vector2(position->x, position->y));
}

sf::Sprite* Character::GetSprite() const
{
    return sprite;
}

void Character::Movement(float deltaTime)
{
    if(sf::Joystick::isConnected(0))
        {
            float x{sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X)/100};
            float y{sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y)/100};
            
            x = x > 0.2f ? 1 : x < -0.2f ? -1 : 0;
            y = y > 0.2f ? 1 : y < -0.2f ? -1 : 0;
            sf::Vector2 axis{sf::Vector2(x, y)};

            sprite->move(axis * moveSpeed * deltaTime);

            //FlipSprite(x, *player->GetSprite());
        }
}