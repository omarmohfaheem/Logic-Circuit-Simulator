#include "AND2.h"
#include <iostream>

AND2::AND2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
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
		Yesterday.x1= m_GfxInfo.x1 - 7;
		Yesterday.y1 = m_GfxInfo.y1  + 8;
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


void AND2::Operate()          //Set OutputPin Status
{
	m_OutputPin[0].setStatus((STATUS)(GetInputPinStatus(1) * GetInputPinStatus(2)));
	//caclulate the output status as the ANDing of the two input pins
	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void AND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND2(m_GfxInfo);
}

//returns status of outputpin
int AND2::GetOutPinStatus()	
{
	return m_OutputPin[0].getStatus();    //Low            //High
	
}


//returns status of Inputpin #n
int AND2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

Gating AND2::getGateType()
{
	return And2;
}

//Set status of an input pin ot HIGH or LOW
void AND2::setInputPinStatus(int n, STATUS s)		//0 or 1
{
	m_InputPins[n-1].setStatus(s);
}
