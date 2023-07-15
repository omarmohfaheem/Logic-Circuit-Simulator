#ifndef _Simulation_H
#define _Simulation_H

#include "action.h"
#include "..\Components\Switch.h"

class Simulation : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	Switch*x;
public:
	Simulation(ApplicationManager* pApp);
	virtual ~Simulation(void);
	void transfer();
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual GraphicsInfo GetOutpinPostion();
	virtual void Undo();
	virtual void Redo();


};
#endif
