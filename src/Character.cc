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
}

sf::Sprite* Character::GetSprite() const
{
    return sprite;
}

sf::Texture Character::GetTexture() const
{
    return texture;
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

        FlipSprite(x);
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