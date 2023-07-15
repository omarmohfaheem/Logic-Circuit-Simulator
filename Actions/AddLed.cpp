#include "AddLed.h"
#include "..\ApplicationManager.h"

AddLed::AddLed(ApplicationManager* pApp) :Action(pApp)
{
}

AddLed::~AddLed(void)
{
}

void AddLed::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Led: Click to add the Led");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddLed::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.Led_Width;
	int Wdth = UI.Led_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	Led* pA = new Led(GInfo, AND2_FANOUT);
	AddGate(pA);
	pManager->Addgates(pA);
	pManager->AddComponent(pA);
	pManager->UpdateInterface();
	GraphicsInfo LabelLoc;
	LabelLoc.x1 = GInfo.x1;
	LabelLoc.y1 = GInfo.y1 - 15;
	LABEL* Pl = new LABEL(LabelLoc, pManager->GetInput()->GetSrting(pManager->GetOutput(), "Please Add A label for this Led"));
	pManager->AddLabel(Pl);
}

void AddLed::Undo()
{}

void AddLed::Redo()
{}


