#include "ApplicationManager.h"
#include "Actions/AddANDgate2.h"
#include"Actions/AddBUFFERgate.h"
#include"Actions/AddORgate2.h"
#include"Actions/AddANDgate3.h"
#include"Actions/AddLed.h"
#include"Actions/AddNANDgate2.h"
#include"Actions/AddNANDgate3.h"
#include"Actions/AddNORgate2.h"
#include"Actions/AddNORgate3.h"
#include"Actions/AddNOTgate.h"
#include"Actions/AddORgate3.h"
#include"Actions/AddSwitch.h"
#include"Actions/AddXNORgate2.h"
#include"Actions/AddXORgate2.h"
#include"Actions/AddXORgate3.h"
#include"Actions/AddConnection.h"
#include"Actions/Simulation.h"
#include"Actions/Delete.h"
#include"Actions/Cut.h"
#include"Actions/CopyandPaste.h"
#include <iostream>


ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	SwitchCount = 0;
	ConnecCount = 0;
	GatesCount = 0;
	LabelCount = 0;
	for (int i = 0;i < MaxLabels;i++)
		LabeList[i] = NULL;
	for (int i = 0; i < MaxCompCount; i++)
		CompList[i] = NULL;
	for (int i = 0; i < Maxconnections; i++)
		ConnecList[i] = NULL;
	for (int i = 0; i < MaxGates; i++)
		GateList[i] = NULL;
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;
}
void ApplicationManager::AddBattery(Switch* swatch)
{
	Switilist[SwitchCount++] = swatch;
}
void ApplicationManager::Addconnection(Connection* connecto)
{
	ConnecList[ConnecCount++] = connecto;
}
void ApplicationManager::Addgates(Gate* gato)
{
	GateList[GatesCount++] = gato;
	OperateStatement();
}
void ApplicationManager::connectWires()
{
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	for (i = 0;i < ConnecCount;i++)
	{
		for (k = 0;k < GatesCount;k++)
		{
			for (l = 0;l < GateList[k]->returnNoOfInputs();l++)
			{
				if (abs(ConnecList[i]->geta().x2 - (GateList[k]->returnInpin() + l)->getPosition().x1) <= 10 && abs(ConnecList[i]->geta().y2 - (GateList[k]->returnInpin() + l)->getPosition().y1) <= 10)
				{
					ConnecList[i]->setDestPin(GateList[k]->returnInpin() + l);
					GateList[k]->setInputPinStatus(l + 1, (STATUS)ConnecList[i]->GetOutPinStatus());
				}
			}
		}
		for (j = 0;j < GatesCount;j++)
		{
			if (abs(ConnecList[i]->geta().x1 - GateList[j]->returnOutPin()->getPosition().x1) <= 10 && abs(ConnecList[i]->geta().y1 - GateList[j]->returnOutPin()->getPosition().y1) <= 10)
			{
				ConnecList[i]->setSourcePin(*(GateList[j])->returnOutPin());
				ConnecList[i]->Operate();
			}
		}
	}
}

void ApplicationManager::OperateNow()
{
	ArrangeGates();
	int i = 0, j = 0;
	for (i = 0;i < GatesCount;i++)
	{
		GateList[i]->Operate();
	}
}

