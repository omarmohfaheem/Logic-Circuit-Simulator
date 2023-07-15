#include "AddSwitch.h"
#include "..\ApplicationManager.h"



AddSwitch::AddSwitch(ApplicationManager* pApp) :Action(pApp)
{
}

AddSwitch::~AddSwitch(void)
{
}

void AddSwitch::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Switch: Click to add the Switch");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddSwitch::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.Switch_Width;
	int Wdth = UI.Switch_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	Switch* pA = new Switch(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
	pManager->AddBattery(pA);
	AddGate(pA);
	pManager->Addgates(pA);
	pManager->UpdateInterface();
	GraphicsInfo LabelLoc;
	LabelLoc.x1 = GInfo.x1;
	LabelLoc.y1 = GInfo.y1 - 15;
	LABEL* Pl = new LABEL(LabelLoc, pManager->GetInput()->GetSrting(pManager->GetOutput(), "Please Add A label for this Switch"));
	pManager->AddLabel(Pl);
}


void AddSwitch::Undo()
{}

void AddSwitch::Redo()
{}


