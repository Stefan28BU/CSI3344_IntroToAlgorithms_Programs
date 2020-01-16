//
// Created by 徐宇帆 on 18/12/1.
//

#ifndef GP_DVC_STRASSEN_H
#define GP_DVC_STRASSEN_H

#include <iostream>
#include <cmath>
#include "Matrix.h"

using namespace std;

int leafsize = 8;

/*
 *    description: Multiply the two matrix
 *  pre-condition: Matrix are valid and int n is power of 2
 * post-condition: Store the value in Matrix C
 *         return: Nothing
 */

void Mul(Matrix A,
         Matrix B,
         Matrix &C, int n) {

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                C(i,j) += A(i,k) * B(k,j);
            }
        }
    }
}


/*
 *    description: Sum the two matrix
 *  pre-condition: Matrix are valid and int n is power of 2
 * post-condition: Store the value in Matrix C
 *         return: Nothing
 */
void sum(Matrix &A,
         Matrix &B,
         Matrix &C, int tam) {
    int i, j;


    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            C(i,j) = A(i,j) + B(i,j);
        }
    }
}


/*
 *    description: Subtract the two matrix
 *  pre-condition: Matrix are valid and int n is power of 2
 * post-condition: Store the value in Matrix C
 *         return: Nothing
 */
void subtract(Matrix &A,
              Matrix &B,
              Matrix &C, int tam) {
    int i, j;

    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            C(i,j) = A(i,j) - B(i,j);
        }
    }
}


/*
 *    description: Do Strassen Algorithm
 *  pre-condition: Matrix are valid and int n is valid
 * post-condition: Store the value in Matrix C
 *         return: Nothing
 */
void strassenR(Matrix &A,
               Matrix &B,
               Matrix &C, int tam) {

    if (tam <= leafsize) {
        Mul(A, B, C, tam);
        return;
    }

        // other cases are treated here:
    else {
        int newTam = tam/2;
        vector<int> inner (newTam);
        Matrix
                a11(newTam), a12(newTam), a21(newTam), a22(newTam),
                b11(newTam), b12(newTam), b21(newTam), b22(newTam),
                c11(newTam), c12(newTam), c21(newTam), c22(newTam),
                p1(newTam), p2(newTam), p3(newTam), p4(newTam),
                p5(newTam), p6(newTam), p7(newTam),
                aResult(newTam), bResult(newTam);

        int i, j;

        //dividing the matrices in 4 sub-matrices:
        for (i = 0; i < newTam; i++) {
            for (j = 0; j < newTam; j++) {
                a11(i,j) = A(i,j);
                a12(i,j) = A(i,j + newTam);
                a21(i,j) = A(i + newTam,j);
                a22(i,j) = A(i + newTam,j + newTam);

                b11(i,j) = B(i,j);
                b12(i,j) = B(i,j + newTam);
                b21(i,j) = B(i + newTam,j);
                b22(i,j) = B(i + newTam,j + newTam);
            }
        }

        // Calculating p1 to p7:

        sum(a11, a22, aResult, newTam); // a11 + a22
        sum(b11, b22, bResult, newTam); // b11 + b22
        strassenR(aResult, bResult, p1, newTam); // p1 = (a11+a22) * (b11+b22)

        sum(a21, a22, aResult, newTam); // a21 + a22
        strassenR(aResult, b11, p2, newTam); // p2 = (a21+a22) * (b11)

        subtract(b12, b22, bResult, newTam); // b12 - b22
        strassenR(a11, bResult, p3, newTam); // p3 = (a11) * (b12 - b22)

        subtract(b21, b11, bResult, newTam); // b21 - b11
        strassenR(a22, bResult, p4, newTam); // p4 = (a22) * (b21 - b11)

        sum(a11, a12, aResult, newTam); // a11 + a12
        strassenR(aResult, b22, p5, newTam); // p5 = (a11+a12) * (b22)

        subtract(a21, a11, aResult, newTam); // a21 - a11
        sum(b11, b12, bResult, newTam); // b11 + b12
        strassenR(aResult, bResult, p6, newTam); // p6 = (a21-a11) * (b11+b12)

        subtract(a12, a22, aResult, newTam); // a12 - a22
        sum(b21, b22, bResult, newTam); // b21 + b22
        strassenR(aResult, bResult, p7, newTam); // p7 = (a12-a22) * (b21+b22)

        // calculating c21, c21, c11 e c22:

        sum(p3, p5, c12, newTam); // c12 = p3 + p5
        sum(p2, p4, c21, newTam); // c21 = p2 + p4

        sum(p1, p4, aResult, newTam); // p1 + p4
        sum(aResult, p7, bResult, newTam); // p1 + p4 + p7
        subtract(bResult, p5, c11, newTam); // c11 = p1 + p4 - p5 + p7

        sum(p1, p3, aResult, newTam); // p1 + p3
        sum(aResult, p6, bResult, newTam); // p1 + p3 + p6
        subtract(bResult, p2, c22, newTam); // c22 = p1 + p3 - p2 + p6

        // Grouping the results obtained in a single matrix:
        for (i = 0; i < newTam ; i++) {
            for (j = 0 ; j < newTam ; j++) {
                C(i,j) = c11(i,j);
                C(i,j + newTam) = c12(i,j);
                C(i + newTam,j) = c21(i,j);
                C(i + newTam,j + newTam) = c22(i,j);
            }
        }
    }
}


/*
 *    description: find the next int that is power of 2
 *  pre-condition: int n are valid
 * post-condition: get the next int which is in power of 2
 *         return: unsigned int
 */
unsigned int nextPowerOfTwo(int n) {
    return pow(2, int(ceil(log2(n))));
}


/*
 *    description: Where call the StrassenR function and get the result and store it
 *  pre-condition: Matrix are valid and int n is power of 2
 * post-condition: Store the value in Matrix C
 *         return: Nothing
 */
void strassen(Matrix &A,
              Matrix &B,
              Matrix &C, unsigned int n) {
    //unsigned int n = tam;
    unsigned int m = nextPowerOfTwo(n);
    vector<int> inner(m);
    Matrix APrep(m), BPrep(m), CPrep(m);

    for(unsigned int i=0; i<n; i++) {
        for (unsigned int j=0; j<n; j++) {
            APrep(i,j) = A(i,j);
            BPrep(i,j) = B(i,j);
        }
    }

    strassenR(APrep, BPrep, CPrep, m);
    for(unsigned int i=0; i<n; i++) {
        for (unsigned int j=0; j<n; j++) {
            C(i,j) = CPrep(i,j);
        }
    }
}


#endif //GP_DVC_STRASSEN_H
