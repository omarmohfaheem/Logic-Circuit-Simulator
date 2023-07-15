#ifndef _OR3_H
#define _OR3_H

/*
  Class OR3
  -----------
  represent the 3-input OR gate
*/

#include "Gate.h"

class OR3 :public Gate
{
public:
	OR3(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the OR3 gate
	virtual void Draw(Output* pOut);	//Draws 3-input OR gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual Gating getGateType();
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	void SaveGate(ofstream& fname);

};

#endif

