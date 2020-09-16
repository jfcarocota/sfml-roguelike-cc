#include "BoxCollider.hh"

BoxCollider::BoxCollider(float width, float height, sf::Color* outlineColor, float outlineSize, b2World*& world)
{
    this->width = width;
    this->height = height;
    this->outlineColor = outlineColor;
    this->outlineSize = outlineSize;
    this->world = world;

    InitCollider();
}

BoxCollider::~BoxCollider(){}

void BoxCollider::InitCollider()
{
    //shape
    boxShape = new sf::RectangleShape(sf::Vector2f(width, height));
    boxShape->setFillColor(sf::Color::Transparent);
    boxShape->setOutlineColor(*outlineColor);
    boxShape->setOutlineThickness(outlineSize);

    //physics
    bodyDef = new b2BodyDef();
    bodyDef->type = b2BodyType::b2_dynamicBody;
    bodyDef->position = b2Vec2(boxShape->getPosition().x, boxShape->getPosition().y);
    body = world->CreateBody(bodyDef);
    polyShape = new b2PolygonShape();
    polyShape->SetAsBox(width / 2, height / 2);
    fixtureDef = new b2FixtureDef();
    fixtureDef->shape = polyShape;
    fixtureDef->density = 1.f;
    fixtureDef->friction = 0.f;
    fixtureDef->restitution = 0.f;
    fixture = body->CreateFixture(fixtureDef); 
}

sf::RectangleShape* BoxCollider::GetShape() const
{
    return boxShape;
}

void BoxCollider::Move(float x, float y)
{
    body->SetLinearVelocity(*(new b2Vec2(x, y)));
    boxShape->setPosition(body->GetPosition().x, body->GetPosition().y);
}

void BoxCollider::Move(float x, float y, sf::Sprite*& sprite)
{
    body->SetLinearVelocity(*(new b2Vec2(x, y)));
    boxShape->setPosition(body->GetPosition().x, body->GetPosition().y);
    sprite->setPosition(body->GetPosition().x, body->GetPosition().y);
}

void BoxCollider::SetPosition(float x, float y)
{
    bodyDef->position = *(new b2Vec2(x, y));
    boxShape->setPosition(body->GetPosition().x, body->GetPosition().y);
}