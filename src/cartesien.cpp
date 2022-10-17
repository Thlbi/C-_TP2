#include "cartesien.hpp"
#include "polaire.hpp"
#include <iostream>
#include <math.h>
#include <sstream>

using std::stringstream;

Cartesien::Cartesien(double x, double y) : Point(), x(x), y(y) {
}

Cartesien::Cartesien() : Cartesien(0, 0) {
}

Cartesien::Cartesien(Polaire const &other) : Cartesien(0, 0) {
	other.convertir(*this);
}

double Cartesien::getX() const {
	return x;
}

double Cartesien::getY() const {
	return y;
}

void Cartesien::setX(double _x) {
	x = _x;
}

void Cartesien::setY(double _y) {
	y = _y;
}

void Cartesien::afficher(stringstream &flux) const {
	flux << "(x=" << x << ";y=" << y << ")";
}

void Cartesien::convertir(Polaire &point) const {
	point.setAngle(atan2(y, x) * 180 / M_PI);
	point.setDistance(sqrt(x * x + y * y));
}

void Cartesien::convertir(Cartesien &point) const {
	point.x = x;
	point.y = y;
}
