#pragma once

#include <iostream>

using std::stringstream;

class Cartesien;
class Polaire;

class Point {
  public:
	virtual void afficher(stringstream &flux) const = 0;
	virtual void convertir(Cartesien &point) const = 0;
	virtual void convertir(Polaire &point) const = 0;
};

std::stringstream &operator<<(std::stringstream &flux, const Point &point);
