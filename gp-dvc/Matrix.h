//
// Created by 徐宇帆 on 18/11/24.
//

#ifndef GP_DVC_MATRIX_H
#define GP_DVC_MATRIX_H

#include <vector>
#include <iostream>
#include <time.h>
#include <math.h>
#include <iomanip>

using namespace std;

class Matrix {

private:
    vector<vector<int>> data;
    unsigned int n; 	//row and column size of matrix

public:
    Matrix(){}
    Matrix(unsigned int n);
    Matrix(const Matrix& other);
    ~Matrix(){}

    Matrix& operator+=(const Matrix& other);
    Matrix& operator=(const Matrix& other);

    int& operator()(const unsigned int& row, const unsigned int& col);
    const int& operator()(const unsigned int& row, const unsigned int& col) const;

    unsigned int getN() const;

    void setSubMatrix(const int, const int, const int, const int, const Matrix&, const Matrix&);
    static Matrix DC1(Matrix &A, Matrix &B, int ar, int ac, int br, int bc, int n);


    void print();
};


/*
 *    description: Constructor
 *  pre-condition: Nothing
 * post-condition: An instance of the class object is made of size n,  and
 *                  elements of each row are initialized to 0
 *         return: Nothing
 */
Matrix::Matrix(unsigned int n) {
    data.resize(n, std::vector<int>(n, 0));
    this->n = n;
    /*
    this->data.resize(n);
    for (unsigned i=0; i < this-> data.size(); i++) {
        this->data[i].resize(n);
    }

    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < n; j++) {
            this->data[i][j] = 0;
        }
    }

    this->n = n;
    */
}

/*
 *    description: Copy constructor
 *  pre-condition: A Matrix object exists
 * post-condition: A copy of the class object that is made
 *         return: Nothing
 */
Matrix::Matrix(const Matrix& other) {
    this->data = other.data;
    this->n = other.n;
}

/*
 *    description: Assignment Operator
 *  pre-condition: Two Matrix object exist
 * post-condition: This Matrix is equivalent to the other Matrix
 *         return: A Matrix object
 */
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other){

        unsigned int temp = other.getN();

        this->data.resize(temp);
        for (unsigned int i = 0; i < this->data.size(); i++) {
            this->data[i].resize(temp);
        }

        for (unsigned int i = 0; i < temp; i++) {
            for (unsigned int j = 0; j < temp; j++) {
                this->data[i][j] = other(i,j);
            }
        }
        this->n = temp;
    }
    return *this;
}

/*
 *    description: Overloaded += operator
 *  pre-condition: Two Matrix object exist
 * post-condition: This Matrix is added to the other Matrix and the result is
 *                   saved in this matrix
 *         return: A Matrix object
 */
Matrix& Matrix::operator+=(const Matrix& other) {
    unsigned int n = other.getN();

    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < n; j++) {
            this->data[i][j] += other(i,j);
        }
    }

    return *this;
}

/*
 *    description: Overloaded () operator
 *  pre-condition: A Matrix object exists, row and col value are passed by value
 * post-condition: The value at data[row][col] is found
 *         return: An integer: the element at data[row][col]
 */
int& Matrix::operator()(const unsigned int& row, const unsigned int& col) {
    return this->data[row][col];
}

/*
 *    description: Overloaded () operator
 *  pre-condition: A Matrix object exists, row and col value are passed by value
 * post-condition: The value at data[row][col] is found
 *         return: An integer: the element at data[row][col]
 */
const int& Matrix::operator()(const unsigned int& row, const unsigned int& col)
const{
    return this->data[row][col];
}

/*
 *    description: Get the row/column size
 *  pre-condition: A Matrix object exists
 * post-condition: The value of n is returned
 *         return: An unsigned integer: the value of n
 */
unsigned int Matrix::getN() const {
    return this->n;
}

/*
 *    description: Set a sub-matrix from two matrices
 *  pre-condition: A Matrix object exists
 * post-condition: The sub-matrix is initialized
 *         return: void
 */
void Matrix::setSubMatrix(const int r, const int c, const int rn, const int cn, const Matrix &A, const Matrix &B) {
    for (int i = c; i < cn; i++) {
        for (int j = r; j < rn; j++) {
            data[i][j] = A.data[i - c][j - r] + B.data[i - c][j - r];
        }
    }
}

/*
 *    description: display a matrix to stdout
 *  pre-condition: A Matrix object exists
 * post-condition: the matrix is print to screen
 *         return: void
 */
void Matrix::print() {
    for(int i = 0; i < data.size(); i++)
    {
        for(int j = 0; j < data[0].size(); j++)
        {
            cout << left << setw(3) << data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

Matrix Matrix::DC1(Matrix &A, Matrix &B, int ar, int ac, int br, int bc, int n) {
    Matrix C(n);

    if(n == 1)
    {
        C.data[0][0] = A.data[ac][ar] * B.data[bc][br];
    }
    else
    {
        C.setSubMatrix(0, 0, n / 2, n / 2,
                       DC1(A, B, ar, ac, br, bc, n / 2),
                       DC1(A, B, ar, ac + (n / 2), br + (n / 2), bc, n / 2));

        C.setSubMatrix(0, n / 2, n / 2, n,
                       DC1(A, B, ar, ac, br, bc + (n / 2), n / 2),
                       DC1(A, B, ar, ac + (n / 2), br + (n / 2), bc + (n / 2), n / 2));

        C.setSubMatrix(n / 2, 0, n, n / 2,
                       DC1(A, B, ar + (n / 2), ac, br, bc, n / 2),
                       DC1(A, B, ar + (n / 2), ac + (n / 2), br + (n / 2), bc, n / 2));

        C.setSubMatrix(n / 2, n / 2, n, n,
                       DC1(A, B, ar + (n / 2), ac, br, bc + (n / 2), n / 2),
                       DC1(A, B, ar + (n / 2), ac + (n / 2), br + (n / 2), bc + (n / 2), n / 2));
    }

    return C;
}


#endif //GP_DVC_MATRIX_H
