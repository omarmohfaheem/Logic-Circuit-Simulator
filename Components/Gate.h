#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"

class Gate:public Component
{
protected:
	window* pWinde;
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin*m_OutputPin;	//The Gate output pin
	GraphicsInfo getOPinLocation;
	int m_Inputs;		//No. of input pins of that Gate.
public:
	Gate();
	Gate(int r_Inputs, int r_FanOut);
	OutputPin* returnOutPin();
	InputPin* returnInpin();
	int returnNoOfInputs();
	virtual GraphicsInfo getLocation();
	void SaveGate(ofstream& fname);

};

#endif
