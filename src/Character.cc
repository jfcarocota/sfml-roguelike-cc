#include<SFML/Graphics.hpp>
#include<Character.hh>

Character::Character(std::string spriteSheet, Vec2* spriteScale, Vec2* transformScale, Vec2* position)
{
    this->spriteSheet = spriteSheet;
    this->spriteScale = spriteScale;
    this->transformScale = transformScale;
    this->position = position;

    InitSprite(spriteSheet, spriteScale, transformScale, position);
}

Character::~Character(){}

void Character::InitSprite(std::string& spriteSheet, Vec2*& spriteScale, Vec2*& transformScale, Vec2*& position)
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