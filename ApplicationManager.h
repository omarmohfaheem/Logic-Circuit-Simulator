#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include"../Project Code Framework/GUI/Input.h"
#include"GUI\Input.h"
#include "GUI\Output.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include"Components/Switch.h"
#include"Components/LABEL.h"
#include<fstream>
//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	
	enum { Maxbattery = 50 };
	enum { Maxconnections = 100 };
	enum { MaxGates = 100 };
	enum { MaxLabels = 100 };
private:
	int Cx, Cy;
	int CompCount;     //Actual number of Components
	int SwitchCount;
	int ConnecCount;
	int GatesCount;
	int LabelCount;
	LABEL* LabeList[MaxLabels];;
	Switch*Switilist[Maxbattery];;
	Component* CompList[MaxCompCount];;	//List of all Components (Array of pointers)
	Gate*Holder;
	Gate* CopyHolder;
	Gate* GateList[MaxGates];;
	Connection* ConnecList[Maxconnections];;
	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
public:
	ApplicationManager();
	ActionType GetUserAction();
	ActionType GetUserAction2Transfer();
	void ExecuteAction(ActionType);
	void ExecuteSimulate();
	void UpdateInterface();
	void ReadActionParametersSimulate();;
	Output* GetOutput();
	Input* GetInput();
	Switch* getSwitches();
	void AddLabel(LABEL* pLabel);
	void AddComponent(Component* pComp);
	void AddBattery(Switch*swatch);
	void Addconnection(Connection* connecto);
	void Addgates(Gate* gato);
	void connectWires();
	void OperateNow();
	void ArrangeGates();
	void SimulateCopy(int x, int y);
	void SimulateCut(int x,int y);
	void SimulatePaste();
	int getNoOfswitches();
	void Deleto(int x, int y);
	void Deletewire(int x);
	void DeletConnection(int x, int y);
	void DeleteComp(int x);
	void DeleteLabel(int x);
	void Edit_Label();
	void OperateStatement();
	ActionType Detect();
	void checkWires();
	~ApplicationManager();
};

#endif