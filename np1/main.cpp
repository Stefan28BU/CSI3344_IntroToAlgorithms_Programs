#include <iostream>
#include "BigInteger.h"

using namespace std;

int main(){
    /*
    string str1 = "21";
    string str2 = "10";
    BigInteger v1("124");
    BigInteger v2("99990001");
    BigInteger v3 = (v1+v2);

    BigInteger v4(str1);
    BigInteger v5(str2);
    BigInteger v6("123013");
    BigInteger v7("2");

    //cout << v4.isPrime() << endl;

    cout << "MUL ";
    (v4*v5).display(cout);
    cout << "  Size: " << (v4*v5).getSize() << endl;
    cout << endl;

    cout << "DIV ";
    (v6/v7).display(cout);
    //cout << "  Size: " << (v6/v7).getSize() << endl;
    cout << endl;


    cout << (v1+v2).getSize() << endl;


    (v1-v2).display(cout);
    cout << endl;
    cout << "comp " <<(v1<v2) << endl;

    cout << "V1 ";
    v1.display(cout);
    cout << "V2 ";
    v2.display(cout);
    cout << "V3 ";
    v3.display(cout);
    cout << endl;
    cout << "is same?  " << (v1==v2) << endl;
    cout << "V3 SIZE " << v3.getSize() << endl;
    cout << "V1 SIZE " << v1.getSize() << endl;
    cout << "V2 SIZE " << v2.getSize() << endl;
    v7 = v6;
    v6.display(cout);
    cout << endl;
    //cout << "V2 Prime " << v2.isPrime() << endl;
    */

    BigInteger b1("0");
    BigInteger b2("2");

    cout << (b1<b2) << endl;
    cout << "b1 sign:  " << b1.getSign() << endl;
    cout << "b2 sign:  " << b2.getSign() << endl;

    return 0;
}