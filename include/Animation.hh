#include<SFML/Graphics.hpp>
#include "Vec2.hh"

class Animation
{
    private:
        unsigned int first;
        unsigned int last;
        unsigned int frame;
        float delay;
        float currentTime;
        sf::Sprite* sprite;
        Vec2* spriteScale;
        unsigned int col;
        unsigned int row;
        bool isRunnig{false};
    public:
        Animation(unsigned int, unsigned int, float, sf::Sprite*&, Vec2*&, unsigned int, unsigned int);
        ~Animation();
        void Play(float&);
        bool IsRunning() const;
};

