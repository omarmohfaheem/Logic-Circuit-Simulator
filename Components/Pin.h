#ifndef _PIN_H
#define _PIN_H

#include "..\Defs.h"

class Pin
{
protected:
	STATUS m_Status;	//Status of the Pin
	GraphicsInfo Position;
public:
	Pin();
	virtual void setPosition(GraphicsInfo seto);
	GraphicsInfo getPosition();
	void setStatus(STATUS r_Status);
	STATUS getStatus();
};

#endif