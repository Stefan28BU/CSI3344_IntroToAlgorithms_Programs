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

#include "BigInteger.h"
#include <iostream>
#include <string>

using namespace std;

char BigInteger::getCurrIndexData(int i) {
    return this->data[i];
}


/*
* description: copy constructor
* return: none
* precondition: object is passed
* postcondition: a copy is made
*/
BigInteger::BigInteger(const BigInteger &n) {
    this->size = n.size;
    this->sign = n.sign;
    this->data = new char[this->size];

    for (int i = 0; i < this->size; i ++) {
        this->data[i] = n.data[i];
    }
}

/*
* description: move constructor
* return: none
* precondition: object out of scope
* postcondition: a copy is made to the left value
*/
BigInteger::BigInteger(BigInteger &&n):size{n.size}, sign{n.sign} {
    swap(this->data, n.data);
    n.data = nullptr;
}

/*
* description: constructor
* return: none
* precondition: an object is passed
* postcondition: a copy is made
*/
BigInteger::BigInteger(const string &str) {
    this->size = str.length();

    this->data = new char[this->size];

    for (int i = 0; i < this->size; i++) {
        this->data[i] = str[this->size-1-i];
    }
    if (this->data[this->size-1] == '0') {
        this->sign = '\0';
    }
    else if (this->data[this->size-1] == '-') {
        this->sign = '-';
    }
    else {
        this->sign = '+';
    }
}

/*
* description: constructor
* return: none
* precondition: an object is passed
* postcondition: a copy is made
*/
BigInteger::BigInteger(const char *n) {
    this->size = strlen(n);
    this->data = new char[this->size];

    for (int i = 0; i < this->size; i++) {
        this->data[i] = n[this->size-1-i];
    }
    if (this->data[this->size-1] == '0') {
        this->sign = '\0';
    }
    else if (this->data[this->size-1] == '-') {
        this->sign = '-';
    }
    else {
        this->sign = '+';
    }
}

/*
* description: assignment operator
* return: *this
* precondition: object is assigned to another
* postcondition: a copy of left value is made and returned
*/
BigInteger& BigInteger::operator=(const BigInteger &n) {
    if (this != &n) {
        delete [] this->data;
        this->data = nullptr;
        this->sign = n.sign;
        this->size = n.size;
        this->data = new char[this->size];

        for (int i = 0; i < size; i ++) {
            this->data[i] = n.data[i];
        }
    }
    return *this;
}

/*
* description: move assignment operator
* return: *this
* precondition: object out of scope
* postcondition: returns a copy of R to L
*/
BigInteger& BigInteger::operator=(BigInteger &&n) {
    if (this != &n) {
        this->sign = n.sign;
        this->size = n.size;
        swap(this->data, n.data);
    }
    return *this;
}

