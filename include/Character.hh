#include <SFML/Graphics.hpp>
#include<iostream>
#include "Vec2.hh"

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
        void InitSprite();
        void FlipSprite(float&);
    public:
        Character(const char*, Vec2*, Vec2*, Vec2*, float);
        ~Character();
        sf::Sprite* GetSprite() const;
        void Movement(float);
};
