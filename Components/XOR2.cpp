#include "XOR2.h"

XOR2::XOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
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
		Yesterday.y1 = m_GfxInfo.y1  +8;
		Yesterday.x2 = m_GfxInfo.x2;
		Yesterday.y2 = m_GfxInfo.y2;
		m_InputPins[0].setPosition(Yesterday);
		GraphicsInfo Tomorrow;
		Tomorrow.x1 = m_GfxInfo.x1 - 7;
		Tomorrow.y1 = m_GfxInfo.y1 + 41;
		Tomorrow.x2 = m_GfxInfo.x2;
		Tomorrow.y2 = m_GfxInfo.y2;
		m_InputPins[1].setPosition(Tomorrow);
}


void XOR2::Operate()
{
	//caclulate the output status as the XORing of the two input pins
	m_OutputPin[0].setStatus((STATUS)((!GetInputPinStatus(1) * GetInputPinStatus(2)) + (!GetInputPinStatus(2) * GetInputPinStatus(1))));
	//Add you code here
}


// Function Draw
// Draws 2-input XOR gate
void XOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR2(m_GfxInfo);
}

//returns status of outputpin
int XOR2::GetOutPinStatus()
{
	return m_OutputPin[0].getStatus();
}


//returns status of Inputpin #n
int XOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

Gating XOR2::getGateType()
{
	return Xor2;
}

//Set status of an input pin ot HIGH or LOW
void XOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

