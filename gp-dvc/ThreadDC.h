
#ifndef GP_DVC_THREADDC_H
#define GP_DVC_THREADDC_H

#include <pthread.h>
#include "Matrix.h"

using namespace std;



struct Mats{
    Matrix xa, xb, res;
    int n, myCount;
};
//Description: thread function that multiplies matrix section
//Return: void pointer
//Precondition: a thread is created and three matrices exist
//Postcondition: two matrices are multiplied into the third
void *tMult(void *arg){
    Mats *vals = (Mats *)arg;
    int x = vals->myCount;
    for(int i=x*vals->n/4; i<(x+1)*vals->n/4; i++){
        for(int j=0; j<vals->n; j++){
            for(int k=0; k<vals->n; k++){
                vals->res(i,j) += vals->xa(i,k)*vals->xb(k,j);
            }
        }
    }
    pthread_exit(NULL);
}

//Description: creates threads to split matrix multiplication
//Return: Matrix
//PreCondition: three matrices exist
//PostCondition: two matrices are multiplied into the third
Matrix TDaC2(Matrix &A, Matrix &B, int n){

    Matrix result(n);

    Mats vals[4];
    vals[0].xa = A;
    vals[0].xb = B;
    vals[0].res = result;
    vals[0].n = A.getN();
    vals[0].myCount=0;
    vals[1].xa = A;
    vals[1].xb = B;
    vals[1].res = result;
    vals[1].n = A.getN();
    vals[1].myCount=1;
    vals[2].xa = A;
    vals[2].xb = B;
    vals[2].res = result;
    vals[2].n = A.getN();
    vals[2].myCount=2;
    vals[3].xa = A;
    vals[3].xb = B;
    vals[3].res = result;
    vals[3].n = A.getN();
    vals[3].myCount=3;

    pthread_t children[4];
    for(int i=0; i<4; i++){
        pthread_create(&children[i], NULL, tMult, &vals[i]);
    }

    for(int i=0; i<4; i++){
        pthread_join(children[i], NULL);
    }

    result += vals[0].res;
    result += vals[1].res;
    result += vals[2].res;
    result += vals[3].res;

    return result;

}

#endif //GP_DVC_THREADDC_H
