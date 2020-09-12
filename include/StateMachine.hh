#include<iostream>
#include "AnimationState.hh"

class StateMachine
{
    private:
        std::vector<AnimationState*>* states;
    public:
        StateMachine(std::vector<AnimationState*>*);
        ~StateMachine();
        void Run(float&);
};
