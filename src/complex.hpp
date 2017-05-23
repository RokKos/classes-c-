#ifndef _SRC_COMLEX_HPP_
#define _SRC_COMLEX_HPP_

// System includes
#include <cassert>
#include <iostream>
#include <math.h>

// User includes


/**
 * @file complex.hpp
 * @author Rok Kos <kosrok97@gmail.com>
 * @brief Class that represent complex numbers.
 */

/*TODO:
	- + operator(complex, int, double)
	- * operator
	- / operator
	- abs
	- konjugirano
*/

class Complex {
private:
	double real;
	double imaginary;

public:
	// Constructor
	Complex ();
	Complex (double _real, double _imaginary);
	// Copy Constructor
	Complex (const Complex& rhs);
	// Destructor
	~Complex();
	// Assigment operator
	Complex& operator=(const Complex& rhs);
	// Get degree of polynom
	double getReal() const;
	double getImaginary() const;

	const double abs () const;

};

std::ostream& operator<<(std::ostream& output, const Complex& x);

// Adding polynom to polynom
const Complex operator+(const Complex&, const Complex&);

// Adding double to polynom
const Complex operator+(const Complex&, const double);
const Complex operator+(const double, const Complex&);

// Adding int to polynom
const Complex operator+(const Complex&, const int);
const Complex operator+(const int, const Complex&);

#endif  // _SRC_COMLEX_HPP_