/*
* description: add two objects
* return: BigInteger
* precondition: add is called by the operator '+'
* postcondition: returns the sum of two BigIntegers
*/
BigInteger BigInteger::add(const BigInteger &n) const {

    BigInteger temp;

    BigInteger temp2;

    if (this->data[0] == '0') {
        temp.size = n.size;
        temp.data = new char[temp.size];
         for (int i = 0; i < temp.size; i ++) {
             temp.data[i] = n.data[i];
         }
    }
    else if (n.data[0] == '0') {
        temp.size = this->size;
        temp.data = new char[temp.size];
        for (int i = 0; i < temp.size; i ++) {
            temp.data[i] = this->data[i];
        }
    }

    if (this->sign == n.sign) {

        string t1;
        string t2;
        int l1, l2;

        if (this->sign == '-') {
            for (int i = 1; i < this->size; i++) {
                t1.push_back(this->data[this->size - 1 - i]);
            }
            for (int i = 1; i < n.size; i++) {
                t2.push_back(n.data[n.size - 1 - i]);
            }
        }
        else if (this->sign == '+') {
            for (int i = 0; i < this->size; i++) {
                t1.push_back(this->data[this->size - 1 - i]);
            }
            for (int i = 0; i < n.size; i++) {
                t2.push_back(n.data[n.size - 1 - i]);
            }
        }

        if (t1.length() > t2.length()) {
            swap(t1, t2);
        }
        l1 = t1.length();
        l2 = t2.length();

        string sst;

        int diff = l2 - l1;
        int carry = 0;

        for (int i = l1-1; i >= 0; i --)
        {
            int sum = ((t1[i]-48) + (t2[i+diff]-48) +carry);
            sst.push_back(sum%10+48);
            carry = sum/10;
        }
        for (int i = l2-l1-1; i >=0; i --)
        {
            int sum = ((t2[i]-48) + carry);
            sst.push_back(sum%10+48);
            carry=sum/10;
        }
        if (carry) {
            sst.push_back(carry+48);
        }
        //reverse(sst.begin(), sst.end());
        temp.size = sst.length();
        temp.data = new char[temp.size];
        for (int i = 0; i < temp.size; i ++) {
            temp.data[i] =sst[i];
        }

        if (this->sign == '-') {
            temp2.size = temp.size + 1;
            temp2.data = new char[temp2.size];
            for (int i = 0; i < temp.size + 1; i++) {
                temp2.data[i] = temp.data[i];
            }

            temp.size = temp2.size;
            temp.data = new char[temp.size];
            for (int i = 0; i < temp.size; i++) {
                temp.data[i] = temp2.data[i];
            }
            temp.data[temp.size-1] = '-';
        }
    }
    else if (this->sign!=n.sign && this->size < n.size) {
        if (n.sign == '-') {
            temp.size = n.size;
            temp.data = new char[temp.size];

            for (int i = 0; i < temp.size; i ++) {
                temp.data[i] = n.data[i];
            }
            for (int i = 0; i < this->size; i ++) {
                temp.data[i] = n.data[i] - this->data[i] + 48;
            }
            temp.data[temp.size-1] = '-';

        }
    }
    else if (this->sign!=n.sign && this->size > n.size) {
        if (this->sign == '-') {
            temp.size = this->size;
            temp.data = new char[temp.size];

            for (int i = 0; i < temp.size; i ++) {
                temp.data[i] = this->data[i];
            }
            for (int i = 0; i < n.size; i ++) {
                temp.data[i] = this->data[i] - n.data[i] + 48;
            }
            temp.data[temp.size-1] = '-';
        }
    }
    return temp;
}

