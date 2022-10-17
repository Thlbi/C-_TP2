#include "nuage.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"

Nuage::Nuage() : points() {
}

size_t Nuage::size() const {
	return points.size();
}

void Nuage::ajouter(Point &p) {
	points.push_back(&p);
}

std::vector<Point *>::const_iterator Nuage::begin(void) const {
	return points.begin();
}

std::vector<Point *>::const_iterator Nuage::end(void) const {
	return points.end();
}

Point &Nuage::operator[](uint const index) {
	return *points[index];
}

Cartesien barycentre(Nuage const &nuage) {
	uint total = nuage.size();
	double x = 0;
	double y = 0;
	for (auto point : nuage) {
		Cartesien tmp = {};
		point->convertir(tmp);
		x += tmp.getX();
		y += tmp.getY();
	}

	return {x / total, y / total};
}

Cartesien BarycentreCartesien::operator()(Nuage const &nuage) const {
	return barycentre(nuage);
}

Polaire BarycentrePolaire::operator()(Nuage const &nuage) const {
	Polaire p = {};
	barycentre(nuage).convertir(p);
	return p;
}