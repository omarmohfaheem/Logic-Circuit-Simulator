#ifndef _ACTION_H
#define _ACTION_H

class ApplicationManager; //forward class declaration

#include"..\Components\Gate.h"
#include"..\Components\Connection.h"
//Base class for all possible actions (abstract class)
class Action
{
	enum { MaxCompCount = 200 };	//Max no of Components	
	enum { Maxbattery = 5 };
	enum { Maxconnections = 100 };
protected:
	int compno=0;
	int wiresno;
	ApplicationManager* pManager;;	//Actions needs AppMngr to do their job
	Gate* Gateso[MaxCompCount];;
	Connection* Wires[Maxconnections];;
public:
	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor
	virtual void AddGate(Gate*x);
	//Reads parameters required for action to execute
	virtual void ReadActionParameters()=0;
	//Execute action (code depends on action type)
	virtual void Execute()=0;

	//To undo this action (code depends on action type)
	virtual void Undo()=0;

	//To redo this action (code depends on action type)
	virtual void Redo()=0;

};

#endif