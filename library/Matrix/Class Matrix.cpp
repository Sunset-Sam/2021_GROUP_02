
#include "Class Matrix.h"
#include "./../Vector3D/Vector3D.h"
#include <iostream>
#include <math.h>
#define PI 3.14
using namespace std;


Matrix::Matrix() {

    unsigned i, j;

    for (i = 0; i < 3; i++){

        for (j = 0; j < 3; j++) {

            if (i == j) {

                this->MatrixArray[i][j] = 1;
            }
            else {

                this->MatrixArray[i][j] = 0;
            }
        }
    }
    return;
}

// -------------------------------------------------------------------------------------------------
// Constructor to input in a 3x3 matrix

Matrix::Matrix(double a, double b, double c,double d, double e, double f,double g, double h, double z) {

    double elements[] = {a, b, c, d, e, f, g, h, z };

    unsigned i,j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            this->MatrixArray[i][j] = elements[(i * 3) + j];

        }
    }

    return;
}
//Matrix Destructor
Matrix::~Matrix() {}
//Matrix copy constructor
Matrix::Matrix(const Matrix& Mat) {

    unsigned i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            this->MatrixArray[i][j] = Mat.MatrixArray[i][j];

        }

    }

    return;

}


// Matrix addition operator
// Addition 2 Matrix together
Matrix Matrix::operator+(const Matrix &Mat)
{
	Matrix Addition;
	unsigned i, j;

    for (i = 0;i < 3; i++) {

        for (j = 0; j < 3; j++) {

        	double MatB;
        	Mat.Get_Element(i,j, &MatB );
            Addition.Set_Element(i, j, this->MatrixArray[i][j] + MatB);
        }
    }

    return Addition;
}



// -------------------------------------------------------------------------------------------------
// Matrix subtraction operator
// Subtraction 2 Matrix together
Matrix Matrix::operator-(const Matrix& Mat)
{
    Matrix Subtraction;
    unsigned i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {
        	double MatB;
        	Mat.Get_Element(i,j, &MatB );
            Subtraction.Set_Element(i, j, this->MatrixArray[i][j] - MatB);
        }
    }

    return Subtraction;
}

//Matrix Multiplication operator
//Multiple 2 Matrix together
Matrix Matrix::operator*(const Matrix& Mat)
{
    Matrix Multiple;

    unsigned i, j, k;

    double temp = 0.0;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            temp = 0.0;

            for (k = 0; k < 3; k++) {

                double MatB;
                Mat.Get_Element(k, j, &MatB);

                temp += this->MatrixArray[i][k] * MatB;

            }

            Multiple.Set_Element(i, j, temp);

        }

    }

    return Multiple;

}
// Set Matrix diagonal
void Matrix::setdiagonal(const Vector3D& vec) {
    this->MatrixArray[0][0] = this->MatrixArray[2][2] = 0.0;
    this->MatrixArray[3][3]= this->MatrixArray[5][5] = 0.0;
    this->MatrixArray[6][6] = this->MatrixArray[7][7] = 0.0;

    this->MatrixArray[0][0] = vec.x;
    this->MatrixArray[4][4] = vec.y;
    this->MatrixArray[6][6] = vec.z;
}
/// Matrix Multiplication operator with Vector
/// Multiple Matrix with Vector together
///error class Matrix has no member named "x,y,z"
/*
void Matrix ::operator*(const Vector3D& vec){
    Matrix Multvec;
    unsigned i,j;
    double VecMultipleArray[3];
    double MultipleValue = (vec.x*this->MatrixArray[i][0] + vec.y*this->MatrixArray[i][1] + vec.z*this->MatrixArray[i][2]);
    VecMultipleArray[i]=MultipleValue;
    Multvec.x = vec.x*this->MatrixArray[i][0];
    Multvec.y = vec.y*this->MatrixArray[i][1];
    Multvec.z = vec.z*this->MatrixArray[i][2];

    return Multvec;
}
*/
// Matrix Multiplication operator with Scalar
// Multiple Matrix with Scalar together
Matrix Matrix::operator*(double Scalar)
{
    Matrix MultipleScalar;

    unsigned i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

           MultipleScalar.Set_Element(i, j, this->MatrixArray[i][j] * Scalar);
        }

    }

    return MultipleScalar;
}


