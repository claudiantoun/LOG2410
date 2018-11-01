///////////////////////////////////////////////////////////
//  PrimitiveAbs.cpp
//  Implementation of the Class PrimitiveAbs
//  Created on:      25-oct.-2018 20:47:13
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "PrimitiveAbs.h"

// Declaration d'un conteneur vide pour retourner des iterateurs toujours valides
Objet3DContainer PrimitiveAbs::m_emptyContainer;

PrimitiveAbs::PrimitiveAbs(){

}

PrimitiveAbs::PrimitiveAbs(const Point3D& c) 
	: m_center(c)
	// A Completer...
{
}

PrimitiveAbs::~PrimitiveAbs(){

}

void PrimitiveAbs::addChild(const Objet3DAbs& obj3d){
	// Echoue silencieusement
}

Objet3DIterator PrimitiveAbs::begin(){

	// A Completer...
	Objet3DIterator iterator = m_emptyContainer.begin();
	return iterator;
}

Objet3DIterator_const PrimitiveAbs::cbegin() const {

	// A Completer...
	Objet3DIterator_const constantIterator = m_emptyContainer.begin();
	return constantIterator;
}

Objet3DIterator_const PrimitiveAbs::cend() const {

	// A Completer...
	Objet3DIterator_const constantIterator = m_emptyContainer.end();
	return constantIterator;
}

Objet3DIterator PrimitiveAbs::end(){

	// A Completer...
	Objet3DIterator iterator = m_emptyContainer.end();
	return iterator;
}

void PrimitiveAbs::removeChild(Objet3DIterator_const obj3dIt){
	// Echoue silencieusement
}

Point3D PrimitiveAbs::getCenter() const {

	// A Completer...
	return m_center;
}

void PrimitiveAbs::moveCenter(const Point3D & delta)
{
	// A Completer...
	m_center += delta;
}

void PrimitiveAbs::setCenter(const Point3D& center)
{
	// A Completer...
	m_center = center;
}

std::ostream & operator<<(std::ostream & o, const Objet3DAbs& obj3d )
{
	return obj3d.toStream(o);
}
