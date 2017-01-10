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
	ASSERT_EQ(0,polinom2.getDegree());
	ASSERT_EQ(1.0,polinom2[0]);
}

TEST (Polynomial, CopyConstructor) {
	int degree1 = 5;
	double* coef1 = new double[degree1+1];
	for (int i = 0; i < degree1+1; ++i) {
		coef1[i] = i + 1;
	}
	Polynomial polinom1(degree1, coef1);
	Polynomial polinom2(polinom1);
	ASSERT_EQ(degree1, polinom2.getDegree());
	for (int i = 0; i < degree1 + 1; ++i) {
		EXPECT_EQ(i + 1,polinom2[i]);
	}

	double* coef2 = new double[1];
	coef2[0] = 1.0;
	Polynomial polinom3(0,coef2);
	Polynomial polinom4(polinom3);
	ASSERT_EQ(degree1, polinom2.getDegree());
	EXPECT_EQ(1.0, polinom4[0]);
}

TEST (Polynomial, AssigmentOperator) {
	int degree1 = 5;
	double* coef1 = new double[degree1+1];
	for (int i = 0; i < degree1+1; ++i) {
		coef1[i] = i + 1;
	}
	Polynomial polinom1(degree1, coef1);
	Polynomial polinom2 = polinom1;
	ASSERT_EQ(degree1, polinom2.getDegree());
	for (int i = 0; i < degree1 + 1; ++i) {
		EXPECT_EQ(i + 1,polinom2[i]);
	}

	double* coef2 = new double[1];
	coef2[0] = 1.0;
	Polynomial polinom3(0,coef2);
	Polynomial polinom4 = polinom3;
	ASSERT_EQ(degree1, polinom2.getDegree());
	EXPECT_EQ(1.0, polinom4[0]);
}

TEST (Polynomial, OperatorPlus) {
	// Testing polynom + polynom
	int degree1 = 3;
	int degree2 = 2;
	double* coef1 = new double[degree1 + 1];
	double* coef2 = new double[degree2 + 1];
	for (int i = 0; i < degree1 + 1; ++i) {
		coef1[i] = i + 1;
	}
	for (int i = 0; i < degree2 + 1; ++i) {
		coef2[i] = i + 1;
	}
	double* coef3 = new double[1];
	coef3[0] = 1.0;
	Polynomial pol1(degree1, coef1);
	Polynomial pol2(degree2, coef2);
	Polynomial pol3(0,coef2);

	Polynomial pol4 = pol1 + pol1;
	for (int i = 0; i < degree1 + 1; ++i) {
		EXPECT_EQ(2*(i + 1),pol4[i]);
	}
	Polynomial pol5 = pol1 + pol2;
	for (int i = 0; i < degree1 + 1; ++i) {
		if (i == degree1) {
			EXPECT_EQ(i + 1,pol5[i]);
		} else {
			EXPECT_EQ(2*(i + 1),pol5[i]);
		}
	}
	Polynomial pol6 = pol1 + pol3;
	for (int i = 0; i < degree1 + 1; ++i) {
		if (i == 0) {
			EXPECT_EQ(i + 2,pol6[i]);
		} else {
			EXPECT_EQ((i + 1),pol6[i]);
		}
	}
	Polynomial pol7 = pol3 + pol3;
	EXPECT_EQ(2.0,pol7[0]);

	// Testing polynom + int
	// polynom + double
	// int + polynom
	// double + polynom
	Polynomial pol8 = pol1 + 2.5;
	Polynomial pol9 = 2.5 + pol1;
	Polynomial pol10 = pol1 + 3;
	Polynomial pol11 = 3 + pol1;
	for (int i = 0; i < degree1 + 1; ++i) {
		if (i == 0) {
			EXPECT_EQ(i + 3.5,pol8[i]);
			EXPECT_EQ(i + 3.5,pol9[i]);
			EXPECT_EQ(i + 4,pol10[i]);
			EXPECT_EQ(i + 4,pol11[i]);
		} else {
			EXPECT_EQ(i + 1,pol8[i]);
			EXPECT_EQ(i + 1,pol9[i]);
			EXPECT_EQ(i + 1,pol10[i]);
			EXPECT_EQ(i + 1,pol11[i]);
		}
	}
	Polynomial pol12 = pol3 + 1.0;
	Polynomial pol13 = 1.0 + pol3;
	Polynomial pol14 = pol3 + 2;
	Polynomial pol15 = 2 + pol3;
	EXPECT_EQ(2.0,pol12[0]);
	EXPECT_EQ(2.0,pol13[0]);
	EXPECT_EQ(3,pol14[0]);
	EXPECT_EQ(3,pol15[0]);
}

TEST (Polynomial, OutputOperator) {
	int degree1 = 3;
	int degree2 = 2;
	double* coef1 = new double[degree1 + 1];
	double* coef2 = new double[degree2 + 1];
	for (int i = 0; i < degree1 + 1; ++i) {
		coef1[i] = i + 1;
	}
	for (int i = 0; i < degree2 + 1; ++i) {
		coef2[i] = i + 1;
	}
	double* coef3 = new double[1];
	coef3[0] = 1.0;
	// Polinoms
	Polynomial polinom1(degree1, coef1);
	Polynomial polinom2(degree2, coef2);
	Polynomial polinom3(0,coef2);
	// Output streams
	std::ostringstream out1;
	std::ostringstream out2;
	std::ostringstream out3;
	out1 << polinom1;
	EXPECT_EQ( "Degree: 3 \nCoeffcients: 1x^0 2x^1 3x^2 4x^3 ", out1.str());
	out2 << polinom2;
	EXPECT_EQ( "Degree: 2 \nCoeffcients: 1x^0 2x^1 3x^2 ", out2.str());
	out3 << polinom3;
	EXPECT_EQ( "Degree: 0 \nCoeffcients: 1x^0 ", out3.str());
}

