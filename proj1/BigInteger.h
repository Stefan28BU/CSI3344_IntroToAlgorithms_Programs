//
// Created by 徐宇帆 on 18/9/6.
//

#ifndef PROJ1_BIGINTEGER_H
#define PROJ1_BIGINTEGER_H
#include <ostream>
#include <vector>
#include <string.h>
using namespace std;

class BigInteger{
public:
    BigInteger(): sign{'+'}, size{1}{
        data = new char[1];
        data [0] = '0';
    }

    ~BigInteger(){
        delete [] data;
    }

    BigInteger(const BigInteger&);
    BigInteger(BigInteger&&);
    BigInteger(const string&);
    BigInteger(const char*);

    int getSize() const {return size;}

    BigInteger& operator= (const BigInteger&);
    BigInteger& operator= (BigInteger&&);
    BigInteger add(const BigInteger&) const;
    BigInteger subtract(const BigInteger&) const;
    BigInteger multiply(const BigInteger&) const;
    BigInteger divide(const BigInteger&) const;
    BigInteger absoluteValue() const;
    bool isPrime( ) const;
    vector<BigInteger> primeFactors() const;
    void display(ostream&) const;

    bool operator<  (const BigInteger&) const;
    bool operator<= (const BigInteger&) const;
    bool operator>  (const BigInteger&) const;
    bool operator>= (const BigInteger&) const;
    bool operator== (const BigInteger&) const;

    BigInteger operator+ (const BigInteger&) const;
    BigInteger operator- (const BigInteger&) const;
    BigInteger operator* (const BigInteger&) const;
    BigInteger operator/ (const BigInteger&) const;

private:
    char *data;
    char sign;
    unsigned int  size;

};
#endif //PROJ1_BIGINTEGER_H
