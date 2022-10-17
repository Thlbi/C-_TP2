#include "polaire.hpp"
#include "cartesien.hpp"
#include "point.hpp"
#include <iostream>
#include <math.h>
#include <sstream>

using std::cout;
using std::endl;
using std::stringstream;

Polaire::Polaire(double angle, double distance) : Point(), angle(angle), distance(distance) {
}

Polaire::Polaire() : Polaire(0, 0) {}

Polaire::Polaire(Cartesien const &other) : Polaire(0, 0) {
	other.convertir(*this);
}

double Polaire::getAngle() const {
	return angle;
}

double Polaire::getDistance() const {
	return distance;
}

void Polaire::afficher(stringstream &flux) const {
	flux << "(a=" << angle << ";d=" << distance << ")";
}

void Polaire::setAngle(double _angle) {
	angle = _angle;
}

void Polaire::setDistance(double _distance) {
	distance = _distance;
}

void Polaire::convertir(Polaire &point) const {
	point.angle = angle;
	point.distance = distance;
}

void Polaire::convertir(Cartesien &point) const {
	point.setX(distance * cos(angle * M_PI / 180));
	point.setY(distance * sin(angle * M_PI / 180));
}
