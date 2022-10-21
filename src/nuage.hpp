#ifndef ZZ3_TP2_NUAGE_HPP
#define ZZ3_TP2_NUAGE_HPP

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
Cartesien barycentre_v1(Nuage<T> const &n)
{
	double x, y;
	for (T p : n)
	{
		Cartesien c;
		p.convertir(c);
		x += c.getX();
		y += c.getY();
	}
	return (n.size() == 0) ? Cartesien(0, 0) : Cartesien(x / n.size(), y / n.size());
}

template <typename T>
Cartesien barycentre_v2(T cont)
{
	double x, y;
	for (auto p : cont)
	{
		Cartesien c;
		p.convertir(c);
		x += c.getX();
		y += c.getY();
	}
	return (cont.size() == 0) ? Cartesien(0, 0) : Cartesien(x / cont.size(), y / cont.size());
}

#endif