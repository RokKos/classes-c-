#include <climits> // Including max and min values for tipes

#include "gtest/gtest.h"
#include "polynomial.hpp"

TEST (Polynomial, GetDegree) {
	// We dont look at the coeficient so that doesnt matter now
	double* coef1 = new double[2];
	for (int i = 0; i < 2; ++i) {
		coef1[i] = i + 1;
	}
	Polynomial polinom1(0, coef1);
	ASSERT_EQ(0, polinom1.getDegree());
	Polynomial polinom2(1, coef1);
	ASSERT_EQ(1, polinom2.getDegree());
	Polynomial polinom3(2, coef1);
	ASSERT_EQ(2, polinom3.getDegree());
	Polynomial polinom4(5, coef1);
	ASSERT_EQ(5, polinom4.getDegree());
	Polynomial polinom5(100, coef1);
	ASSERT_EQ(100, polinom5.getDegree());
	Polynomial polinom6(1000, coef1);
	ASSERT_EQ(1000, polinom6.getDegree());
	// Big number doesnt work because there is to much space to alocate
	//Polynomial polinom7(100, coef1);
	//ASSERT_EQ(100, polinom7.getDegree());

	delete[] coef1;
}

TEST (Polynomial, GetCoefficient) {
	int degree1 = 5;
	double* coef1 = new double[degree1+1];
	for (int i = 0; i < degree1+1; ++i) {
		coef1[i] = i + 1;
	}
	Polynomial polinom1(degree1+1, coef1);
	for (int i = 0; i < degree1 + 1; ++i) {
		ASSERT_EQ(i + 1,polinom1[i]);
	}

	double* coef2 = new double[1];
	coef2[0] = 1.0;
	Polynomial polinom2(0, coef2);
	ASSERT_EQ(1.0,polinom2[0]);
}
