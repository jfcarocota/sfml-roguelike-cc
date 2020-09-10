#include "Animation.hh"

Animation::Animation(unsigned int first, unsigned int last, float delay, sf::Sprite*& sprite, Vec2*& spriteScale, unsigned int col, unsigned int row)
{
    this->first = first;
    this->last = last;
    this->delay = delay;
    this->sprite = sprite;
    this->spriteScale = spriteScale;
    this->frame = first;
    this->col = col;
    this->row = row;
}

Animation::~Animation(){}

void Animation::Play(float& deltaTime)
{
    if(!isRunnig)
    {
        isRunnig = true;
    }
    currentTime += deltaTime;
    if(currentTime >= delay)
    {
        currentTime = 0.f;
        col = col < last ? col + 1 : first;
        sprite->setTextureRect(sf::IntRect(spriteScale->x * col, spriteScale->y * row, spriteScale->x, spriteScale->y));
    }
}

bool Animation::IsRunning() const
{
    return isRunnig;
}