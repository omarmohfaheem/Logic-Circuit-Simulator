//#include "Input.h"
#include "Output.h"
#include <iostream>

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pOut,string Req)
{
	char* Enter = new char[50];
	pWind->FlushKeyQueue();
	keytype thePress;
	int i = 0;
	pOut->PrintMsg(Req);
	while (true)
	{
		thePress = pWind->WaitKeyPress(Enter[i]);
		if (int(Enter[i]) == 8)  //Backspace
		{
			if (i > 0)
			{
				Enter[i - 1] = ' ';
				i = i - 2;                                  
				char* Holde = new char[i + 2];              //3         
				Holde[i + 1] = '\0';
				strncpy(Holde, Enter, i + 1);                 //  
				pOut->PrintMsg(Holde);
				delete Holde;
			}
			else if (i == 0)
			{
				Enter[i] = ' ';
				i = i - 1;
				pOut->PrintMsg(Req);
			}
		}
		else if (int(Enter[i]) == 27)         
		{
			for (int j = 0;j < 50;j++)
				Enter[j] = ' ';
			break;
		}
		else if (int(Enter[i]) == 13)
			break;                  
		else
		{
			char* Holde = new char[i+2];          
			Holde[i+1] = '\0';
			strncpy(Holde, Enter, i + 1);
			pOut->PrintMsg(Holde);
			delete Holde;                             
		}   
		i++;                    
	}
	char* Holde = new char[i+1];             
	Holde[i] = '\0';  
	strncpy(Holde, Enter, i);                 
	pOut->PrintMsg(Holde);
	return string(Holde);
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItemOrder)
			{
			case ITM_BUFFER:return ADD_Buff;
			case ITM_NOT:return ADD_NOT;
			case ITM_AND2: return ADD_AND_GATE_2;
			case ITM_OR2: return ADD_OR_GATE_2;
			case ITM_NAND2:return ADD_NAND_GATE_2;
			case ITM_NOR2:return ADD_NOR_GATE_2;
			case ITM_XOR2:return ADD_XOR_GATE_2;
			case ITM_AND3:return ADD_AND_GATE_3;
			case ITM_OR3:return ADD_OR_GATE_3;
			case ITM_NAND3:return ADD_NAND_GATE_3;
			case ITM_NOR3:return ADD_NOR_GATE_3;
			case ITM_XOR3:return ADD_XOR_GATE_3;
			case ITM_XNOR2:return ADD_XNOR_GATE_2;
			case ITM_TRANSFER:return TransferPoint;
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			pWind->FlushMouseQueue();
			GetUserAction();
		}

		//[3] User clicks on the status bar
		/*return STATUS_BAR;*/
	}
	//else	//Application is in Simulation mode
	//{
	//	return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	//}

}

ActionType Input::GetUserAction2Transfer() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItemOrder)
			{
			case ITM_BACK:return ADD_BACK;
			case ITM_SWITCH:return ADD_Switch;
			case ITM_LED:return ADD_LED;
			case ITM_CONNECTION:return ADD_CONNECTION;
			case Simulate:return SimulateDo;
			case Copying:return COPY;
			case Cutting:return CUT;
			case ITM_DELETE:return DELETEC;
			case ITM_LABEL:return EDIT_LABEL;
			case ITM_EXIT:return EXIT;
			default: return DSN_TOOL;

			}
		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			
			pWind->FlushMouseQueue();
			GetUserAction2Transfer();
		}

		////[3] User clicks on the status bar
		//return STATUS_BAR;
	}
	//else	//Application is in Simulation mode
	//{
	//	return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	//}

}
Input::~Input()
{
}