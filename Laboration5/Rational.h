#pragma once
#include <stdio.h>
#include <iostream>
#include "RelOps.h"
#include "GCD.h"

//class that handles Rational numbers
template<typename Tint>
class Rational {
public:
	Tint nom, denom;

	Rational() : nom(0), denom(1) {};
	Rational(Tint P) : nom(P), denom(1) {};
	Rational(Rational &t) : nom(t.nom), denom(t.denom) {};
	Rational(Tint P, Tint Q) : nom(P), denom(Q) {
		Reduce(P, Q);
	}

	Rational<Tint> operator+(Rational<Tint> &rhs);
	Rational<Tint> operator+(Tint &rhs);
	Rational<Tint> operator+=(const Rational &rhs);
	Rational<Tint> operator+=(Tint rhs);
	Rational<Tint> operator=(Rational &rhs);
	Rational<Tint> operator=(Tint rhs);
	Rational<Tint> operator-() const;
	Rational<Tint> operator++();
	Rational<Tint> operator++(const int i);

	operator int() const { return (nom / denom); }

	bool operator==(Rational<Tint> &rhs);
	bool operator==(int rhs);

	friend std::ostream& operator<<(std::ostream& out, Rational<Tint> R) {
		out << R.nom << '/' << R.denom;
		return out;
	}

	friend std::istream& operator>>(std::istream& in, Rational<Tint> &R) {
		in >> R.nom >> R.denom;
		return in;
	}

};

//Method that adds two rational numbers and returns the result
template<typename Tint>
Rational<Tint> Rational<Tint>::operator+(Rational<Tint> &rhs) {
	return Rational(*this += rhs);
}

//Method that adds two rational numbers and returns the result
template<typename Tint>
Rational<Tint> Rational<Tint>::operator+(Tint &rhs) {
	Rational temp1(rhs);
	Rational temp2(*this);
	temp2 += temp1;
	return Rational(temp2);
}

//method that adds a rational number to the number calling the method (this)
template<typename Tint>
Rational<Tint> Rational<Tint>::operator+=(const Rational &rhs) {
	int a = denom, b = rhs.denom;
	nom *= b;
	denom *= b;
	nom += rhs.nom * a;
	Reduce(nom, denom);
	return *this;
}

//method that adds a rational number to the number calling the method (this)
template<typename Tint>
Rational<Tint> Rational<Tint>::operator+=(Tint rhs) {
	Rational temp(rhs);
	this->operator+=(temp);
	return *this;
}

//method that equalizes the "this" number with the parameter value
template<typename Tint>
Rational<Tint> Rational<Tint>::operator=(Rational<Tint> &rhs) {
	nom = rhs.nom;
	denom = rhs.denom;
	return *this;
}

//method that equalizes the "this" number with the parameter value
template<typename Tint>
Rational<Tint> Rational<Tint>::operator=(Tint rhs) {
	nom = rhs;
	denom = 1;
	return *this;
}

//method that negates a rational number (this)
template<typename Tint>
Rational<Tint> Rational<Tint>::operator-() const {
	Rational<Tint> temp;
	temp.nom = -nom;
	temp.denom = denom;
	return temp;
}

//method that adds one to the calling number (this) POST
template<typename Tint>
Rational<Tint> Rational<Tint>::operator++() {
	return *this += 1;
}

//method that adds one to the calling number (this) PRE
template<typename Tint>
Rational<Tint> Rational<Tint>::operator++(int i) {
	Rational<Tint> temp = *this;
	*this += 1;
	return temp;
}

//method that checks the "this" number and the parameter value for equality
template<typename Tint>
bool Rational<Tint>::operator==(Rational &rhs) {
	return (this->nom == rhs.nom && this->denom == rhs.denom);
}

//method that checks the "this" number and the parameter value for equality
template<typename Tint>
bool Rational<Tint>::operator==(const int rhs) {
	return nom / denom == rhs;
}

