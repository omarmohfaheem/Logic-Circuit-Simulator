#pragma once
#include"..\Defs.H"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include"..\GUI\Input.h"
#include "..\GUI\Output.h"
//#include"..\ApplicationManager.h"
class LABEL
{
private:
	GraphicsInfo m_GfxInfo;
	string Labelo;
	Input* InputLabel;;
	Output* pOut;;
public:
	LABEL(GraphicsInfo r_GfxInfo, string Labele);
	void Draw(Output*Outo);
	GraphicsInfo retLabeLocation();
	void setLabel();
	void SaveGate(ofstream& fname);
};

