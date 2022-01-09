#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include "./../Vector3D/Vector3D2.h"

// Declares the use of the class
class Vector3D;

class Matrix {

private:


	double MatrixArray[3][3];





public:



	Matrix();


	Matrix(double a, double b, double c,double d, double e, double f,double g, double h, double z);



	

	Matrix(const Matrix& Mat);
	Matrix& operator=(const Matrix& Mat);
	~Matrix();

	Matrix operator+(const Matrix& Mat);

	Matrix operator-(const Matrix& Mat);

	Matrix operator*(const Matrix& Mat);

	Matrix operator*(vec& Vec);
	Matrix operator*(double Scalar);

	Matrix Inverse();

	Matrix Transpose();
	void RotateX(double Theta);

	void RotateY(double Theta);

	void RotateZ(double Theta);
	void SetMatrix();
	bool Set_Element(int i, int j, double MatB);
    bool Get_Element(int i, int j, double* Element) const;
	void OutputMatrix();



};


#endif // MATRIX_H_INCLUDED
