#ifndef _Led_H
#define _Led_H

/*
  Class Led
  -----------
  represent the Led
*/

#include "Gate.h"

class Led :public Gate
{
public:
	Led(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the Led
	virtual void Draw(Output* pOut);	//Draws Led

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual Gating getGateType();
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	void SaveGate(ofstream& fname);

};

#endif

