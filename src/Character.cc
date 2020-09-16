#include<SFML/Graphics.hpp>
#include<Character.hh>
#include<box2d/box2d.h>

Character::Character(const char* spriteSheet, Vec2* spriteSize, Vec2* transformScale, Vec2* position, float moveSpeed)
{
    this->spriteSheet = spriteSheet;
    this->spriteSize = spriteSize;
    this->transformScale = transformScale;
    this->position = position;
    this->moveSpeed = moveSpeed;

    InitSprite();
}

Character::Character(const char* spriteSheet, Vec2* spriteSize, Vec2* transformScale, Vec2* position, float moveSpeed, uint32_t col, uint32_t row, BoxCollider* collider)
{
    this->spriteSheet = spriteSheet;
    this->spriteSize = spriteSize;
    this->transformScale = transformScale;
    this->position = position;
    this->moveSpeed = moveSpeed;
    this->col = col;
    this->row = row;
    this->collider = collider;

    InitSprite();
}

Character::~Character(){}

void Character::InitSprite()
{
    texture.loadFromFile(spriteSheet);
    sprite = new sf::Sprite(texture, sf::IntRect(spriteSize->x *col, spriteSize->y * row, spriteSize->x, spriteSize->y));
    sprite->setScale(transformScale->x, transformScale->y);
    sprite->setPosition(position->x, position->y);
    collider->SetPosition(position->x, position->y);

    animations = new Animation*[2]
    {
        new Animation(1, 5, 80.f, sprite, spriteSize, 1, 5),
        new Animation(1, 5, 80.f, sprite, spriteSize, 1, 6)
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

/*void Character::Movement(float& deltaTime, Vec2* axis, b2Body*& body)
{
    body->SetLinearVelocity(*(new b2Vec2(axis->x * deltaTime * moveSpeed, axis->y * deltaTime * moveSpeed)));
    FlipSprite(axis->x);
}*/

void Character::Movement(float& deltaTime, Vec2* axis)
{
    collider->Move(axis->x * deltaTime * moveSpeed, axis->y * deltaTime * moveSpeed, sprite);
    
    FlipSprite(axis->x);
}

BoxCollider* Character::GetCollider() const
{
    return collider;
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

StateMachine* Character::GetStateMachine() const
{
    return stateMachine;
}

void Character::SetStateMachine(StateMachine* stateMachine)
{
    this->stateMachine = stateMachine;
}