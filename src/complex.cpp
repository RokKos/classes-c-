#include "complex.hpp"

Complex::Complex() {
	this->real = 0;
	this->imaginary = 0;
}

Complex::Complex(double _real, double _imaginary) {
	this->real = _real;
	this->imaginary = _imaginary;
}

Complex::Complex(const Complex& rhs) {
	this->real = rhs.getReal();
	this->imaginary = rhs.getImaginary();
}

Complex::~Complex() {
	// Free anything if needed
}

Complex& Complex::operator=(const Complex& rhs) {
	this->real = rhs.getReal();
	this->imaginary = rhs.getImaginary();
	return *this;
}

double Complex::getReal() const {
	return this->real;
}

double Complex::getImaginary() const {
	return this->imaginary;
}

const double Complex::abs() const {
	return sqrt(real * real + imaginary * imaginary);
}

std::ostream& operator<<(std::ostream& output, const Complex& x) {
	output << x.getReal() << " " << x.getImaginary() << "i";
	return output;
}

const Complex operator+(const Complex& rhs1, const Complex& rhs2) {
	double newReal = rhs1.getReal() + rhs2.getReal();
	double newImaginary = rhs1.getImaginary() + rhs2.getImaginary();

	return Complex(newReal, newImaginary);
}

const Complex operator+(const Complex& rhs1, const double rhs2) {
	double newReal = rhs1.getReal() + rhs2;
	return Complex(newReal, rhs1.getImaginary());
}

const Complex operator+(const double rhs1, const Complex& rhs2) {
	double newReal = rhs2.getReal() + rhs1;
	return Complex(newReal, rhs2.getImaginary());
}

const Complex operator+(const Complex& rhs1, const int rhs2) {
	double newReal = rhs1.getReal() + rhs2;
	return Complex(newReal, rhs1.getImaginary());
}

const Complex operator+(const int rhs1, const Complex& rhs2) {
	double newReal = rhs2.getReal() + rhs1;
	return Complex(newReal, rhs2.getImaginary());
}
