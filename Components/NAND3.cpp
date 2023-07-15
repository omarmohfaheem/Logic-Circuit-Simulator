#include "NAND3.h"

NAND3::NAND3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
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
		GraphicsInfo Yesterday;
		Yesterday.x1 = m_GfxInfo.x1 - 7;
		Yesterday.y1 = m_GfxInfo.y1 + 8;
		Yesterday.x2 = m_GfxInfo.x2;
		Yesterday.y2 = m_GfxInfo.y2;
		m_InputPins[0].setPosition(Yesterday);
		GraphicsInfo Today;
		Today.x1 = m_GfxInfo.x1 - 7;
		Today.y1 = m_GfxInfo.y1 + 25;
		Today.x2 = m_GfxInfo.x2;
		Today.y2 = m_GfxInfo.y2;
		m_InputPins[1].setPosition(Today);
		GraphicsInfo Tomorrow;
		Tomorrow.x1 = m_GfxInfo.x1 - 7;
		Tomorrow.y1 = m_GfxInfo.y1 + 41;
		Tomorrow.x2 = m_GfxInfo.x2;
		Tomorrow.y2 = m_GfxInfo.y2;
		m_InputPins[2].setPosition(Tomorrow);
}


void NAND3::Operate()
{
	//caclulate the output status as the NANDing of the three input pins
	m_OutputPin[0].setStatus((STATUS)(!(GetInputPinStatus(1) * GetInputPinStatus(2) * GetInputPinStatus(3))));
	//Add you code here
}


// Function Draw
// Draws 3-input NAND gate
void NAND3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNAND3(m_GfxInfo);
}

//returns status of outputpin
int NAND3::GetOutPinStatus()
{
	return m_OutputPin[0].getStatus();
}


//returns status of Inputpin #n
int NAND3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

Gating NAND3::getGateType()
{
	return Nand3;
}

//Set status of an input pin ot HIGH or LOW
void NAND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

