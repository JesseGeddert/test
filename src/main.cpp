#include <stdio.h>
#include <stdlib.h>
#include <matrix.h>
#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
	matrix M1;
	cout << endl << "M1= " << endl;
	M1.print();

	matrix M2(100);
	cout << endl << "M2= " << endl;
	M2.print();

	matrix M3(5, 2, 1, 8);
	cout << endl << "M3= " << endl;
	M3.print();

	int row = 0;
	int column = 0;
	double elem = M3. element(row, column);
	cout << "Element " << row << column << " of M3 is: " << elem << endl;
	row = 1;
	column = 0;
	elem = M3. element(row, column);
	cout << "Element " << row << column << " of M3 is: " << elem << endl;
	row = 0;
	column = 1;
	elem = M3. element(row, column);
	cout << "Element " << row << column << " of M3 is: " << elem << endl;
	row = 1;
	column = 1;
	elem = M3. element(row, column);
	cout << "Element " << row << column << " of M3 is: " << elem << endl;

	double determ = M3.determinant();
	cout << "The determinant of M3 is: " << determ << endl;

	matrix M4 = M3.multiply(3);
	cout << endl << "M4 = 3*M3 = " << endl;
	M4.print();

	matrix M5 = M3.inverse();
	cout << endl << "M5 = inverse of M3 =" << endl;
	M5.print();

	return 0;
}