TEST (Polynomial, OperatorMult) {
	// Testing polynom * polynom
	int degree1 = 3;
	int degree2 = 2;
	double* coef1 = new double[degree1 + 1];
	double* coef2 = new double[degree2 + 1];
	for (int i = 0; i < degree1 + 1; ++i) {
		coef1[i] = i + 1;
	}
	for (int i = 0; i < degree2 + 1; ++i) {
		coef2[i] = i + 1;
	}
	double* coef3 = new double[1];
	coef3[0] = 1.0;
	Polynomial pol1(degree1, coef1);
	Polynomial pol2(degree2, coef2);
	Polynomial pol3(0,coef2);

	double* rez1 = new double[7]{1,4,10,20,25,24,16};
	Polynomial pol4 = pol1 * pol1;
	for (int i = 0; i < 7; ++i) {
		EXPECT_EQ(rez1[i],pol4[i]);
	}

	double* rez2 = new double[6]{1,4,10,16,17,12};
	Polynomial pol5 = pol1 * pol2;
	for (int i = 0; i < 6; ++i) {
		EXPECT_EQ(rez2[i],pol5[i]);
	}

	double* rez3 = new double[5]{1,4,10,12,9};
	Polynomial pol6 = pol2 * pol2;
	for (int i = 0; i < 5; ++i) {
		EXPECT_EQ(rez3[i],pol6[i]);
	}

	Polynomial pol7 = pol1 * pol3;
	for (int i = 0; i < degree1 + 1; ++i) {
		EXPECT_EQ(coef1[i],pol7[i]);
	}
	Polynomial pol8 = pol3 * pol3;
	EXPECT_EQ(1.0,pol8[0]);

	// Testing polynom * int
	// polynom * double
	// int * polynom
	// double * polynom
	Polynomial pol9 = pol1 * 2.5;
	Polynomial pol10 = 2.5 * pol1;
	Polynomial pol11 = pol1 * 3;
	Polynomial pol12 = 3 * pol1;
	for (int i = 0; i < degree1 + 1; ++i) {
		EXPECT_EQ(coef1[i] * 2.5, pol9[i]);
		EXPECT_EQ(coef1[i] * 2.5, pol10[i]);
		EXPECT_EQ(coef1[i] * 3, pol11[i]);
		EXPECT_EQ(coef1[i] * 3, pol12[i]);
	}
	Polynomial pol13 = pol3 * 1.0;
	Polynomial pol14 = 1.0 * pol3;
	Polynomial pol15 = pol3 * 2;
	Polynomial pol16 = 2 * pol3;
	EXPECT_EQ(1.0, pol13[0]);
	EXPECT_EQ(1.0, pol14[0]);
	EXPECT_EQ(2, pol15[0]);
	EXPECT_EQ(2, pol16[0]);
}

TEST (Polynomial, Derivate) {
	// Testing derivate
	int degree1 = 3;
	int degree2 = 2;
	double* coef1 = new double[degree1 + 1];
	double* coef2 = new double[degree2 + 1];
	for (int i = 0; i < degree1 + 1; ++i) {
		coef1[i] = i + 1;
	}
	for (int i = 0; i < degree2 + 1; ++i) {
		coef2[i] = i + 1;
	}
	double* coef3 = new double[1];
	coef3[0] = 1.0;
	Polynomial pol1(degree1, coef1);
	Polynomial pol2(degree2, coef2);
	Polynomial pol3(0,coef2);

	// pol1' -> first derivate
	Polynomial pol4 = pol1(1);
	//double* rez2 = new double[4]{2,6,12}; actual values
	for (int i = 0; i < degree1; ++i) {
		EXPECT_EQ(coef1[i+1] * (i+1), pol4[i]);  // rez2[i] can compare to this
	}

	Polynomial pol5 = pol2(1);
	for (int i = 0; i < degree2; ++i) {
		EXPECT_EQ(coef2[i+1] * (i+1), pol5[i]);
	}

	// When derivate is largen the degree
	Polynomial pol6 = pol3(1);
	EXPECT_EQ(0, pol6[0]);
	Polynomial pol7 = pol3(2);
	EXPECT_EQ(0, pol7[0]);

	// pol1'' -> second derivate
	Polynomial pol8 = pol1(2);
	for (int i = 0; i < degree1 - 1; ++i) {
		EXPECT_EQ(coef1[i+2] * (i+1) * (i+2), pol8[i]);
	}

	Polynomial pol9 = pol2(2);
	for (int i = 0; i < degree2 - 1; ++i) {
		EXPECT_EQ(coef2[i+2] * (i+1) * (i+2), pol9[i]);
	}

	// Values at first derivate
	EXPECT_EQ(62, pol1(1, 2));
	EXPECT_EQ(20, pol2(1, 3));
	EXPECT_EQ(0, pol3(1, 3));

	// Values at second derivate
	EXPECT_EQ(54, pol1(2, 2));
	EXPECT_EQ(6, pol2(2, 1000));
	EXPECT_EQ(0, pol3(2, 100));




}
