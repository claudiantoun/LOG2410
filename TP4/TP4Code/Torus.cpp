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