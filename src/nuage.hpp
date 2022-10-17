#pragma once
#include "cartesien.hpp"
#include "point.hpp"
#include "polaire.hpp"
#include <iterator>
#include <vector>

using std::vector;

class Nuage {
	vector<Point *> points;

  public:
	Nuage();
	size_t size() const;
	void ajouter(Point &p);
	std::vector<Point *>::const_iterator begin(void) const;
	std::vector<Point *>::const_iterator end(void) const;
	using const_iterator = std::vector<Point *>::const_iterator;
	Point &operator[](uint const index);
};

struct BarycentreCartesien {
	Cartesien operator()(Nuage const &nuage) const;
};

struct BarycentrePolaire {
	Polaire operator()(Nuage const &nuage) const;
};

Cartesien barycentre(Nuage const &nuage);