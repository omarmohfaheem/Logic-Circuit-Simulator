#include "Switch.h"

Switch::Switch()
{
}

Switch::Switch(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(0, r_FanOut)
{
	m_OutputPin->setStatus(LOW);
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
}



void Switch::Operate()
{
	//caclulate the output status as the ORing of the three input pins
	/*m_OutputPin[0].setStatus((STATUS)(GetInputPinStatus(1)));*/
	/*SetOutPinStatus();*/
	//Add you code here
}


// Function Draw
// Draws Switch
void Switch::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if (m_OutputPin[0].getStatus() == LOW)
		pOut->DrawSwitch(m_GfxInfo);
	else if (m_OutputPin[0].getStatus() == HIGH)
		pOut->DrawSwitchon(m_GfxInfo);
}

void Switch::SetOutPinStatus()       //
{
	if (m_OutputPin[0].getStatus() == LOW)
		m_OutputPin[0].setStatus(HIGH);
	else if (m_OutputPin[0].getStatus() == HIGH)
		m_OutputPin[0].setStatus(LOW);
}

//returns status of outputpin
int Switch::GetOutPinStatus()
{
	return m_OutputPin[0].getStatus();
}


//returns status of Inputpin #n
int Switch::GetInputPinStatus(int n)
{
	return -1;	//n starts from 1 but array index starts from 0.
}

GraphicsInfo Switch::getcomponentPosition()
{
	return m_GfxInfo;
}



//Set status of an input pin ot HIGH or LOW
void Switch::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

Gating Switch::getGateType()
{
	return Switcher;
}
