//
// Created by 徐宇帆 on 18/11/24.
//

#ifndef GP_DVC_DIVIDE_AND_CONQUER_H
#define GP_DVC_DIVIDE_AND_CONQUER_H

#include "Matrix.h"

Matrix Divide_and_Conquer(Matrix &A, Matrix &B, int ar, int ac, int br, int bc, int n)
{
    Matrix temp(n);

   if(n == 1)
    {
        temp(0,0) = A(ac, ar) * B(bc, br);
    } else if (( n * n ) % 2 != 0){
        cout << "Not Possible." << endl;
        exit(1);
    } else {
        temp.setSubMatrix(0, 0, n / 2, n / 2,
                         Divide_and_Conquer(A, B, ar, ac, br, bc, n / 2),
                         Divide_and_Conquer(A, B, ar, ac + (n / 2), br + (n / 2), bc, n / 2));

        temp.setSubMatrix(0, n / 2, n / 2, n,
                         Divide_and_Conquer(A, B, ar, ac, br, bc + (n / 2), n / 2),
                         Divide_and_Conquer(A, B, ar, ac + (n / 2), br + (n / 2), bc + (n / 2), n / 2));

        temp.setSubMatrix(n / 2, 0, n, n / 2,
                         Divide_and_Conquer(A, B, ar + (n / 2), ac, br, bc, n / 2),
                         Divide_and_Conquer(A, B, ar + (n / 2), ac + (n / 2), br + (n / 2), bc, n / 2));

        temp.setSubMatrix(n / 2, n / 2, n, n,
                         Divide_and_Conquer(A, B, ar + (n / 2), ac, br, bc + (n / 2), n / 2),
                         Divide_and_Conquer(A, B, ar + (n / 2), ac + (n / 2), br + (n / 2), bc + (n / 2), n / 2));
    }

    return temp;
}

#endif //GP_DVC_DIVIDE_AND_CONQUER_H
