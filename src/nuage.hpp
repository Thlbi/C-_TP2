#include "cartesien.hpp"
#include "point.hpp"
#include "polaire.hpp"
#include <iterator>
#include <vector>

template <class T>

class Nuage
{
	std::vector<T> vect;

public:
	using const_iterator = typename std::vector<T>::const_iterator;

	Nuage();
	size_t size() const;
	void ajouter(T const &p);
	const_iterator begin() const;
	const_iterator end() const;
};

template <class T>
Nuage<T>::Nuage() {}

template <class T>
size_t Nuage<T>::size() const
{
	return vect.size();
}

template <class T>
void Nuage<T>::ajouter(T const &p)
{
	vect.push_back(p);
}

template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::begin() const
{
	return vect.begin();
}

template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::end() const
{
	return vect.end();
}

template <typename T>

Polaire barycentre_v1(Nuage<T> const &n)
{
	double x = 0;
	double y = 0;
	for (T p : n)
	{
		Cartesien c;
		p.convertir(c);
		x += c.getX();
		y += c.getY();
	}
	return (n.size() == 0) ? Polaire(0, 0) : Polaire((atan2(y / n.size(), x / n.size()) * 180 / M_PI), sqrt(x / n.size() * x / n.size() + y / n.size() * y / n.size()));
}
