#include "..\ApplicationManager.h"
#include "Simulation.h"
#include <iostream>

Simulation::Simulation(ApplicationManager* pApp) :Action(pApp)
{
}

Simulation::~Simulation(void)
{
}



void Simulation::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//Print Action Message
	pOut->PrintMsg("Simulate: Click to Simulate the battery");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Simulation::Execute()
{
	pManager->ExecuteSimulate();
	pManager->connectWires();
}

GraphicsInfo Simulation::GetOutpinPostion()
{
	GraphicsInfo getOut;
	getOut.x1 = Cx - UI.AND2_Width;
	getOut.y1 = Cy - UI.AND2_Width / 2;
	return getOut;
}

void Simulation::Undo()
{}

void Simulation::Redo()
{}

