#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
}

GraphicsInfo Component::geta()
{
	return m_GfxInfo;
}

Component::Component()
{}

Component::~Component()
{}

