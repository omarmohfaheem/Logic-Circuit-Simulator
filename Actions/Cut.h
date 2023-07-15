#pragma once
#include "action.h"


class Cut : public Action
{
private:
	
	int Cx, Cy;
	int x1, y1, x2, y2;	
public:
	Cut(ApplicationManager* pApp);
	virtual ~Cut(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();


};

