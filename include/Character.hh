#include <SFML/Graphics.hpp>
#include<iostream>
#include "StateMachine.hh"

class Character
{
    private:
        const char* spriteSheet;
        sf::Texture texture;
        sf::Sprite* sprite;
        Vec2* spriteScale; 
        Vec2* transformScale;
        Vec2* position;
        float moveSpeed;
        uint32_t col{1};
        uint32_t row{1};
        Animation** animations;
        StateMachine* stateMachine;

        void InitSprite();
        void FlipSprite(float&);
    public:
        Character(const char*, Vec2*, Vec2*, Vec2*, float);
        Character(const char*, Vec2*, Vec2*, Vec2*, float, uint32_t, uint32_t);
        ~Character();
        sf::Sprite* GetSprite() const;
        sf::Texture GetTexture() const;
        void Movement(float&, Vec2*);
        Animation* GetAnimation(unsigned int) const;
        StateMachine* GetStateMachine() const;
        void SetStateMachine(StateMachine*);
};
