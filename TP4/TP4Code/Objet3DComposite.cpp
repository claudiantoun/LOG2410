///////////////////////////////////////////////////////////
//  Objet3DComposite.cpp
//  Implementation of the Class Objet3DComposite
//  Created on:      25-oct.-2018 20:40:33
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Objet3DComposite.h"


Objet3DComposite::Objet3DComposite()
{
}

Objet3DComposite::Objet3DComposite(const Objet3DComposite & mdd)
{
	// A Completer...
	for (auto it = mdd.cbegin(); it != mdd.cend(); it++)
		addChild(*it);

	this->outputIndent = mdd.outputIndent;
}

Objet3DComposite::~Objet3DComposite()
{
}

Objet3DComposite * Objet3DComposite::clone() const
{
	// A Completer...
	return new Objet3DComposite(*this);
}

void Objet3DComposite::addChild(const Objet3DAbs& obj3d)
{
	// A Completer...
	m_objetContainer.push_back(Objet3DPtr(obj3d.clone()));
}

Objet3DIterator Objet3DComposite::begin()
{
	// A Completer...
	Objet3DIterator it = m_objetContainer.begin();
	return it;
}

Objet3DIterator_const Objet3DComposite::cbegin() const
{
	// A Completer...
	Objet3DIterator_const it = m_objetContainer.begin();
	return it;
}

Objet3DIterator_const Objet3DComposite::cend() const
{
	// A Completer...
	Objet3DIterator_const it = m_objetContainer.end();
	return it;
}

Objet3DIterator Objet3DComposite::end()
{
	// A Completer...
	Objet3DIterator it = m_objetContainer.end();
	return it;
}

Point3D Objet3DComposite::getCenter() const
{	
	// A Completer...
	return computeCenter();
}

size_t Objet3DComposite::getNbParameters() const 
{
	return 0;
}

PrimitiveParams Objet3DComposite::getParameters() const
{
	return  PrimitiveParams();
}

void Objet3DComposite::removeChild(Objet3DIterator_const obj3dIt)
{
	// A Completer...
	m_objetContainer.erase(obj3dIt);
}

void Objet3DComposite::moveCenter(const Point3D & delta)
{
	// A Completer...
	for (auto it = begin(); it != end(); it++)
		it->moveCenter(delta);
}

void Objet3DComposite::setCenter(const Point3D& center)
{
	// A Completer...
	Point3D diff = center - getCenter();
	for (auto it = begin(); it != end(); it++)
		it->moveCenter(diff);
}

void Objet3DComposite::setParameter(size_t pIndex, float pValue)
{
}

Point3D Objet3DComposite::computeCenter() const
{
	// Calcul la moyenne des centres de tous les enfants
	// S'il n'y a pas d'enfant, initialise a (0,0,0)

	// A Completer...
	Point3D m_center(0, 0, 0);

	if (m_objetContainer.size() == 0)
		return m_center;

	else
	{
		for (auto it = cbegin(); it != cend(); it++)
			m_center += it->getCenter();

		m_center /= m_objetContainer.size();
		return m_center;
	}
}

// Variable statique permettant de stocker le niveau d'indentation
size_t Objet3DComposite::outputIndent = 0;

std::ostream& indentation(std::ostream& o, size_t indentLevel)
{
	for (auto iindent = 0; iindent < indentLevel; ++iindent)
		o << "\t";
	return o;
}

std::ostream & Objet3DComposite::toStream(std::ostream & o) const
{
	o << "Composite: center = " << computeCenter() << ": {" << std::endl;
	++outputIndent;
	for (auto it = cbegin(); it != cend(); ++it)
		indentation(o, outputIndent) << *it << std::endl;
	--outputIndent;
	indentation(o, outputIndent) << "}";

	return o;
}
