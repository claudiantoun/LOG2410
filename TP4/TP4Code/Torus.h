///////////////////////////////////////////////////////////
//  Torus.h
//  Implementation of the Class Torus
//  Created on:      10-nov.-2018
//  Original author: Sandu Babira et Claudia Antoun
///////////////////////////////////////////////////////////

//#if !defined(EA_7AFCD1D8_33C4_440c_AB86_C25104795AAF__INCLUDED_)
//#define EA_7AFCD1D8_33C4_440c_AB86_C25104795AAF__INCLUDED_

#include "PrimitiveAbs.h"

class Torus : public PrimitiveAbs
{

public:
	Torus(const Point3D& pt, float r, float R);
	virtual ~Torus();
	virtual Torus* clone() const;

	virtual size_t getNbParameters() const;
	virtual PrimitiveParams getParameters() const;
	virtual void setParameter(size_t pIndex, float pValue);

private:
	virtual std::ostream& toStream(std::ostream& o) const;

	float m_dimensions[2];
};
//#endif // !defined(EA_7AFCD1D8_33C4_440c_AB86_C25104795AAF__INCLUDED_)
