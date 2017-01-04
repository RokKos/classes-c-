#ifndef _POLYNOMIAL_HPP_
#define _POLYNOMIAL_HPP_

// System includes
#include <cassert>
#include <iostream>

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

};

std::ostream& operator<<(std::ostream& output, const Polynomial& x);

#endif  // _POLYNOMIAL_HPP_
