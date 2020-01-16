#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>


using namespace std;
using namespace std::chrono;


template<class T>
class Matrix
{
public:
    size_t n;
    Matrix(size_t n)
    {
        Data.resize(n, std::vector<T>(n, 0));
        this->n = n;
    }

    void SetSubMatrix(const int r, const int c, const int rn, const int cn, const Matrix<T>& A, const Matrix<T>& B)
    {
        for(int _c=c; _c<cn; ++_c)
        {
            for(int _r=r; _r<rn; ++_r)
            {
                Data[_c][_r] = A.Data[_c-c][_r-r] + B.Data[_c-c][_r-r];
            }
        }
    }
    static Matrix<T> Brute_Force(const Matrix<T>& mtxA, const Matrix<T>& mtxB){

        //only multiply if compatible
        if(mtxA.n == mtxB.n){
            unsigned int n = mtxA.n;
            Matrix mtxC(n);

            for(unsigned int r = 0; r < n; r++){
                for(unsigned int c = 0; c < n; c++){
                    for(unsigned int k = 0; k < n; k++){ //loop rows again
                        mtxC.Data[r][c] += mtxA.Data[r][c] * mtxB.Data[k][c];
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

    static Matrix<T> SquareMultiplyRecursive(Matrix<T>& A, Matrix<T>& B, int ar, int ac, int br, int bc, int n)
    {
        Matrix<T> C(n);

        if(n == 1)
        {
            C.Data[0][0] = A.Data[ac][ar] * B.Data[bc][br];
        }
        else
        {
            C.SetSubMatrix(0, 0, n / 2, n / 2,
                           SquareMultiplyRecursive(A, B, ar, ac, br, bc, n / 2),
                           SquareMultiplyRecursive(A, B, ar, ac + (n / 2), br + (n / 2), bc, n / 2));

            C.SetSubMatrix(0, n / 2, n / 2, n,
                           SquareMultiplyRecursive(A, B, ar, ac, br, bc + (n / 2), n / 2),
                           SquareMultiplyRecursive(A, B, ar, ac + (n / 2), br + (n / 2), bc + (n / 2), n / 2));

            C.SetSubMatrix(n / 2, 0, n, n / 2,
                           SquareMultiplyRecursive(A, B, ar + (n / 2), ac, br, bc, n / 2),
                           SquareMultiplyRecursive(A, B, ar + (n / 2), ac + (n / 2), br + (n / 2), bc, n / 2));

            C.SetSubMatrix(n / 2, n / 2, n, n,
                           SquareMultiplyRecursive(A, B, ar + (n / 2), ac, br, bc + (n / 2), n / 2),
                           SquareMultiplyRecursive(A, B, ar + (n / 2), ac + (n / 2), br + (n / 2), bc + (n / 2), n / 2));
        }

        return C;
    }

    void Print()
    {
        for(int c=0; c<Data.size(); ++c)
        {
            for(int r=0; r<Data[0].size(); ++r)
            {
                cout << Data[c][r] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    vector<vector<T> > Data;
};

int main()
{
    clock_t t;

    Matrix<int> A(16);
    Matrix<int> B(16);

    for (int i = 0; i < 16; i ++) {
        for (int j = 0; j < 16; j ++) {
            A.Data[i][j] = 4;
        }
    }

    for (int i = 0; i < 16; i ++) {
        for (int j = 0; j < 16; j ++) {
            B.Data[i][j] = 2;
        }
    }

    A.Print();
    B.Print();

    t = clock();
    Matrix<int> C(Matrix<int>::SquareMultiplyRecursive(A, B, 0, 0, 0, 0, 16));

    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    C.Print();

    t = clock();
    Matrix<int> D(Matrix<int>::Brute_Force(A, B));

    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    D.Print();
}