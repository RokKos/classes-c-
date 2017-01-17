#ifndef _SRC_POLYNOMIAL_HPP_
#define _SRC_POLYNOMIAL_HPP_

// System includes
#include <cassert>
#include <iostream>
#include <math.h>

// User includes


/**
 * @file polynomial.hpp
 * @author Rok Kos <kosrok97@gmail.com>
 * @brief Class that represent polynom.
 */

class Polynomial {
private:
	int degree;
	double* coeffcients;

public:
	// Constructor
	Polynomial ();
	Polynomial (int _degree, double* _coeffcients);
	// Copy Constructor
	Polynomial (const Polynomial& rhs);
	// Destructor
	~Polynomial();
	// Assigment operator
	Polynomial& operator=(const Polynomial& rhs);
	// Getting i-th coeffcient with []
	const double& operator[](int i) const;
	// Setting i-th coeffcient with []
	double& operator[](int i);
	// Get degree of polynom
	int getDegree() const;
	// K-derivate of polynom
	const Polynomial operator()(const int) const;
	const double operator()(const int, const double) const;

	const double computeZero (double x) const;

};

std::ostream& operator<<(std::ostream& output, const Polynomial& x);

// Adding polynom to polynom
const Polynomial operator+(const Polynomial&, const Polynomial&);

// Adding double to polynom
const Polynomial operator+(const Polynomial&, const double);
const Polynomial operator+(const double, const Polynomial&);

// Adding int to polynom
const Polynomial operator+(const Polynomial&, const int);
const Polynomial operator+(const int, const Polynomial&);

// Multiplying polynom to polynom
const Polynomial operator*(const Polynomial&, const Polynomial&);

// Multiplying double to polynom
const Polynomial operator*(const Polynomial&, const double);
const Polynomial operator*(const double, const Polynomial&);

// Multiplying int to polynom
const Polynomial operator*(const Polynomial&, const int);
const Polynomial operator*(const int, const Polynomial&);


#endif  // _SRC_POLYNOMIAL_HPP_
