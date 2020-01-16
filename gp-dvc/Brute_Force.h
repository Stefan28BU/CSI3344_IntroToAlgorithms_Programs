//
// Created by 徐宇帆 on 18/11/24.
//

#ifndef GP_DVC_BRUTE_FORCE_H
#define GP_DVC_BRUTE_FORCE_H

#include "Matrix.h"

Matrix Brute_Force(const Matrix& mtxA, const Matrix& mtxB){

    //only multiply if compatible
    if(mtxA.getN() == mtxB.getN()){

        unsigned int n = mtxA.getN();
        Matrix mtxC(n);

        for(unsigned int r = 0; r < n; r++){
            for(unsigned int c = 0; c < n; c++){
                for(unsigned int k = 0; k < n; k++){ //loop rows again
                    mtxC(r,c) += mtxA(r,k) * mtxB(k,c);
                }
            }
        }
        return mtxC;
    }
    else{
        Matrix mtxC(0);
        return mtxC;
    }
}

#endif //GP_DVC_BRUTE_FORCE_H
