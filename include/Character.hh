#include <SFML/Graphics.hpp>
#include<iostream>
#include "Vec2.hh"

class Character
{
    private:
        std::string spriteSheet;
        sf::Texture texture;
        sf::Sprite* sprite;
        Vec2* spriteScale; 
        Vec2* transformScale;
        Vec2* position;
    public:
        Character(std::string, Vec2*, Vec2*, Vec2*);
        ~Character();
        void InitSprite(std::string&, Vec2*&, Vec2*&, Vec2*&);
        sf::Sprite* GetSprite() const;
};
