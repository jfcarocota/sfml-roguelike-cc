#include <SFML/Graphics.hpp>
#include<box2d/box2d.h>

class BoxCollider
{
    private:
        sf::RectangleShape* boxShape;
        float width{}, height{};
        sf::Color* outlineColor;
        float outlineSize;
        b2World* world;
        b2BodyDef* bodyDef;
        b2Body* body;
        b2PolygonShape* polyShape;
        b2FixtureDef* fixtureDef;
        b2Fixture* fixture;

        void InitCollider();
    public:
        BoxCollider(float, float, sf::Color*, float, b2World*&);
        ~BoxCollider();
        sf::RectangleShape* GetShape() const;

        void Move(float, float);
        void Move(float, float, sf::Sprite*&);
        void SetPosition(float, float);
};