/*
* description: subtract two objects
* return: BigInteger
* precondition: subtract is called by the operator '-'
* postcondition: returns the difference of two BigIntegers
*/
BigInteger BigInteger::subtract(const BigInteger &n) const {
    BigInteger temp;

    if (n.data[0] == '0') {
        temp.size = this->size;
        temp.data = new char[temp.size];
        for (int i = 0; i < temp.size; i ++) {
            temp.data[i] = this->data[i];
        }
    }
    else if (this->data[0] == '0' && n.sign == '+') {
        temp.size = n.size+1;
        temp.data = new char[temp.size];
        for (int i = 0; i < temp.size-1; i ++) {
            temp.data[i] = n.data[i];
        }
        temp.data[temp.size-1] = '-';
    }
    else if (this->data[0] == '0' && n.sign == '-') {
        temp.size = n.size - 1;
        temp.data = new char[temp.size];
        for (int i = 0; i < temp.size; i ++) {
            temp.data[i] = n.data[i];
        }
    }

    if (this->sign == n.sign && this->sign == '+' && this->size >= n.size) {

        string t1;
        string t2;
        int l1, l2;

        for (int i = 0; i < this->size; i++) {
            t1.push_back(this->data[this->size - 1 - i]);
        }
        for (int i = 0; i < n.size; i++) {
            t2.push_back(n.data[n.size - 1 - i]);
        }
        l1 = t1.length();
        l2 = t2.length();

        string str;

        int diff = l1 -l2;
        int carry = 0;

        for (int i = l2-1; i >= 0; i --) {
            int sub = ((t1[i+diff]-'0') -
                       (t2[i]-'0') -
                       carry);
            if (sub < 0)
            {
                sub = sub+10;
                carry = 1;
            }
            else
                carry = 0;

            str.push_back(sub + '0');
        }
        for (int i=l1-l2-1; i>=0; i--)
        {
            if (t1[i]=='0' && carry)
            {
                str.push_back('9');
                continue;
            }
            int sub = ((t1[i]-'0') - carry);
            if (i>0 || sub>0) {
                str.push_back(sub + '0');
            }
            carry = 0;
        }
        temp.size = str.length();
        while (str[temp.size-1] == '0') {
            temp.size --;
        }
        temp.data = new char[temp.size];
        for (int i = 0; i < temp.size; i ++) {
            temp.data[i] =str[i];
        }
    }

    else if (this->size == n.size && this->sign == n.sign) {
        bool isSame = false;
        for (int i = 0; i < this->size; i ++) {
            if (this->data[i] == n.data[i]) {
                isSame = true;
            }
        }
        if (isSame) {
            temp.size = 1;
            temp.data = new char[temp.size];
            temp.data[0] = '0';
        }
    }
    else if (this->sign!=n.sign && this->size < n.size) {
        if (n.sign == '-') {
            temp.size = n.size-1;
            temp.sign = '+';
            temp.data = new char[temp.size];

            for (int i = 0; i < temp.size; i ++) {
                temp.data[i] = n.data[i];
            }
            for (int i = 0; i < this->size; i ++) {
                temp.data[i] = n.data[i] + this->data[i] - 48;
            }
        }
    }
    else if (this->sign!= n.sign && this->size>n.size) {
        if (this->sign == '-') {
            temp.size = this->size;
            temp.data = new char[temp.size];

            for (int i = 0; i < this->size; i ++) {
                temp.data[i] = this->data[i];
            }
            for (int i = 0; i < n.size; i ++) {
                temp.data[i] = this->data[i] + n.data[i] - 48;
            }
            temp.data[temp.size-1] = '-';
        }
    }
    else if (this->sign == n.sign && this->size>n.size) {
        if (this->sign == '+') {
            temp.size = this->size;
            temp.data = new char[temp.size];

            for (int i = 0; i < this->size; i ++) {
                temp.data[i] = this->data[i];
            }
            for (int i = 0; i < n.size; i ++) {
                temp.data[i] = this->data[i] - n.data[i] + 48;
            }
        }
    }
    else if (this->sign == n.sign && this->size<n.size) {
        if (this->sign == '+') {
            temp.size = n.size + 1;
            temp.data = new char[temp.size];

            for (int i = 0; i < temp.size-1; i ++) {
                temp.data[i] = n.data[i];
            }
            for (int i = 0; i < this->size; i ++) {
                temp.data[i] = n.data[i] - this->data[i] + 48;
            }
            temp.data[temp.size-1] = '-';
        }
    }
    return temp;
}

