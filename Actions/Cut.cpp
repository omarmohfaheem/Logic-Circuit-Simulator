#include "Cut.h"
#include "..\ApplicationManager.h"

Cut::Cut(ApplicationManager* pApp) :Action(pApp)
{
}

Cut::~Cut(void)
{
}

void Cut::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//Print Action Message
	pOut->PrintMsg("Cut Operation : Click to Cut the Gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}


void Cut::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	pManager->SimulateCut(Cx,Cy);
	pManager->SimulatePaste();
}

void Cut::Undo()
{}

void Cut::Redo()
{}
