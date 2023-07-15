#include "InputPin.h"

InputPin::InputPin()
{}

void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;   // this component 
}

Component* InputPin::getComponent()
{
	return pComp;
}