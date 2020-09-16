#include <SFML/Graphics.hpp>
#include<iostream>
#include "StateMachine.hh"
#include<box2d/box2d.h>
#include "BoxCollider.hh"

class Character
{
    private:
        const char* spriteSheet;
        sf::Texture texture;
        sf::Sprite* sprite;
        Vec2* spriteSize; 
        Vec2* transformScale;
        Vec2* position;
        float moveSpeed;
        uint32_t col{1};
        uint32_t row{1};
        Animation** animations;
        StateMachine* stateMachine;
        BoxCollider* collider;

        void InitSprite();
        void FlipSprite(float&);
    public:
        Character(const char*, Vec2*, Vec2*, Vec2*, float);
        Character(const char*, Vec2*, Vec2*, Vec2*, float, uint32_t, uint32_t, BoxCollider*);
        ~Character();
        sf::Sprite* GetSprite() const;
        sf::Texture GetTexture() const;
        //void Movement(float&, Vec2*);
        //void Movement(float&, Vec2*, b2Body*&);
        void Movement(float&, Vec2*);
        Animation* GetAnimation(unsigned int) const;
        StateMachine* GetStateMachine() const;
        void SetStateMachine(StateMachine*);

        BoxCollider* GetCollider() const;
};
