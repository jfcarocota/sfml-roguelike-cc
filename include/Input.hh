#include <SFML/Graphics.hpp>

struct Input
{
    private:
        
    public:

        Vec2* JoystickAxis()
        {
            float x{sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X)/100};
            float y{sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y)/100};

            x = x > 0.2f ? 1 : x < -0.2f ? -1 : 0;
            y = y > 0.2f ? 1 : y < -0.2f ? -1 : 0;
            return new Vec2(x, y);
        }

        Vec2* KeyboardAxis()
        {
            float x{};
            float y{};

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            {
                x = 1;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            {
                x = -1;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            {
                y = 1;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            {
                y = -1;
            }

            return new Vec2(x, -y);
        }
};
