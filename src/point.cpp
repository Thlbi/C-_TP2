#include "point.hpp"
#include <math.h>

std::stringstream &operator<<(std::stringstream &flux, const Point &point) {
	point.afficher(flux);
	return flux;
}
