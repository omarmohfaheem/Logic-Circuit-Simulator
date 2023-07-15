#include "Gate.h"

Gate::Gate()
{
}

Gate::Gate(int r_Inputs, int r_FanOut)
{
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;
	m_OutputPin = new OutputPin[1];
	for(int i=0; i<m_Inputs; i++)
		m_InputPins[i].setComponent(this);             
}				 

OutputPin* Gate::returnOutPin()
{
	return m_OutputPin;
}

InputPin* Gate::returnInpin()
{
	return m_InputPins;
}

int Gate::returnNoOfInputs()
{
	return m_Inputs;
}

GraphicsInfo Gate::getLocation()
{
	return m_GfxInfo;
}