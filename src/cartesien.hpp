#pragma once
#include "point.hpp"

class Cartesien : public Point {
  private:
	double x;
	double y;

  public:
	Cartesien(double x, double y);
	Cartesien();
	Cartesien(Polaire const &other);
	double getX() const;
	double getY() const;
	void setX(double _x);
	void setY(double _y);
	void afficher(stringstream &flux) const override;
	void convertir(Polaire &point) const override;
	void convertir(Cartesien &point) const override;
};