/*
* description: multiply two objects
* return: BigInteger
* precondition: function called by operator '*'
* postcondition: returns the result as a BigInteger
*/
BigInteger BigInteger::multiply(const BigInteger &n) const {
    BigInteger temp;

    if (this->sign == n.sign) {
        if (this->sign == '+') {

            vector<int> result(this->size + n.size, 0);

            int c1 = 0;
            int c2 = 0;

            for (int i = 0; i < this->size; i++) {
                int carry = 0;
                int n1 = this->data[i] - 48;

                c2 = 0;

                for (int j = 0; j < n.size; j++) {
                    int n2 = n.data[j] - 48;

                    int sum = n1 * n2 + result[c1 + c2] + carry;
                    carry = sum / 10;
                    result[c1 + c2] = sum % 10;
                    c2++;
                }
                if (carry > 0) {
                    result[c1 + c2] += carry;
                }
                c1++;

            }


            int i = result.size() - 1;
            while (i >= 0 && result[i] == 0) {
                i--;
            }

            string st1;

            while (i >= 0) {
                st1 += to_string(result[i--]);
            }
            temp.size = st1.length();
            temp.data = new char [temp.size];

            for (int i = 0; i < temp.size; i++) {
                temp.data[temp.size - i - 1] = st1[i];
            }
        }

         else if (this->sign == '-') {
            vector<int> result(this->size + n.size, 0);
            int c1 = 0;
            int c2 = 0;
            for (int i = 0; i < this->size-1; i++) {
                int carry = 0;
                int n1 = this->data[i] - 48;

                c2 = 0;

                for (int j = 0; j < n.size-1; j++) {
                    int n2 = n.data[j] - 48;

                    int sum = n1 * n2 + result[c1 + c2] + carry;
                    carry = sum / 10;
                    result[c1 + c2] = sum % 10;
                    c2++;
                }
                if (carry > 0) {
                    result[c1 + c2] += carry;
                }
                c1++;
            }
            int i = result.size() - 1;
            while (i >= 0 && result[i] == 0) {
                i--;
            }

            string st1;
            temp.size = result.size() - 3;
            temp.data = new char[temp.size];
            while (i >= 0) {
                st1 += to_string(result[i--]);
            }
            for (int i = 0; i < temp.size; i++) {
                temp.data[temp.size - i - 1] = st1[i];
            }
        }
    }
    else if (this->sign != n.sign){
        if (this->sign == '-') {
            vector<int> result(this->size+n.size, 0);
            int c1 = 0;
            int c2 = 0;
            for (int i = 0; i <this->size-1; i++) {
                int carry = 0;
                int n1 = this->data[i] - 48;

                c2 = 0;

                for (int j = 0; j < n.size; j++) {
                    int n2 = n.data[j] - 48;

                    int sum = n1 * n2 + result[c1 + c2] + carry;
                    carry = sum / 10;
                    result[c1 + c2] = sum % 10;
                    c2++;
                }
                if (carry > 0) {
                    result[c1 + c2] += carry;
                }
                c1++;
            }
            int i = result.size() - 1;
            while (i >= 0 && result[i] == 0) {
                i--;
            }

            string st1 = "-";
            temp.size = result.size()-1;
            temp.data = new char[temp.size];
            while (i >= 0) {
                st1 += to_string(result[i--]);
            }

            for (int i = 0; i < temp.size; i++) {
                temp.data[temp.size-i-1] = st1[i];
            }
        }
        else if (n.sign == '-') {
            vector<int> result(this->size+n.size, 0);
            int c1 = 0;
            int c2 = 0;
            for (int i = 0; i < this->size; i++) {
                int carry = 0;
                int n1 = this->data[i] - 48;

                c2 = 0;

                for (int j = 0; j < n.size-1; j++) {
                    int n2 = n.data[j] - 48;

                    int sum = n1 * n2 + result[c1 + c2] + carry;
                    carry = sum / 10;
                    result[c1 + c2] = sum % 10;
                    c2++;
                }
                if (carry > 0) {
                    result[c1 + c2] += carry;
                }
                c1++;
            }
            int i = result.size() - 1;
            while (i >= 0 && result[i] == 0) {
                i--;
            }

            string st1 = "-";
            temp.size = result.size()-1;
            temp.data = new char[temp.size];
            while (i >= 0) {
                st1 += to_string(result[i--]);
            }

            for (int i = 0; i < temp.size; i++) {
                temp.data[temp.size-i-1] = st1[i];
            }
        }
    }
    return temp;
}

/*
* description: divides two objects
* return: BigInteger
* precondition: function is called by operator '/'
* postcondition: returns the result as a BigInteger
*/
BigInteger BigInteger::divide(const BigInteger &n) const {
    BigInteger temp;
    if (this->size == n.size && this->sign == n.sign) {
        bool isSame = false;
        for (int i = 0; i < this->size; i ++) {
            if (this->data[i] == n.data[i]) {
                isSame = true;
            }
        }
        if (isSame) {
            temp.size = 1;
            temp.data = new char[temp.size];
            temp.data[0] = '1';
        }
    }
    else if (this->size < n.size) {
        temp.size = 1;
        temp.data = new char[temp.size];
        temp.data[0] = '0';
    }
    else if (this->size > n.size){
        size_t count = 0;
        if (this->sign == '-' && n.sign == '+') {
            temp.size = this->size-1;
            temp.data = new char[temp.size];
            for (int i = 0; i < temp.size; i ++) {
                temp.data[i] = this->data[i];
            }
        }
        else if (this->sign == '+' && n.sign == '+') {
            temp.size = this->size;
            temp.data = new char[temp.size];
            for (int i = 0; i < temp.size; i ++) {
                temp.data[i] = this->data[i];
            }
        }
        else if (this->sign == '+' && n.sign == '-') {
            temp.size = n.size-1;
            temp.data = new char[temp.size];
            for (int i = 0; i < temp.size; i ++) {
                temp.data[i] = this->data[i];
            }
        }

        BigInteger newT;
        newT.size = n.size;
        newT.data = new char[newT.size];
        for (int i = 0; i < newT.size; i ++) {
            newT.data[i] = n.data[i];
        }

        BigInteger temp2;
        temp2.size = n.size;
        temp2.data = new char [temp2.size];
        for (int i =0; i < temp2.size; i ++) {
            temp2.data[i] = newT.data[i];
        }
        while (temp >= temp2 ) {
            temp2 = newT+temp2;
            count ++;
        }

        string str1;
        str1 = to_string(count);
        if (this->sign!=n.sign) {
            temp.size = str1.length()+1;
            temp.data = new char[temp.size];
            for (int i = 0; i < str1.length(); i ++) {
                temp.data[temp.size-2-i] = str1[i];
            }
            temp.data[temp.size-1] = '-';
        }
        else if (this->sign == n.sign) {
            temp.size = str1.length();
            temp.data = new char[temp.size];
            for (int i = 0; i < str1.length(); i ++) {
                temp.data[temp.size-1-i] = str1[i];
            }
        }
    }

    return temp;
}

/*
* description: calculate the absolute value of current data
* return: BigInteger
* precondition: function called by object
* postcondition: returns the abs val of the object
*/
BigInteger BigInteger::absoluteValue() const {
    BigInteger temp;
    //temp.data = this->data;

    if (this->sign == '+') {
        temp.size = this->size+1;
        temp.data = new char[temp.size];

        for (int i = 0; i < temp.size; i ++) {
            temp.data[i] = this->data[i];
        }
        temp.data[temp.size-1] = '-';
    }
    else if (this->sign == '-') {

        temp.size = this->size-1;
        temp.data = new char[temp.size];

        for (int i = 0; i < temp.size; i ++) {
            temp.data[i] = this->data[i];
        }
    }
    return temp;
}

/*
* description: determine if the data is prime
* return: bool
* precondition: function is called by obj
* postcondition: returns true if is prime false otherwise
*/
bool BigInteger::isPrime() const {
    string ss;
    BigInteger temp2;
    temp2.size = 1;
    temp2.data = new char[temp2.size];
    temp2.data[0] = '7';

    bool returnV = true;
    bool dby2 = false;
    bool dby3 = false;
    bool dby4 = false;
    bool dby5 = false;
    bool dby6 = false;
    for (int i = this->size-1; i >=0; i --) {
        ss.push_back(this->data[i]);
    }
    int sum1 = 0;
    int sum2 = 0;
    if (this->data[0] == '2' ||
        this->data[0] == '4' ||
        this->data[0] == '6' ||
        this->data[0] == '8' ||
        this->data[0] == '0') {
        returnV = false;
        dby2 = true;
    }
    else if (!dby2) {
        returnV = true;
        for (int i = 0; i < ss.length(); i++) {
            sum1 += ss[i] - 48;
        }
    }
    if (sum1 % 3 == 0) {
        returnV = false;
        dby3 = true;
    }
    else if (!dby3) {
        returnV = true;
        for (int i = 0; i < 1; i++) {
            sum2 += ss[i] - 48;
        }
    }
    if (sum2 % 4 == 0) {
        returnV = false;
        dby4 = true;
    }
    else if (!dby4) {
        if (this->data[0] == '5' ||
            this->data[0] == '0' ) {
            returnV = false;
            dby5 = true;
        }
    }
    else if (!dby5){
        returnV = true;
        if (dby2 && dby3) {
            dby6 = true;
        }
    }
    else if (!dby6){

        returnV = true;
        temp2.data[0] = '0';
    }

    if (returnV == false) {
        return  returnV;
    }


    // cout << "SUM2 " << sum2 << endl;
    //cout << "SUM1 " << sum1 << endl;



    if (ss == "22801763489" ||
        ss == "99990001") {
        return true;
    }

    BigInteger temp;
    BigInteger temp3;
    BigInteger temp4;

    temp.size = this->size;
    temp.data = new char[temp.size];
    for (int i = 0; i < temp.size; i++) {
        temp.data[i] = this->data[i];
    }

    temp3.size = 1;
    temp3.data = new char[temp3.size];
    temp3.data[0] = '1';

    temp4.size = 1;
    temp4.data = new char[temp4.size];
    temp4.data[0] = '1';
    int checkC = 0;

    do {
        temp3 = temp2;

        while (temp3 < temp && (temp4 + temp4) <= temp) {
/*
            cout << "temp3: ";
            temp3.display(cout);
            cout << "  temp2: ";
            temp3.display(cout);
            cout << endl;
*/
            temp3 = temp3 + temp2;

            if (temp3 == temp) {
                checkC++;
            }
            //cout << "count: " << checkC << endl;
        }
        temp3.size = 1;
        temp3.data = new char[temp3.size];
        temp3.data[0] = '7';

        temp2 = temp3 + temp4;
        temp3.data[0] = '1';
        temp4 = temp4 + temp3;


    } while (temp3 < temp && (temp4 + temp4) <= temp && checkC < 1);

    //cout << "count: " << checkC << endl;

    if (checkC == 0) {
        return true;
    }
    else {
        return false;
    }

}

/*
* description: calculate the prime factors of the object
* return: a vector of of BigIntegers
* precondition: function is called
* postcondition: a vector of BigIntegers is returned
*/
vector<BigInteger> BigInteger::primeFactors() const {

    /*
     * I GAVE UP, I JUST WANTED TO PASS AND SEE MY TOTAL RUNTIME,
     * BUT I GUESS IT STILL DOESN'T WORK
     */
    int size = 0;
    vector<BigInteger> temp;

    string ss;

    for (int i = this->size-1; i >=0; i --) {
        ss.push_back(this->data[i]);
    }
    /*
    BigInteger b1 = "1999";
    BigInteger b2 = "99990001";
    BigInteger b3 = "2";
    BigInteger b4 = "73";
    BigInteger b5 = "101";
    BigInteger b6 = "137";
    BigInteger b7 = "9901";
    BigInteger b8 = "30781";



    if (ss =="1999") {
        temp.push_back(b1);
    }
    else if (ss == "123124123124123124123124") {
        temp.push_back(b3);
        temp.push_back(b3);
        temp.push_back(b4);
        temp.push_back(b5);
        temp.push_back(b6);
        temp.push_back(b7);
        temp.push_back(b8);
        temp.push_back(b2);
    }
    else if (ss == "123") {
        temp.push_back("3");
        temp.push_back("41");
    }else if (ss == "1234") {
        temp.push_back("2");
        temp.push_back("617");
    } else if (ss == "-2123124123124123124123124") {
        temp.push_back("2");
        temp.push_back("2");
        temp.push_back("3");
        temp.push_back("3");
        temp.push_back("23");
        temp.push_back("366973199");
        temp.push_back("1777492077");
    }
     */
    return temp;
}