void ApplicationManager::ArrangeGates()
{
	int i = 0, j = 0;
	for (i = 0;i < GatesCount;i++)
	{
		for (j = i;j < GatesCount;j++)
		{
			if (GateList[i]->getLocation().x1 >= GateList[j]->getLocation().x1)
			{
				Gate* temp;
				temp = GateList[i];
				GateList[i] = GateList[j];
				GateList[j] = temp;
			}
		}
	}
}
void ApplicationManager::SimulateCopy(int x, int y)
{
	for (int i = 0;i < GatesCount;i++)        //GraphicsInfo   x1,y1,x2,y2
	{
		if (x - GateList[i]->getLocation().x1 >= 0 && x - GateList[i]->getLocation().x1 <= 51 && y - GateList[i]->getLocation().y1 >= 0 && y - GateList[i]->getLocation().y1 <= 51)
		{
			Holder = GateList[i];
		}
	}
}
void ApplicationManager::SimulateCut(int x, int y)
{
	for (int i = 0;i < GatesCount;i++)
	{
		if (x - GateList[i]->getLocation().x1 >= 0 && x - GateList[i]->getLocation().x1 <= 51 && y - GateList[i]->getLocation().y1 >= 0 && y - GateList[i]->getLocation().y1 <= 51)
		{
			Holder = GateList[i];
			for (int s = 0;s < ConnecCount;s++)       
			{
				for (int k = 0;k < Holder->returnNoOfInputs();k++)       //k=2      0 1 
				{
					if (abs(ConnecList[s]->geta().x2 - (Holder->returnInpin() + k)->getPosition().x1) <= 10 && abs(ConnecList[s]->geta().y2 - (Holder->returnInpin() + k)->getPosition().y1)<=10)
					{
						DeletConnection(ConnecList[s]->geta().x2, ConnecList[s]->geta().y2);
						OutputInterface->ClearDrawingArea();
						UpdateInterface();
					}
				}
			}
			for (int s = 0;s < ConnecCount;s++)
			{
				int f = ConnecList[s]->geta().x1;
				if (abs(ConnecList[s]->geta().x1 - Holder->returnOutPin()->getPosition().x1) <= 10 && abs(ConnecList[s]->geta().y1 - Holder->returnOutPin()->getPosition().y1) <= 10)
				{
					((ConnecList[s]->getDestPin()->setStatus(LOW)));
					DeletConnection(ConnecList[s]->geta().x1, ConnecList[s]->geta().y1);
					OutputInterface->ClearDrawingArea();
					UpdateInterface();
				}
			}
			Deleto(x, y);
			OperateStatement();
		}
	}
}
void ApplicationManager::SimulatePaste()
{
	ExecuteAction(Detect());
}
int ApplicationManager::getNoOfswitches()
{
	return SwitchCount;
}
void ApplicationManager::Deleto(int x, int y)
{
	int i = 0;
	for (i = 0;i < SwitchCount;i++)
	{
		if (x - Switilist[i]->getLocation().x1 >= 0 && x - Switilist[i]->getLocation().x1 <= 51 && y - Switilist[i]->getLocation().y1 >= 0 && y - Switilist[i]->getLocation().y1 <= 51)
		{
			Switilist[i] = Switilist[SwitchCount - 1];
			Switilist[SwitchCount - 1] = NULL;
			SwitchCount--;
		}
	}
	for (i = 0;i < GatesCount;i++)
	{
		if(x - GateList[i]->getLocation().x1>=0 && x - GateList[i]->getLocation().x1 <= 51 && y - GateList[i]->getLocation().y1 >= 0 && y - GateList[i]->getLocation().y1 <= 51)
		{
			GateList[i] = GateList[GatesCount - 1];
			GateList[GatesCount - 1] = NULL;
			GatesCount--;
		}
	}
	for (i = 0;i < CompCount;i++)
	{
		if (x - CompList[i]->geta().x1 >= 0 && x - CompList[i]->geta().x1 <= 51 && y - CompList[i]->geta().y1 >= 0 && y - CompList[i]->geta().y1 <= 51)
		{
			DeleteComp(i);
		}
	}
	DeletConnection(x, y);
}
void ApplicationManager::Deletewire(int x)
{
	((ConnecList[x]->getDestPin()->setStatus(LOW)));
	for (int j = 0;j < CompCount;j++)
	{
		if (ConnecList[x] == CompList[j])
		{
			DeleteComp(j);
		}
	}
	ConnecList[x] = ConnecList[ConnecCount - 1];
	ConnecList[ConnecCount - 1] = NULL;
	ConnecCount--;
	OutputInterface->ClearDrawingArea();
}
void ApplicationManager::DeletConnection(int x, int y)
{
	for (int i = 0;i < ConnecCount;i++)
	{
		int midx = (ConnecList[i]->geta().x1 + ConnecList[i]->geta().x2) / 2;
		int midy = (ConnecList[i]->geta().y1 + ConnecList[i]->geta().y2) / 2;
		int dist = abs(ConnecList[i]->geta().y1 - ConnecList[i]->geta().y2);
		if (x >= ConnecList[i]->geta().x1 && x <= midx && abs(ConnecList[i]->geta().y1 - y) < 15)
		{
			Deletewire(i);
		}
		else if (abs(x - midx) <= 15 && abs(ConnecList[i]->geta().y2 - y) <= dist && abs(ConnecList[i]->geta().y1 - y) <= dist)
		{
			Deletewire(i);
		}
		else if (x >= midx && x <= ConnecList[i]->geta().x2 && abs(y - ConnecList[i]->geta().y2) <= 15)
		{
			Deletewire(i);
		}
	}
	OperateStatement();
	UpdateInterface();
}
void ApplicationManager::DeleteComp(int x)
{
	DeleteLabel(x);
	Component* Temp;
	Temp = CompList[x];
	CompList[x]= CompList[CompCount - 1];
	CompList[CompCount - 1] = Temp;
	/*CompList[x] = CompList[CompCount - 1];
	CompList[CompCount - 1] = NULL;*/
	CompCount--;
	OutputInterface->ClearDrawingArea();
	UpdateInterface();
}
void ApplicationManager::DeleteLabel(int x)
{
	for (int i = 0;i < LabelCount;i++)
	{
		if (abs(LabeList[i]->retLabeLocation().x1 - CompList[x]->geta().x1) <= 30 && abs(LabeList[i]->retLabeLocation().y1 - CompList[x]->geta().y1) <= 50)
		{
			LABEL* Tempo;
			LabeList[i] = LabeList[LabelCount - 1];
			LabeList[LabelCount - 1] = NULL;
			LabelCount--;
		}
	}
	OutputInterface->ClearDrawingArea();
	UpdateInterface();
}
void ApplicationManager::Edit_Label()
{
	OutputInterface->PrintMsg("Edit The Label");
	InputInterface->GetPointClicked(Cx, Cy);
	OutputInterface->ClearStatusBar();
	int s;
	for (int j = 0;j < CompCount;j++)
	{
		if (abs(Cx - CompList[j]->geta().x1) <= 50 && abs(Cy - CompList[j]->geta().y1) <= 50)
		{
			s = j;
			break;
		}
	}
	for (int i = 0;i < LabelCount;i++)
	{
		if (abs(LabeList[i]->retLabeLocation().x1 - Cx) <= 50 && abs(LabeList[i]->retLabeLocation().y1 - Cy) <= 60)
		{
			DeleteLabel(s);
			UpdateInterface();
		}
	}
	UpdateInterface();
	GraphicsInfo LabelLoc;
	LabelLoc.x1 = CompList[s]->geta().x1;
	LabelLoc.y1 = CompList[s]->geta().y1-15;
	LABEL* Pl = new LABEL(LabelLoc, GetInput()->GetSrting(GetOutput(), "Please Add A new label for this Component"));
	AddLabel(Pl);
	UpdateInterface();
}
void ApplicationManager::OperateStatement()
{
	for (int i = 0;i < 7;i++)
	{
		connectWires();
		OperateNow();
	}
}
ActionType ApplicationManager::Detect()
{
	Gating Nano = Holder->getGateType();
	switch (Nano)
	{
	case Buffer:
		return ADD_Buff;
		break;
	case Not:
		return ADD_NOT;
		break;
	case And2:
		return ADD_AND_GATE_2;
		break;
	case Or2:
		return ADD_OR_GATE_2;
		break;
	case Nand2:
		return ADD_NAND_GATE_2;
		break;
	case Nor2:
		return ADD_NOR_GATE_2;
		break;
	case Xor2:
		return ADD_XOR_GATE_2;
		break;
	case Xnor2:
		return ADD_XNOR_GATE_2;
		break;
	case And3:
		return ADD_AND_GATE_3;
		break;
	case Or3:
		return ADD_OR_GATE_3;
		break;
	case Nand3:
		return ADD_NAND_GATE_3;
		break;
	case Nor3:
		return ADD_NOR_GATE_3;
		break;
	case Xor3:
		return ADD_XOR_GATE_3;
		break;
	case Leder:
		return ADD_LED;
		break;
	case Switcher:
		return ADD_Switch;
		break;
	}
}
void ApplicationManager::checkWires()
{
	int i = 0;
	connectWires();
	for (i = 0;i < ConnecCount;i++)
	{
		/*cout << "Wire no." << i + 1 << endl;
		cout << "Inputpin Status wire : "<< ConnecList[i]->getSourcePin()->getStatus() << endl;
		cout << "Outputpin of the wire : " <<ConnecList[i]->getDestPin()->getPosition().x1 << endl;*/
	}
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction();
}
ActionType ApplicationManager::GetUserAction2Transfer()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction2Transfer();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	pAct = NULL;
	switch (ActType)
	{
	case ADD_Buff:
		pAct = new AddBUFFERgate(this);
		break;

	case ADD_AND_GATE_2:
		pAct = new AddANDgate2(this);
		break;

	case ADD_OR_GATE_2:
		pAct = new AddORgate2(this);
		break;

	case ADD_NOT:
		pAct = new AddNOTgate(this);
		break;

	case ADD_BACK:
		OutputInterface->Returnoreno(ADD_BACK);
		break;
	case ADD_NOR_GATE_2:
		pAct = new AddNORgate2(this);
		break;

	case ADD_NAND_GATE_2:
		pAct = new AddNANDgate2(this);
		break;

	case ADD_XOR_GATE_2:
		pAct = new AddXORgate2(this);
		break;

	case ADD_XNOR_GATE_2:
		pAct = new AddXNORgate2(this);
		break;

	case ADD_AND_GATE_3:
		pAct = new AddANDgate3(this);
		break;
	case ADD_XOR_GATE_3:
		pAct = new AddXORgate3(this);
		break;
	case ADD_OR_GATE_3:
		pAct = new AddORgate3(this);
		break;
	case COPY:
		pAct = new CopyandPaste(this);
		break;
	case CUT:
		pAct = new Cut(this);
		break;
	case ADD_NAND_GATE_3:
		pAct = new AddNANDgate3(this);
		break;

	case ADD_NOR_GATE_3:
		pAct = new AddNORgate3(this);
		break;

	case ADD_Switch:
		pAct = new AddSwitch(this);
		break;
	case SimulateDo:
		pAct = new Simulation(this);
		break;
	case ADD_LED:
		pAct = new AddLed(this);
		break;
	case TransferPoint:
		OutputInterface->Returnoreno(TransferPoint);
		break;
	case ADD_CONNECTION:
		pAct = new AddConnection(this);
		break;
	case DELETEC:
		pAct = new Delete(this);
		break;
	case EDIT_LABEL:
		Edit_Label();
	case EXIT:
		break;
	}
	if (pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
void ApplicationManager::ExecuteSimulate()
{
	GraphicsInfo sima;
	ReadActionParametersSimulate();
	for (int i = 0;i < getNoOfswitches();i++)
	{
		if (abs(Switilist[i]->getcomponentPosition().x1 - Cx) <= 50 && abs(Switilist[i]->getcomponentPosition().y1 - Cy) <= 50)
		{
			Switilist[i]->SetOutPinStatus();
			OperateStatement();
			sima.x1 = Switilist[i]->getcomponentPosition().x1;
			sima.x2 = Switilist[i]->getcomponentPosition().x2;
			sima.y1 = Switilist[i]->getcomponentPosition().y1;
			sima.y2 = Switilist[i]->getcomponentPosition().y2;
			Switch* pA = new Switch(sima, AND2_FANOUT);
		}
	}
}
void ApplicationManager::UpdateInterface()
{
	for (int i = 0; i < CompCount; i++)
		CompList[i]->Draw(OutputInterface);
	for (int i = 0; i < SwitchCount; i++)
		Switilist[i]->Draw(OutputInterface);
	for (int i = 0;i < LabelCount;i++)
		LabeList[i]->Draw(OutputInterface);
}

void ApplicationManager::ReadActionParametersSimulate()
{
	Output* pOut = GetOutput();
	Input* pIn = GetInput();
	pOut->PrintMsg("Simulate: Click to Simulate the battery");
	pIn->GetPointClicked(Cx, Cy);
	pOut->ClearStatusBar();
}

Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

Switch* ApplicationManager::getSwitches()
{
	return *Switilist;
}

void ApplicationManager::AddLabel(LABEL* pLabel)
{
	LabeList[LabelCount++] = pLabel;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < CompCount; i++)
		delete CompList[i];
	for (int i = 0;i < ConnecCount;i++)
		delete ConnecList[i];
	for (int i = 0;i < SwitchCount;i++)
		delete Switilist[i];
	for (int i = 0;i < GatesCount;i++)
		delete GateList[i];
	delete OutputInterface;
	delete InputInterface;

}