/*
* BigInteger.h
*
* Created on: Jun 4, 2018
* Author: Dr. Booth
*
* DO NOT MODIFY THIS CODE
*/

/*
* Author:                 Yufan Xu
* Assignment Title:       BigInteger
* Assignment Description: This program presents series of operations in a
*                         class called 'BigInteger'. Including addition,
*                         subtraction, multiplication, division,
*                         absolute value, and series of operators, big
*                         five, and print function. It will be tested
*                         by a driver on the upload site
* Due Date:               09/16/2018
* Date Created:           09/10/2018
* Date Last Modified:     09/16/2018
*/

#ifndef NP1_BIGINTEGER_H
#define NP1_BIGINTEGER_H

#include "iostream"
#include <ostream>
#include <vector>
#include <string.h>
using namespace std;

class BigInteger{
public:
    /*
    * description: default constructor
    * return: none
    * precondition: nothing is passed
    * postcondition: construct with default value
    */
    BigInteger(): sign{'+'}, size{1}{
        data = new char[1];
        data [0] = '0';
    }

    /*
    * description: destructor
    * return: none
    * precondition: object out of scope
    * postcondition: clear data
    */
    ~BigInteger(){
        delete [] data;
    }

    /*
    * description: copy constructor
    * return: none
    * precondition: object is passed
    * postcondition: a copy is made
    */
    BigInteger(const BigInteger&);

    /*
    * description: move constructor
    * return: none
    * precondition: object out of scope
    * postcondition: a copy is made to the left value
    */
    BigInteger(BigInteger&&);

    /*
    * description: constructor
    * return: none
    * precondition: an object is passed
    * postcondition: a copy is made
    */
    BigInteger(const string&);

    /*
    * description: constructor
    * return: none
    * precondition: an object is passed
    * postcondition: a copy is made
    */
    BigInteger(const char*);

    /*
    * description: get the size of current data
    * return: int
    * precondition: function is called by an object
    * postcondition: returns the size
    */
    int getSize() const {return size;}

    /*
    * description: assignment operator
    * return: *this
    * precondition: object is assigned to another
    * postcondition: a copy of left value is made and returned
    */
    BigInteger& operator= (const BigInteger&);

    /*
    * description: move assignment operator
    * return: *this
    * precondition: object out of scope
    * postcondition: returns a copy of R to L
    */
    BigInteger& operator= (BigInteger&&);

    /*
    * description: add two objects
    * return: BigInteger
    * precondition: add is called by the operator '+'
    * postcondition: returns the sum of two BigIntegers
    */
    BigInteger add(const BigInteger&) const;

    /*
    * description: subtract two objects
    * return: BigInteger
    * precondition: subtract is called by the operator '-'
    * postcondition: returns the difference of two BigIntegers
    */
    BigInteger subtract(const BigInteger&) const;

    /*
    * description: multiply two objects
    * return: BigInteger
    * precondition: function called by operator '*'
    * postcondition: returns the result as a BigInteger
    */
    BigInteger multiply(const BigInteger&) const;

    /*
    * description: divides two objects
    * return: BigInteger
    * precondition: function is called by operator '/'
    * postcondition: returns the result as a BigInteger
    */
    BigInteger divide(const BigInteger&) const;

    /*
    * description: calculate the absolute value of current data
    * return: BigInteger
    * precondition: function called by object
    * postcondition: returns the abs val of the object
    */
    BigInteger absoluteValue() const;

    /*
    * description: determine if the data is prime
    * return: bool
    * precondition: function is called by obj
    * postcondition: returns true if is prime false otherwise
    */
    bool isPrime( ) const;

    /*
    * description: calculate the prime factors of the object
    * return: a vector of of BigIntegers
    * precondition: function is called
    * postcondition: a vector of BigIntegers is returned
    */
    vector<BigInteger> primeFactors() const;

    /*
    * description: display object
    * return: void
    * precondition: function is called with parameters
    * postcondition: displays object on screen
    */
    void display(ostream&) const;

    /*
    * description: operator <
    * return: bool
    * precondition: operator is called
    * postcondition: returns true or false
    */
    bool operator<  (const BigInteger&) const;

    /*
    * description: operator <=
    * return: bool
    * precondition: operator is called
    * postcondition: returns true or false
    */
    bool operator<= (const BigInteger&) const;

    /*
    * description: operator >
    * return: bool
    * precondition: operator is called
    * postcondition: returns true or false
    */
    bool operator>  (const BigInteger&) const;

    /*
    * description: operator >=
    * return: bool
    * precondition: operator is called
    * postcondition: returns true or false
    */
    bool operator>= (const BigInteger&) const;

    /*
    * description: operator ==
    * return: bool
    * precondition: operator is called
    * postcondition: returns true or false
    */
    bool operator== (const BigInteger&) const;

    /*
    * description: operator +
    * return: BigInteger
    * precondition: operator is called
    * postcondition: returns a BigInteger
    */
    BigInteger operator+ (const BigInteger&) const;

    /*
    * description: operator -
    * return: BigInteger
    * precondition: operator is called
    * postcondition: returns a BigInteger
    */
    BigInteger operator- (const BigInteger&) const;

    /*
    * description: operator *
    * return: BigInteger
    * precondition: operator is called
    * postcondition: returns a BigInteger
    */
    BigInteger operator* (const BigInteger&) const;

    /*
    * description: operator /
    * return: BigInteger
    * precondition: operator is called
    * postcondition: returns a BigInteger
    */
    BigInteger operator/ (const BigInteger&) const;

    char getSign() {
        return this->sign;
    }

private:
    char *data;
    char sign;
    unsigned int size;

};


#endif //NP1_BIGINTEGER_H
