#include <iostream>
#include <vector>

template<class T>
struct Matrix
{
    std::vector<std::vector<T> > Data;

    Matrix(size_t r, size_t c)
    {
        Data.resize(c, std::vector<T>(r, 0));
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

    static Matrix<T> SquareMultiplyRecursive(Matrix<T>& A, Matrix<T>& B, int ar, int ac, int br, int bc, int n)
    {
        Matrix<T> C(n, n);

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
                std::cout << Data[c][r] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
};

int main()
{
    Matrix<int> A(2, 2);
    Matrix<int> B(2, 2);
    A.Data[0][0] = 2;
    A.Data[0][1] = 1;
    A.Data[1][0] = 1;
    A.Data[1][1] = 2;

    B.Data[0][0] = 2;
    B.Data[0][1] = 1;
    B.Data[1][0] = 1;
    B.Data[1][1] = 2;

    A.Print();
    B.Print();

    Matrix<int> C(Matrix<int>::SquareMultiplyRecursive(A, B, 0, 0, 0, 0, 2));

    C.Print();
}