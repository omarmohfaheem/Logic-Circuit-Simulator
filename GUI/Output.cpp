#include "Output.h"
#include <iostream>

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;

	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
void Output::Returnoreno(ActionType X)
{
	if (X == TransferPoint)
	{
		CreateDesignToolBar2();
	}
	if (X == ADD_BACK)
		CreateDesignToolBar();
}
void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	int midx = (r_GfxInfo.x1 + r_GfxInfo.x2) / 2;
	int midy = (r_GfxInfo.y1 + r_GfxInfo.y2) / 2;
	int dist = abs(r_GfxInfo.y1 - r_GfxInfo.y2);
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, midx, r_GfxInfo.y1);
	pWind->DrawLine(midx, r_GfxInfo.y1, midx, r_GfxInfo.y2);
	pWind->DrawLine(midx, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
}

//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_BUFFER] = "final\\gates\\buffer.jpeg";
	MenuItemImages[ITM_NOT] = "final\\gates\\not.jpeg";
	MenuItemImages[ITM_AND2] = "final\\gates\\and2.jpeg";
	MenuItemImages[ITM_OR2] = "final\\gates\\or2.jpeg";
	MenuItemImages[ITM_NAND2] = "final\\gates\\nand2.jpeg";
	MenuItemImages[ITM_NOR2] = "final\\gates\\nor2.jpeg";
	MenuItemImages[ITM_XOR2] = "final\\gates\\xor2.jpeg";
	MenuItemImages[ITM_XNOR2] = "final\\gates\\xnor2.jpeg";
	MenuItemImages[ITM_AND3] = "final\\gates\\and3.jpeg";
	MenuItemImages[ITM_OR3] = "final\\gates\\or3.jpeg";
	MenuItemImages[ITM_NAND3] = "final\\gates\\nand3.jpeg";
	MenuItemImages[ITM_NOR3] = "final\\gates\\nor3.jpeg";
	MenuItemImages[ITM_XOR3] = "final\\gates\\xor3.jpeg";
	MenuItemImages[ITM_TRANSFER] = "images\\Menu\\upanddown.jpg";
	for (int i = 0; i < ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
void Output::CreateDesignToolBar2() const
{
	UI.AppMode = DESIGN;	//Design Mode
	string MenuItemImages[ITM_DSN_CNT2];
	MenuItemImages[ITM_BACK] = "images\\Menu\\BAKK.jpg";
	MenuItemImages[ITM_LED] = "images\\Menu\\led_off.jpg";
	MenuItemImages[ITM_SWITCH] = "final\\inactive2\\switch.jpg";
	MenuItemImages[ITM_CONNECTION] = "final\\inactive2\\wire.jpg";
	MenuItemImages[Simulate] = "final\\inactive2\\tool.jpg";
	MenuItemImages[Copying] = "final\\inactive2\\Copy.jpg";
	MenuItemImages[Cutting] = "final\\inactive2\\cutin.jpg";
	MenuItemImages[ITM_DELETE] = "final\\inactive2\\delete.jpg";
	MenuItemImages[ITM_LABEL] = "final\\inactive2\\pencil.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";
	for (int i = 0; i < ITM_DSN_CNT2; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)


}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//
void Output::DrawBUFFER(GraphicsInfo r_GfxInfo, bool selected) const
{
	pWind->SetPen(BROWN, 10);
	pWind->DrawCircle(r_GfxInfo.x1 + 55, r_GfxInfo.y1 + 25, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 25, 8);
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "final\\inactive2\\buffer.jpg";
	else
		GateImage = "final\\inactive2\\buffer.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.Buffer_Width, UI.Buffer_Height);
}
void Output::DrawNOT(GraphicsInfo r_GfxInfo, bool selected) const
{
	pWind->SetPen(BROWN, 10);
	pWind->DrawCircle(r_GfxInfo.x1 + 55, r_GfxInfo.y1 + 25, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 25, 8);
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "final\\inactive2\\not.jpg";
	else
		GateImage = "final\\inactive2\\not.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOT_Width, UI.NOT_Height);
}
void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	pWind->SetPen(BROWN, 10);
	pWind->DrawCircle(r_GfxInfo.x1+55, r_GfxInfo.y1+25, 8);
	pWind->DrawCircle(r_GfxInfo.x1-7, r_GfxInfo.y1+8, 8);
	pWind->DrawCircle(r_GfxInfo.x1-7, r_GfxInfo.y1+41, 8);
	cout << r_GfxInfo.x1 + 55 << "GO" << endl;
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "final\\inactive2\\and.jpg";
	else
		GateImage = "final\\inactive2\\and.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	pWind->SetPen(BROWN, 10);
	pWind->DrawCircle(r_GfxInfo.x1 + 55, r_GfxInfo.y1 + 25, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 8, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 41, 8);
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "final\\inactive2\\or.jpg";
	else
		GateImage = "final\\inactive2\\or.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}

void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	pWind->SetPen(BROWN, 10);
	pWind->DrawCircle(r_GfxInfo.x1 + 55, r_GfxInfo.y1 + 25, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 8, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 41, 8);
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "final\\inactive2\\nand.jpg";
	else
		GateImage = "final\\inactive2\\nand.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}

void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	pWind->SetPen(BROWN, 10);
	pWind->DrawCircle(r_GfxInfo.x1 + 55, r_GfxInfo.y1 + 25, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 8, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 41, 8);
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "final\\inactive2\\nor.jpg";
	else
		GateImage = "final\\inactive2\\nor.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR2_Width, UI.NOR2_Height);
}

void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	pWind->SetPen(BROWN, 10);
	pWind->DrawCircle(r_GfxInfo.x1 + 55, r_GfxInfo.y1 + 25, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 8, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 41, 8);
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "final\\inactive2\\xor.jpg";
	else
		GateImage = "final\\inactive2\\xor.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR2_Width, UI.XOR2_Height);
}

void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	pWind->SetPen(BROWN, 10);
	pWind->DrawCircle(r_GfxInfo.x1 + 55, r_GfxInfo.y1 + 25, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 8, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 25, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 41, 8);
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "final\\inactive2\\xor3.jpg";
	else
		GateImage = "final\\inactive2\\xor3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR2_Width, UI.XOR2_Height);
}

void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	pWind->SetPen(BROWN, 10);
	pWind->DrawCircle(r_GfxInfo.x1 + 55, r_GfxInfo.y1 + 25, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 8, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 41, 8);
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "final\\inactive2\\xnor.jpg";
	else
		GateImage = "final\\inactive2\\xnor.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XNOR2_Width, UI.XNOR2_Height);
}

void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	pWind->SetPen(BROWN, 10);
	pWind->DrawCircle(r_GfxInfo.x1 + 55, r_GfxInfo.y1 + 25, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 8, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 25, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 41, 8);
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "final\\inactive2\\and3.jpg";
	else
		GateImage = "final\\inactive2\\and3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND3_Width, UI.AND3_Height);
}

void Output::DrawOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	pWind->SetPen(BROWN, 10);
	pWind->DrawCircle(r_GfxInfo.x1 + 55, r_GfxInfo.y1 + 25, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 8, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 25, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 41, 8);
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "final\\inactive2\\or3.jpg";
	else
		GateImage = "final\\inactive2\\or3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR3_Width, UI.OR3_Height);
}

void Output::DrawNAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	pWind->SetPen(BROWN, 10);
	pWind->DrawCircle(r_GfxInfo.x1 + 55, r_GfxInfo.y1 + 25, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 8, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 25, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 41, 8);
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "final\\inactive2\\nand3.jpg";
	else
		GateImage = "final\\inactive2\\nand3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND3_Width, UI.NAND3_Height);
}

void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	pWind->SetPen(BROWN, 10);
	pWind->DrawCircle(r_GfxInfo.x1 + 55, r_GfxInfo.y1 + 25, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 8, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 25, 8);
	pWind->DrawCircle(r_GfxInfo.x1 - 7, r_GfxInfo.y1 + 41, 8);
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "final\\inactive2\\nor3.jpg";
	else
		GateImage = "final\\inactive2\\nor3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR3_Width, UI.NOR3_Height);
}

void Output::DrawSwitch(GraphicsInfo r_GfxInfo, bool selected) const
{
	pWind->SetPen(BROWN, 10);
	pWind->DrawCircle(r_GfxInfo.x1 + 55, r_GfxInfo.y1 + 25, 8);
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "final\\inactive2\\switch_off.jpg";
	else
		GateImage = "final\\inactive2\\switch_off.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.Switch_Width, UI.Switch_Height);
}

void Output::DrawSwitchon(GraphicsInfo r_GfxInfo, bool selected) const
{
	pWind->SetPen(BROWN, 10);
	pWind->DrawCircle(r_GfxInfo.x1 + 55, r_GfxInfo.y1 + 25, 8);
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "final\\active\\switch_on.jpg";
	else
		GateImage = "final\\active\\switch_on.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.Switch_Width, UI.Switch_Height);
}

void Output::DrawLed(GraphicsInfo r_GfxInfo, bool selected) const
{
	pWind->SetPen(BROWN, 10);
	pWind->DrawCircle(r_GfxInfo.x1-10, r_GfxInfo.y1 + 40, 8);
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "final\\inactive2\\led_off.jpg";
	else
		GateImage = "final\\inactive2\\led_off.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.Led_Width, UI.Led_Height);
}
void Output::DrawLedOn(GraphicsInfo r_GfxInfo, bool selected) const
{
	pWind->SetPen(BROWN, 10);
	pWind->DrawCircle(r_GfxInfo.x1 - 10, r_GfxInfo.y1 + 40, 8);
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "final\\active\\led_on.jpg";
	else
		GateImage = "final\\active\\led_on.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.Led_Width, UI.Led_Height);
}

void Output::DrawLabel(GraphicsInfo r_GfxInfo,string x)
{
	pWind->SetFont(20, BOLD | PLAIN, BY_NAME, "Arial");
	pWind->SetPen(BLACK);
	pWind->DrawString(r_GfxInfo.x1 - 15, r_GfxInfo.y1 -10, x);
}

//TODO: Add similar functions to draw all components

Output::~Output()
{
	delete pWind;
}
