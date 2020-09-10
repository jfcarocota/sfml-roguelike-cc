#include "Animation.hh"
struct AnimationState
{
    Animation* animation;
    AnimationState* transition;
    float rule{};

    AnimationState(Animation* animation, AnimationState* transition)
    {
        this->animation = animation;
        this->transition = transition;
    }
};
