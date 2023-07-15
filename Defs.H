#ifndef CONST_H
#define CONST_H
//This header file contains some defenitions to be used all over the application

//All possible actions
enum ActionType
{
	ADD_Buff,			//Add 1-input Buffer gate
	ADD_NOT,			//Add 1-input Inverter gate
	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_OR_GATE_2,		//Add 2-input OR gate
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
	TransferPoint,
	ADD_AND_GATE_3,		//Add 3-input AND gate
	ADD_OR_GATE_3,
	ADD_NOR_GATE_3,		//Add 3-input NOR gate
	ADD_XOR_GATE_3,		//Add 3-input XOR gate
	ADD_NAND_GATE_3,
	ADD_Switch,			//Add Switch
	ADD_LED,			//Add LED
	ADD_BACK,
	ADD_CONNECTION,//Add Wire Connection
	CheckOutside,
	DELETEC,
	switcho_off,
	switcho_on,
    ADD_Label,			//Add Label to a Component, a Connection
	EDIT_LABEL,			//Edit Label of a Component, a Connection
	SimulateDo,
	Create_TruthTable,	//Create Truth Table of the Circuit
	CUT,
	COPY,
	Change_Switch,		//Change Switch Status in Simulation Mode

	SELECT,		//Select a Component, a Connection
	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file

	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode

	EXIT,		//Exit the application

	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar

};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH
};

//enum SWITCHSTATUS
//{
//	LOW,
//	HIGH
//};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};

enum Gating
{
	Buffer,
	Not,
	And2,
	Or2,
	Nand2,
	Nor2,
	Xor2,
	Xnor2,
	And3,
	Or3,
	Nand3,
	Nor3,
	Xor3,
	Switcher,
	Leder
};
enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_BUFFER,                                  //0
	ITM_NOT,//1        
	ITM_AND2,	//2	//AND gate item in menu
	ITM_OR2,    //3   //OR gate item in menu
	ITM_NAND2,
	ITM_NOR2,
	ITM_XOR2,
	ITM_XNOR2,
	ITM_AND3,
	ITM_OR3,
	ITM_NAND3,
	ITM_NOR3,
	ITM_XOR3,
	ITM_TRANSFER,
	ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum
};
enum DsgnMenuItem2
{
	ITM_BACK,
	ITM_LED,
	ITM_SWITCH,
	ITM_CONNECTION,
	Simulate,
	Cutting,
	Copying,
	ITM_DELETE,
	ITM_LABEL,
	ITM_EXIT,
	ITM_DSN_CNT2
};
#define MAX_CONNS 20
enum FANOUT
{
	AND2_FANOUT = 5	//Default fan out of 2-input AND gate
};

//A structure to contain drawing parameters for each component
//Each component occupies a rectangluar area so it needs 2 points to represent that area
//this structure can be extended if desired
struct GraphicsInfo
{
	int x1,y1, x2, y2;
};


#ifndef NULL
#define NULL 0
#endif

#endif