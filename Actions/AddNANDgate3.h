#ifndef _ADD_NAND_GATE3_H
#define _ADD_NAND_GATE3_H

#include "action.h"
#include "..\Components\NAND3.h"

class AddNANDgate3 : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddNANDgate3(ApplicationManager* pApp);
	virtual ~AddNANDgate3(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif
