/*
* Author:                 Yufan Xu
* Assignment Title:       RSA Cryptography
* Assignment Description: This program uses BigInteger class to generate
*                         and store data, and applies RSA encryption and
*                         decryption to the data. There will be a report
*                         generated as a text file to show the result
* Due Date:               10/01/2018
* Date Created:           10/01/2018
* Date Last Modified:     10/01/2018
*/

/*
 * Data Abstraction:
 * 		Two input files, one output file
 * 	    One class: StringToBI
 * 	        private instances:
 * 	            ifstream *fp,
 * 	            BigInteger n
 * 	        public instances:
 * 	            StringToBI(),
 * 	            StringToBI(ifstream *in, BigInteger n)
 * 	            BigInteger nextBigInt()
 * 	    Main function:
 * 	        BigInteger, ifstream, int, string, ofstream
 *
 * Input:
 * 		Two input files entered using command line. argv[1] is the key file
 * 		    that contains public key e and N, argv[2] is the source file
 * 		    that suppose to be encrypted
 * Process:
 * 		The program reads two input files and applies RSA encryption to the
 * 		    source file and directs the encrypted result to an output file
 * Output:
 * 		The result of encrypted data is printed to the output file, which is
 * 		    the argv[3] entered through command line
 * Assumptions:
 * 		Assume that the number of characters in the file is within 10000
 * 		Assume the user only tests the program using command line arguments
 */

#include "BigInteger.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//this class convert a character to its
//decimal representation
class StringToBI {
private:
    ifstream *fp;
    BigInteger n;

public:
    /*
    * description: default constructor
    * return: none
    * precondition: none
    * postcondition: none
    */
    StringToBI();

    /*
    * description: constructor
    * return: none
    * precondition: object is created
    * postcondition: assign lvalue to arguments
    */
    StringToBI(ifstream *in, BigInteger n) {
        this->fp = in;
        this->n = n;
    }

    /*
    * description: returns a BigInteger
    * return: BigInteger
    * precondition: function called by object
    * postcondition: a BigInteger is returned
    */
    BigInteger nextBigInt() {
        char c;
        BigInteger rv("0");
        BigInteger multiplier("1000");



        //while (fp->get(c) && rv * multiplier < n) {
            do {
                fp->get(c);

                rv = rv * multiplier;
                BigInteger b1 = to_string(int(c));
                rv = rv + b1;
            }while (rv * multiplier < n);
        //}

        return rv;
    }
};

//size of the BigInteger Array
const int SIZE = 10000;


int main(int argc, char ** argv) {

    BigInteger data[SIZE];

    ifstream keyFile;

    //keyFile.open(argv[1]);
    keyFile.open("keyFile");

    if (!keyFile) {
        cerr << "Key File Not Open" << endl;
        return -1;
    }

    int e;
    int N;
    int readKeyCount = 0;

    while (!keyFile.eof()) {
        if(readKeyCount == 0) {
            keyFile >> N;
        }
        else if (readKeyCount == 1) {
            keyFile >> e;
        }
        readKeyCount++;
    }
    keyFile.close();

    cout << "eKey: " << e << endl;
    cout << "N: " << N << endl;

    ifstream dataFile;

    //dataFile.open(argv[2]);
    dataFile.open("dataFile");

    if (!dataFile) {
        cerr << "Data File Not Open" << endl;
        return -1;
    }

    BigInteger comp("90");
    StringToBI s1(&dataFile, comp);
    int countData = 0;
    while (dataFile) {
        data[countData] = s1.nextBigInt();

        cout << endl;
        countData++;
    }
    dataFile.close();

    cout << "Before Encryption: " << endl;
    for (int i = 0; i < countData; i ++) {
        data[i].display(cout);
        cout << endl;
    }

    ofstream encryptedDataFile;

    //encryptedDataFile.open(argv[3]);
    encryptedDataFile.open("outFile");

    if (!encryptedDataFile) {
        cerr << "Encrypted File Not Open" << endl;
        return -1;
    }

    for (int i = 0; i < countData; i ++) {
        BigInteger self;
        int comp2 = 1;
        self = data[i];
        while (comp2 < e) {
            data[i] = data[i] * self;
            comp2 ++;
        }

        int encryptedRes = 0;
        string currRes = "";
        for (int j = data[i].getSize() - 1 ; j >=0; j --) {
            currRes.push_back(data[i].getCurrIndexData(j));
        }
        for (int k = 0; k < currRes.length(); k++) {
            encryptedRes = (encryptedRes * 10 + (int)currRes[k] - '0' ) % N;
        }
        cout <<"curr " <<  currRes << "  Result  " << encryptedRes << endl;

        encryptedDataFile << to_string(encryptedRes);
        encryptedDataFile << endl;
    }
    encryptedDataFile.close();

    return 0;
}
