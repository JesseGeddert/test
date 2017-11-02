#include <matrix.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

matrix::matrix()
{
	/*
		This constructor (the default constructor) creates a matrix with all zero elements
	*/

	e00 = e01 = e10 = e11 = 0;
}

matrix::matrix(double a)
{
	/*
		This constructor should create a diagonal matrix with the diagonal elements equal to a and
		the other elements equal to zero.

		TO DO
	*/

	e00 = a;
	e01 = 0;
	e10 = 0;
	e11 = a;
}

matrix::matrix(double a, double b, double c, double d)
{
	/*
		This constructor should set the elements the values of the elements using the
		parameters a,b,c,d

		TO DO
	*/

	e00 = a;
	e01 = b;
	e10 = c;
	e11 = d;
}

matrix::matrix(const matrix& a)
{
	/*
		This is the copy constructor: it takes a matrix and makes a new one with the same element values
	*/

	e00 = a.e00;
	e01 = a.e01;
	e10 = a.e10;
	e11 = a.e11;
}

matrix& matrix::add(matrix& a)
{
	/*
		The add member function adds the elements of matrix 'a' to this matrix. 
	*/

	e00 = e00 + a.e00;
	e01 = e01 + a.e01;
	e10 = e10 + a.e10;
	e11 = e11 + a.e11;

	return *this;
}

matrix& matrix::multiply(double x)
{
	e00 = e00*x;
	e01 = e01*x;
	e10 = e10*x;
	e11 = e11*x;

	return *this;
}

matrix& matrix::multiply(matrix& m)
{
	e00 = e00*m.e00 + e01*m.e10;
	e01 = e00*m.e10 + e01*m.e11;
	e10 = e10*m.e00 + e11*m.e10;
	e11 = e10*m.e10 + e11*m.e10;

	return *this;
}

double matrix::element(int row, int column)
{
	double entry;

	if(row==0 && column == 0)	entry = e00;
	if(row==0 && column == 1)	entry = e01;
	if(row==1 && column == 0)	entry = e10;
	if(row==1 && column == 1)	entry = e11;

	return entry;
}

double matrix::determinant()
{
	double determ;
	determ = e00*e11 - e10*e01;
	return determ;
}

matrix& matrix::inverse()
{
	double orig_e00 = e00;
	double orig_e01 = e01;
	double orig_e10 = e10;
	double orig_e11 = e11;
	double factor = 1.0/(orig_e00*orig_e11 - orig_e01*orig_e10);

	e00 = factor*orig_e11;
	e01 = factor*-1.0*orig_e01;
	e10 = factor*-1.0*orig_e10;
	e11 = factor*orig_e00;

	return *this;
}

void matrix::print()
{
	//printf("\n| %*.2f %*.2f |\n| %*.2f %*.2f |\n", 4, e00, 4, e01, 4, e10, 4, e11);
	cout << "| " << setprecision(3) << setw(6) << e00 << " " << setprecision(3) << setw(6) << e01 << " |\n";
	cout << "| " << setprecision(3) << setw(6) << e10 << " " << setprecision(3) << setw(6) << e11 << " |\n";
}
