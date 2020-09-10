#include "Animation.hh"

Animation::Animation(unsigned int first, unsigned int last, float delay, sf::Sprite*& sprite, Vec2*& spriteScale)
{
    this->first = first;
    this->last = last;
    this->delay = delay;
    this->sprite = sprite;
    this->spriteScale = spriteScale;
    this->frame = first;
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
        frame = frame < last ? frame + 1 : first;
        sprite->setTextureRect(sf::IntRect(spriteScale->x * frame, spriteScale->y * 5, spriteScale->x, spriteScale->y));
    }
}

bool Animation::IsRunning() const
{
    return isRunnig;
}