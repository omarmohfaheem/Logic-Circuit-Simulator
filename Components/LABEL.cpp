#include "LABEL.h"

LABEL::LABEL(GraphicsInfo r_GfxInfo, string Labele)
{
	m_GfxInfo = r_GfxInfo;
	Labelo = Labele;
}

void LABEL::Draw(Output*Outo)
{
	Outo->DrawLabel(m_GfxInfo, Labelo);
}

GraphicsInfo LABEL::retLabeLocation()
{
	return m_GfxInfo;
}


