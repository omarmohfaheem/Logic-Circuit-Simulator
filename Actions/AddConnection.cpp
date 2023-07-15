#include "AddConnection.h"
#include "..\ApplicationManager.h"
#include <iostream>

AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp)
{
}

AddConnection::~AddConnection(void)
{
}

void AddConnection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("A wire: Click to add the wire");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	pIn->GetPointClicked(Dx, Dy);
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddConnection::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	/*Calculate the rectangle Corners*/
	/*int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;*/

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
	GInfo.x1 = Cx;
	GInfo.y1 = Cy;
	GInfo.x2 = Dx;
	GInfo.y2 = Dy;
	Connection* pA = new Connection(GInfo);
	/*pManager->Test();*/
	pManager->Addconnection(pA);
	pManager->AddComponent(pA);
	pManager->OperateStatement();
	pManager->UpdateInterface();
	GraphicsInfo LabelLoc;
	LabelLoc.x1 = GInfo.x1+30;
	LabelLoc.y1 = GInfo.y1 - 15;
	LABEL* Pl = new LABEL(LabelLoc, pManager->GetInput()->GetSrting(pManager->GetOutput(), "Please Add A label for this Connection "));
	pManager->AddLabel(Pl);
}

void AddConnection::Undo()
{}

void AddConnection::Redo()
{}