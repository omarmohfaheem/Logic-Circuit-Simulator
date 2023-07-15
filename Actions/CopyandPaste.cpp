#include "CopyandPaste.h"
#include "..\ApplicationManager.h"

CopyandPaste::CopyandPaste(ApplicationManager* pApp) :Action(pApp)
{
}

CopyandPaste::~CopyandPaste(void)
{
}

void CopyandPaste::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//Print Action Message
	pOut->PrintMsg("Copy Operation : Click to copy the Component");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}


void CopyandPaste::Execute()
{
	ReadActionParameters();
	pManager->SimulateCopy(Cx, Cy);     //Holder=Gate
	pManager->SimulatePaste();
}


void CopyandPaste::Undo()
{}

void CopyandPaste::Redo()
{}
