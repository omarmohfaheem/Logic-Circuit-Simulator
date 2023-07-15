#include "Led.h"
#include <iostream>

Led::Led(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_InputPins[0].setStatus(LOW);
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
	/////////////////////////////////////////////////////////////////////////
	
		GraphicsInfo Today;
		Today.x1 = m_GfxInfo.x1 - 10;
		Today.y1 = m_GfxInfo.y1 + 40;
		Today.x2 = m_GfxInfo.x2;
		Today.y2 = m_GfxInfo.y2;
		m_InputPins[0].setPosition(Today);
	
}


void Led::Operate()
{
	//caclulate the output status as the XORing of the three input pins
	//Add you code here
}


// Function Draw
// Draws Led
void Led::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if(m_InputPins[0].getStatus()==LOW)
	   pOut->DrawLed(m_GfxInfo);
	else if(m_InputPins[0].getStatus()==HIGH)
		pOut->DrawLedOn(m_GfxInfo);

}

//returns status of outputpin
int Led::GetOutPinStatus()
{
	return -1;
}


//returns status of Inputpin #n
int Led::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

Gating Led::getGateType()
{
	return Leder;
}

//Set status of an input pin ot HIGH or LOW
void Led::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
