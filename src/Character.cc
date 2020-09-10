#include<SFML/Graphics.hpp>
#include<Character.hh>

Character::Character(const char* spriteSheet, Vec2* spriteScale, Vec2* transformScale, Vec2* position, float moveSpeed)
{
    this->spriteSheet = spriteSheet;
    this->spriteScale = spriteScale;
    this->transformScale = transformScale;
    this->position = position;
    this->moveSpeed = moveSpeed;

    InitSprite();
}

Character::Character(const char* spriteSheet, Vec2* spriteScale, Vec2* transformScale, Vec2* position, float moveSpeed, uint32_t col, uint32_t row)
{
    this->spriteSheet = spriteSheet;
    this->spriteScale = spriteScale;
    this->transformScale = transformScale;
    this->position = position;
    this->moveSpeed = moveSpeed;
    this->col = col;
    this->row = row;

    InitSprite();
}

Character::~Character(){}

void Character::InitSprite()
{
    texture.loadFromFile(spriteSheet);
    sprite = new sf::Sprite(texture, sf::IntRect(spriteScale->x *col, spriteScale->y * row, spriteScale->x, spriteScale->y));
    sprite->setScale(transformScale->x, transformScale->y);
    sprite->setPosition(position->x, position->y);

    animations = new Animation*[2]
    {
        new Animation(1, 5, 80.f, sprite, spriteScale, 1, 5),
        new Animation(1, 5, 80.f, sprite, spriteScale, 1, 6)
    };
}

sf::Sprite* Character::GetSprite() const
{
    return sprite;
}

sf::Texture Character::GetTexture() const
{
    return texture;
}

Animation* Character::GetAnimation(unsigned int index) const
{
    return *(animations + index);
}

void Character::Movement(float& deltaTime, Vec2*& axis)
{
    if(sf::Joystick::isConnected(0))
    {
        
        sprite->move(sf::Vector2(axis->x, axis->y) * moveSpeed * deltaTime);

        FlipSprite(axis->x);
    }
}

void Character::FlipSprite(float& axisX)
{
    if(axisX > 0.f)
    {
        sprite->setScale(transformScale->x, transformScale->y);
        sprite->setOrigin(0.f, 0.f);
    }
    if(axisX < 0.f)
    {
        sprite->setScale(-transformScale->x, transformScale->y);
        sprite->setOrigin(sprite->getGlobalBounds().width / transformScale->x, 0.f);
    }
}