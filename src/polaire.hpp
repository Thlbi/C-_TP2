#pragma once
#include "point.hpp"
#include <iostream>

using std::stringstream;

class Polaire : public Point {
	double angle;
	double distance;

  public:
	Polaire(double angle, double distance);
	Polaire(Cartesien const &other);
	Polaire();
	double getAngle() const;
	double getDistance() const;
	void setAngle(double angle_);
	void setDistance(double distance_);
	void afficher(stringstream &flux) const override;
	void convertir(Polaire &point) const override;
	void convertir(Cartesien &point) const override;
};
