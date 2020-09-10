#include<StateMachine.hh>

StateMachine::StateMachine(std::vector<AnimationState*> states)
{
    this->states = states;
}

StateMachine::~StateMachine(){}

void StateMachine::Run(float& deltaTime)
{

}