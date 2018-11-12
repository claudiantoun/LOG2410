///////////////////////////////////////////////////////////
//  Torus.cpp
//  Implementation of the Class Torus
//  Created on:      10-nov.-2018
//  Original author: Sandu Babira et Claudia Antoun
///////////////////////////////////////////////////////////

#include "Torus.h"

Torus::Torus(const Point3D& pt, float r, float R)
	:PrimitiveAbs(pt)
{
	if (r < 0.0 || R < 0.0)
		throw std::range_error("Invalid parameter value for Torus. Must be larger than 0.");

	m_dimensions[0] = r;
	m_dimensions[1] = R;
}

Torus::~Torus()
{
}

Torus * Torus::clone() const
{
	return new Torus(this->m_center, this->m_dimensions[0], this->m_dimensions[1]);
}

size_t Torus::getNbParameters() const
{
	return getParameters().size();
}

PrimitiveParams Torus::getParameters() const
{
	PrimitiveParams parametresTorus;
	for (int i = 0; i < 2; i++)
	{
		parametresTorus.push_back(m_dimensions[i]);
	}
	return parametresTorus;
}

void Torus::setParameter(size_t pIndex, float pValue)
{
	if (pIndex < 0 || pIndex > 1)
		throw std::range_error("Invalid parameter index for torus. Must be between 0 and 1");

	if (pValue < 0.0)
		throw std::range_error("Invalid parameter value for torus. Must be larger than 0");

	m_dimensions[pIndex] = pValue;
}

std::ostream & Torus::toStream(std::ostream & o) const
{
	return o << "Torus:	   center = " << m_center
		<< "; r = " << m_dimensions[0]
		<< "; R = " << m_dimensions[1] << ";";
}