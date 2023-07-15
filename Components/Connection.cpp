#include "Connection.h"
#include <iostream>

Connection::Connection()
{
}

Connection::Connection(const GraphicsInfo& r_GfxInfo, Component* pS, Component* pD, int Pino):Component(r_GfxInfo)
{
	GraphicsInfo Yesterday;
	Yesterday.x1 = r_GfxInfo.x1;
	Yesterday.y1 = r_GfxInfo.y1;
	Yesterday.x2 = 0;
	Yesterday.y2 = 0;
	z.setPosition(Yesterday);
	SrcPin = &z;
	GraphicsInfo Tomorrow;
	Tomorrow.x1 = r_GfxInfo.x2;
	Tomorrow.y1 = r_GfxInfo.y2;
	Tomorrow.x2 = 0;
	Tomorrow.y2 = 0;
	y.setPosition(Tomorrow);
	DstPin = &y;
	SrcCmpnt = pS;
	DstCmpnt = pD;
	DstPino = Pino;
}

Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin):Component(r_GfxInfo)
{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
}
void Connection::setSourcePin(OutputPin &pSrcPin)
{	SrcPin = &pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}

Gating Connection::getGateType()
{
	return Gating();
}

void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	pOut->DrawConnection(m_GfxInfo);
}

void Connection::setInLocation(GraphicsInfo x)
{
	SrcPin->setPosition(x);
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}
