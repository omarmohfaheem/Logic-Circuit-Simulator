#include "Pin.h"

Pin::Pin()
{
	m_Status = LOW;	//Default Status is LOW
}

void Pin::setPosition(GraphicsInfo seto)
{
	Position = seto;
}

//void Pin::setPosition(GraphicsInfo seto)
//{
//	Position.x1 = seto.x1;
//	Position.y1 = seto.y1;
//	Position.x2 = seto.x2;
//	Position.y2 = seto.y2;
//}

GraphicsInfo Pin::getPosition()
{
	return Position;
}

void Pin::setStatus(STATUS r_Status)
{
	m_Status = r_Status>0?HIGH:LOW;
}

STATUS Pin::getStatus()
{
	m_Status > 1 ? HIGH : LOW;
	return m_Status;
}