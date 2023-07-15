
#include <iostream>
#include <sstream>
#include <cmath>

#include "ApplicationManager.h"
int main()
{
	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;
	//Read user action
	ActType = AppManager.GetUserAction();
	do
	{
		
		AppManager.ExecuteAction(ActType);
       //Update the drawing window
		if (ActType != TransferPoint && ActType != ADD_BACK)
			AppManager.UpdateInterface();
		if (ActType == TransferPoint  || ActType == ADD_Switch || ActType == ADD_LED || ActType == ADD_CONNECTION  || ActType == SimulateDo || ActType==DELETEC||ActType==CUT||ActType==COPY||ActType==EDIT_LABEL)
			ActType = AppManager.GetUserAction2Transfer();
		else if (ActType == ADD_BACK || ActType == ADD_Buff || ActType == ADD_NOT || ActType == ADD_AND_GATE_2 || ActType == ADD_OR_GATE_2 || ActType == ADD_XOR_GATE_3 || ActType == ADD_AND_GATE_3 || ActType == ADD_OR_GATE_3 || ActType == ADD_NAND_GATE_3 || ActType == ADD_NOR_GATE_3 || ActType == ADD_NAND_GATE_2 || ActType == ADD_NOR_GATE_2 || ActType == ADD_XOR_GATE_2 || ActType == ADD_XNOR_GATE_2)
			ActType = AppManager.GetUserAction();
	

	}while(ActType != EXIT);
	AppManager.ExecuteSimulate();
		
	return 0;
}


