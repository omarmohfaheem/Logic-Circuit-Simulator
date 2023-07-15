#include "NOT.h"

NOT::NOT(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	GraphicsInfo now;
	now.x1 = m_GfxInfo.x1 + 55;
	now.y1 = m_GfxInfo.y1 + 25;
	now.x2 = m_GfxInfo.x2;
	now.y2 = m_GfxInfo.y2;
	m_OutputPin[0].setPosition(now);
		GraphicsInfo Today;
		Today.x1 = m_GfxInfo.x1 - 7;
		Today.y1 = m_GfxInfo.y1 + 25;
		Today.x2 = m_GfxInfo.x2;
		Today.y2 = m_GfxInfo.y2;
		m_InputPins[0].setPosition(Today);
}


void NOT::Operate()
{
	//caclulate the output status as the NOTing of the two input pins
	m_OutputPin[0].setStatus((STATUS)(!GetInputPinStatus(1)));
	//Add you code here
}


// Function Draw
// Draws NOT gate
void NOT::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOT(m_GfxInfo);
}

//returns status of outputpin
int NOT::GetOutPinStatus()
{
	return m_OutputPin[0].getStatus();
}


//returns status of Inputpin #n
int NOT::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

Gating NOT::getGateType()
{
	return Not;
}

//Set status of an input pin ot HIGH or LOW
void NOT::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
