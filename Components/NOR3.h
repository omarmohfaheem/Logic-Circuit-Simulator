#ifndef _NOR3_H
#define _NOR3_H

/*
  Class NOR3
  -----------
  represent the 3-input NOR gate
*/

#include "Gate.h"

class NOR3 :public Gate
{
public:
	NOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the NOR2 gate
	virtual void Draw(Output* pOut);	//Draws 2-input NOR gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual Gating getGateType();
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	void SaveGate(ofstream& fname);

};

#endif


