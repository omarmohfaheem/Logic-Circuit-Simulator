#include "AddXNORgate2.h"
#include "..\ApplicationManager.h"

AddXNORgate2::AddXNORgate2(ApplicationManager* pApp) :Action(pApp)
{
}

AddXNORgate2::~AddXNORgate2(void)
{
}

void AddXNORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input XNOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddXNORgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.XNOR2_Width;
	int Wdth = UI.XNOR2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	XNOR2* pA = new XNOR2(GInfo, AND2_FANOUT);
	AddGate(pA);
	pManager->Addgates(pA);
	pManager->AddComponent(pA);
	pManager->UpdateInterface();
	GraphicsInfo LabelLoc;
	LabelLoc.x1 = GInfo.x1;
	LabelLoc.y1 = GInfo.y1 - 15;
	LABEL* Pl = new LABEL(LabelLoc, pManager->GetInput()->GetSrting(pManager->GetOutput(), "Please Add A label for this XNOR2 gate"));
	pManager->AddLabel(Pl);
}

void AddXNORgate2::Undo()
{}

void AddXNORgate2::Redo()
{}
