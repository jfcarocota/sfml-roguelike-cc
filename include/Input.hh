#include <SFML/Graphics.hpp>

struct Input
{
    private:
        Vec2* axis;
    public:

        Vec2* JoystickAxis()
        {
            float x{sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X)/100};
            float y{sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y)/100};

            x = x > 0.2f ? 1 : x < -0.2f ? -1 : 0;
            y = y > 0.2f ? 1 : y < -0.2f ? -1 : 0;
            axis = new Vec2(x, y);
            return axis;
        }
};
