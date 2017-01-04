#include "polynomial.hpp"

Polynomial::Polynomial(int _degree, double* _coeffcients){
	this->degree = _degree;
	if (_degree == 0) {
		coeffcients = (double*) NULL;
	} else {
		coeffcients = new double[_degree + 1];  // there is n+1 coeffcients
		for (int i = 0; i < _degree + 1; ++i) {
			coeffcients[i] = _coeffcients[i];
		}
	}
}

Polynomial::Polynomial(const Polynomial& rhs){
	this->degree = rhs.getDegree();
	if (this->degree == 0) {
		coeffcients = (double*) NULL;
	} else {
		coeffcients = new double[this->degree + 1];
		for (int i = 0; i < this->degree + 1; ++i) {
			coeffcients[i] = rhs[i];
		}
	}
}

Polynomial::~Polynomial(){
	if (this->degree > 0) {
		delete[] coeffcients;
	}
}

Polynomial& Polynomial::operator=(const Polynomial& rhs) {
	int newDegre = rhs.getDegree();
	// Check if size has changed
	if (this->degree != newDegre) {
		this->degree = newDegre;
		if (this->degree == 0) {
			coeffcients = (double*) NULL;
		} else {
			// Erase previus array and create new one
			delete[] coeffcients;
			coeffcients = new double[this->degree + 1];
		}
	}
	// If size didn't changed then just overvrite previus values
	for (int i = 0; i < this->degree + 1; ++i) {
		coeffcients[i] = rhs[i];
	}
	return *this;
}

const double& Polynomial::operator[](int i) const{
	assert(i>=0 && i <= this->degree);
	return coeffcients[i];
}

double& Polynomial::operator[](int i) {
	assert(i>=0 && i <= this->degree);
	return coeffcients[i];
}

int Polynomial::getDegree() const{
	return this->degree;
}

std::ostream& operator<<(std::ostream& output, const Polynomial& x) {
	int n = x.getDegree();
	output << "Degree: " << n << " \n";
	output << "Coeffcients: ";
	for (int i = 0; i < n + 1; ++i) {
		output << x[i] << " ";
	}
	return output;
}