//Matrix  inverse function
Matrix Matrix::Inverse()
{
    // computes the inverse of a matrix m
    double Det = (this->MatrixArray[0][0] * ((this->MatrixArray[1][1] * this->MatrixArray[2][2])
        - (this->MatrixArray[2][1] * this->MatrixArray[1][2]))

        - this->MatrixArray[0][1] * ((this->MatrixArray[1][0] * this->MatrixArray[2][2])
            - (this->MatrixArray[2][0] * this->MatrixArray[1][2]))

        + this->MatrixArray[0][2] * ((this->MatrixArray[1][0] * this->MatrixArray[2][1])
            - (this->MatrixArray[2][0] * this->MatrixArray[1][1])));
    double Inverse = 1/Det;

    if (Det == 0)
    {
        // Identity matrix
        Matrix InverseMat;

        return InverseMat;
    }


    // Inverse Matrix
       Matrix InverseMat((this->MatrixArray[1][1] * this->MatrixArray[2][2])
        - (this->MatrixArray[2][1] * this->MatrixArray[1][2]),

        (this->MatrixArray[1][0] * this->MatrixArray[2][2])
        - (this->MatrixArray[2][0] * this->MatrixArray[1][2]),

        (this->MatrixArray[1][0] * this->MatrixArray[2][1])
        - (this->MatrixArray[2][0] * this->MatrixArray[1][1]),

        (this->MatrixArray[0][1] * this->MatrixArray[2][2])
        - (this->MatrixArray[2][1] * this->MatrixArray[0][2]),

        (this->MatrixArray[0][0] * this->MatrixArray[2][2])
        - (this->MatrixArray[2][0] * this->MatrixArray[0][2]),

        (this->MatrixArray[0][0] * this->MatrixArray[2][1])
        - (this->MatrixArray[2][0] * this->MatrixArray[0][1]),

        (this->MatrixArray[0][1] * this->MatrixArray[1][2])
        - (this->MatrixArray[1][1] * this->MatrixArray[0][2]),

        (this->MatrixArray[0][0] * this->MatrixArray[1][2])
        - (this->MatrixArray[1][0] * this->MatrixArray[0][2]),

        (this->MatrixArray[0][0] * this->MatrixArray[1][1])
        - (this->MatrixArray[1][0] * this->MatrixArray[0][1]));



    unsigned i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            if ((((i * 3) + j) % 2) == 1) {

                double MatB;
                InverseMat.Get_Element(i, j, &MatB);

                InverseMat.Set_Element(i, j, (MatB * -1));

            }

        }
    }
    InverseMat = InverseMat.Transpose();

    // Find the Inverse by divided by Det
    InverseMat = InverseMat * ((double)1/ Det);

    return InverseMat;

}


// Matrix transpose function
Matrix Matrix::Transpose()
{
    Matrix Transpose;

    unsigned i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            Transpose.Set_Element(i, j, this->MatrixArray[j][i]);

        }

    }

    return Transpose;

}
//Matrix rotation X-AXIS
void Matrix::RotateX(double Theta){
	double angle;
	angle = Theta * PI / 180.0;
    this->SetMatrix(1.0, 0.0, 0.0,
          0.0, cos(angle),-sin(angle),
		  0.0, sin(angle), cos(angle));
}
//Matrix rotation Y-AXIS
void Matrix::RotateY(double Theta){
	double angle;
	angle = Theta * PI / 180.0;
    this->SetMatrix(cos(angle), 0.0, sin(angle),
          0.0, 1.0,0.0,
		  -sin(angle), 0.0, cos(angle));
}
//Matrix rotation Z-AXIS
void Matrix::RotateZ(double Theta){
	double angle;
	angle = Theta * PI / 180.0;
    this->SetMatrix(cos(angle),-sin(angle) ,0.0,
                   sin(angle),cos(angle), 0.0,
                   0.0, 0.0 ,1.0);
}
// ResetMatrix
void Matrix::SetMatrix(double a, double b, double c,double d, double e, double f,double g, double h, double z) {

    double elements[] = { a, b, c, d, e, f, g, h, z};
    unsigned i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            this->MatrixArray[i][j] = elements[(i * 3) + j];

        }
    }
}



bool Matrix::Set_Element(int i, int j, double MatB)
{
    if (i < 0 && j > 3 && i < 0 && j > 3)
    {
        return false; // Not valid row or col
    }

    this->MatrixArray[i][j] = MatB;

    return true; // Set Element successful
}



// -------------------------------------------------------------------------------------------------
// GetElement returns the value of a certain element in a chosen position

bool Matrix::Get_Element(int i, int j, double* Element) const
{
    if (i< 0 && j > 3 && i < 0 && j > 3)
    {

        return false; // Not valid row or col

    }
    else
    {

        *Element = this->MatrixArray[i][j];

        return true;

    }

}
//Matrix Output
void Matrix::OutputMatrix() {

    unsigned i, j;

    for (i = 0; i < 3; 	i++) {
       for (j = 0; j < 3; j++) {

            if (i == j) {

            	cout<< "Matrix = " <<endl;
                cout << this->MatrixArray[i][j] <<endl;
            }
            else {

                cout<< "error" <<endl;
            }
        }
    }
    return;
}





