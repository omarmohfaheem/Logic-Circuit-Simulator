#include "AddANDgate2.h"
#include "..\ApplicationManager.h"

AddANDgate2::AddANDgate2(ApplicationManager *pApp):Action(pApp)
{
}

AddANDgate2::~AddANDgate2(void)
{
}

void AddANDgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//Print Action Message
	pOut->PrintMsg("2-Input AND Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void AddANDgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	
	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
	
	GInfo.x1 = Cx - Len/2;
	GInfo.x2 = Cx + Len/2;
	GInfo.y1 = Cy - Wdth/2;
	GInfo.y2 = Cy + Wdth/2;
	AND2 *pA=new AND2(GInfo, AND2_FANOUT);
	x = pA;
	AddGate(pA);
	pManager->Addgates(pA);
	pManager->AddComponent(pA); 
	pManager->UpdateInterface();
	GraphicsInfo LabelLoc;
	LabelLoc.x1 = GInfo.x1;
	LabelLoc.y1 = GInfo.y1 - 15;
	LABEL* Pl = new LABEL(LabelLoc,pManager->GetInput()->GetSrting(pManager->GetOutput(),"Please Add A label for this And2 gate"));
	pManager->AddLabel(Pl);
}

GraphicsInfo AddANDgate2::GetOutpinPostion()
{
	GraphicsInfo getOut;
	getOut.x1=Cx- UI.AND2_Width;
	getOut.y1=Cy- UI.AND2_Width/2;
	return getOut;
}

GraphicsInfo AddANDgate2::GetInpinPostion()
{
	GraphicsInfo getIn;
	getIn.x1 = Cx;
	getIn.y1 = Cy - UI.AND2_Width / 2;
	return getIn;
}

void AddANDgate2::Undo()
{}

void AddANDgate2::Redo()
{}

