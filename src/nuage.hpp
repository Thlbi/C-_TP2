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
	double angle = 0;
	double distance = 0;
	for (Polaire p : n)
	{

		angle += p.getAngle();
		distance += p.getDistance();
	}
	return (n.size() == 0) ? Polaire(0, 0) : Polaire(angle / n.size(), distance / n.size());
}