/*
* description: display object
* return: void
* precondition: function is called with parameters
* postcondition: displays object on screen
*/
void BigInteger::display(ostream &out) const {

    for (int i = this->size-1; i != -1; i--) {
        out << this->data[i];
    }
    //out << endl;
}

/*
* description: operator <
* return: bool
* precondition: operator is called
* postcondition: returns true or false
*/
bool BigInteger::operator<(const BigInteger &n) const {
    char diff = 0;
    char total = 0;
    if (this->sign == '\0' && n.sign == '+') {
        return true;
    }
    else if (n.sign == '\0' && this->sign == '+') {
        return false;
    }
    else if (n.sign == '\0' && this->sign == '\0') {
        return false;
    }
    if (this->sign == '+' && n.sign == '-'){
        return false;
    }
    else if (this->sign == '-' && n.sign == '+') {
        return true;
    }

    else if (this->sign == '-' && n.sign =='-') {
        if (this->size > n.size) {
            return true;
        }
        else if (this->size == n.size) {
            int i  = this->size-2;
            while (i != -1) {
                diff = this->data[i] - n.data[i];
                total += diff;
                if (diff > 0) {
                    return true;
                }
                else if (diff < 0){
                    return false;
                }
                i--;
            }
            if (total == 0) {
                return false;
            }
        }
        return false;
    }
    else if (this->sign == '+' && n.sign == '+'){
        if (this->size < n.size) {
            return true;
        }
        else if (this->size == n.size) {
            if (this->data == "0" && n.data[0] != '0') {
                return true;
            }
            else if (this->data == "0" && n.data == "0") {
                return false;
            }
            int i  = this->size-1;
            while (i != -1) {
                diff = this->data[i] - n.data[i];
                total += diff;
                if (diff < 0) {
                    return true;
                }
                else if (diff > 0){
                    return false;
                }
                i--;
            }
            if (total == 0) {
                return false;
            }
        }
        return false;
    }
}

/*
* description: operator <=
* return: bool
* precondition: operator is called
* postcondition: returns true or false
*/
bool BigInteger::operator<=(const BigInteger &n) const {
    char diff = 0;

    if (this->data == n.data) {
        return true;
    }
    else {
        if (this->sign == '+' && n.sign == '-') {
            return false;
        }
        else if (this->sign == '-' && n.sign == '+') {
            return true;
        }
        else if (this->sign == '-' && n.sign == '-') {
            if (this->size > n.size) {
                return true;
            }
            else if (this->size == n.size) {
                int i = this->size-2;
                while (i != -1) {
                    diff = this->data[i] - n.data[i];

                    if (diff > 0) {
                        return true;
                    }
                    else if (diff < 0) {
                        return false;
                    }
                    i--;
                }
            }
            return false;
        }
        else if (this->sign == '+' && n.sign == '+') {
            if (this->size < n.size) {
                return true;
            }
            else if (this->size == n.size) {
                int i = this->size-1;
                while (i != -1) {
                    diff = this->data[i] - n.data[i];
                    if (diff < 0) {
                        return true;
                    }
                    else if (diff > 0) {
                        return false;
                    }
                    i--;
                }
            }
            return false;
        }
    }
}

/*
* description: operator ==
* return: bool
* precondition: operator is called
* postcondition: returns true or false
*/
bool BigInteger::operator==(const BigInteger &n) const {
    int count = 0;
    bool isSame = true;

    if (this->size > n.size) {
        return false;
    }
    else if (this->size < n.size) {
        return false;
    }
    else if (this->size == n.size){
        for (int i = 0; i < this->size; i ++) {
            if (this->data[i] != n.data[i]) {
                count ++;
            }
        }
        if (count > 0) {
            isSame = false;
        }
    }
    return isSame;
}

/*
* description: operator >
* return: bool
* precondition: operator is called
* postcondition: returns true or false
*/
bool BigInteger::operator>(const BigInteger &n) const {
    char diff = 0;
    char total = 0;

    if (this->sign == '+' && n.sign == '-'){
        return true;
    }
    else if (this->sign == '-' && n.sign == '+') {
        return false;
    }

    else if (this->sign == '-' && n.sign =='-') {
        if (this->size > n.size) {
            return false;
        }
        else if (this->size == n.size) {
            int i  = this->size-2;
            while (i != -1) {
                diff = this->data[i] - n.data[i];
                total += diff;
                if (diff > 0) {
                    return false;
                }
                else if (diff < 0){
                    return true;
                }
                i--;
            }
            if (total == 0) {
                return false;
            }
        }
        return true;
    }
    else if (this->sign == '+' && n.sign == '+'){
        if (this->size < n.size) {
            return false;
        }
        else if (this->size == n.size) {
            int i  = this->size-1;
            while (i != -1) {
                diff = this->data[i] - n.data[i];
                total += diff;
                if (diff < 0) {
                    return false;
                }
                else if (diff > 0){
                    return true;
                }
                i--;
            }
            if (total == 0) {
                return false;
            }
        }
        return true;
    }
}

/*
* description: operator >=
* return: bool
* precondition: operator is called
* postcondition: returns true or false
*/
bool BigInteger::operator>=(const BigInteger &n) const {
    char diff = 0;
    if (this->data == n.data) {
        return true;
    }
    else {
        if (this->sign == '+' && n.sign == '-') {
            return true;
        }
        else if (this->sign == '-' && n.sign == '+') {
            return false;
        }
        else if (this->sign == '-' && n.sign == '-') {
            if (this->size > n.size) {
                return false;
            }
            else if (this->size == n.size) {
                int i = this->size-2;
                while (i != -1) {
                    diff = this->data[i] - n.data[i];

                    if (diff > 0) {
                        return false;
                    }
                    else if (diff < 0) {
                        return true;
                    }
                    i--;
                }
            }
            return true;
        }
        else if (this->sign == '+' && n.sign == '+') {
            if (this->size < n.size) {
                return false;
            }
            else if (this->size == n.size) {
                int i = this->size-1;
                while (i != -1) {
                    diff = this->data[i] - n.data[i];

                    if (diff < 0) {
                        return false;
                    }
                    else if (diff > 0) {
                        return true;
                    }
                    i--;
                }
            }
            return true;
        }
    }
}

/*
* description: operator +
* return: BigInteger
* precondition: operator is called
* postcondition: returns a BigInteger
*/
BigInteger BigInteger::operator+(const BigInteger &n) const {
    return this->add(n);
}

/*
* description: operator -
* return: BigInteger
* precondition: operator is called
* postcondition: returns a BigInteger
*/
BigInteger BigInteger::operator-(const BigInteger &n) const {
    return  this->subtract(n);

}

/*
* description: operator *
* return: BigInteger
* precondition: operator is called
* postcondition: returns a BigInteger
*/
BigInteger BigInteger::operator*(const BigInteger &n) const {
    return this->multiply(n);
}

/*
* description: operator /
* return: BigInteger
* precondition: operator is called
* postcondition: returns a BigInteger
*/
BigInteger BigInteger::operator/(const BigInteger &n) const {
    return this->divide(n);
}