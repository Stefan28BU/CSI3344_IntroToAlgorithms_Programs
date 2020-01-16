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
 * 	    Main function:
 * 	        BigInteger, ifstream, int, string, ofstream
 *
 * Input:
 * 		Two input files entered using command line. argv[1] is the key file
 * 		    that contains private key d and N, argv[2] is the encrypted file
 * 		    that suppose to be decrypted
 * Process:
 * 		The program reads two input files and applies RSA decryption to the
 * 		    encrypted file and directs the decrypted result to an output file
 * Output:
 * 		The result of decrypted data is printed to the output file, which is
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

const int SIZE = 10000;

int main(int argc, char ** argv) {
    BigInteger data[SIZE];

    ifstream dkeyFile;

    //dkeyFile.open(argv[1]);
    dkeyFile.open("dkFile");

    if (!dkeyFile) {
        cerr << "Key File Not Open" << endl;
        return -1;
    }

    int d;
    int N;
    int readKeyCount = 0;

    while (!dkeyFile.eof()) {
        if(readKeyCount == 0) {
            dkeyFile >> N;
        }
        else if (readKeyCount == 1) {
            dkeyFile >> d;
        }
        readKeyCount++;
    }
    dkeyFile.close();

    cout << "dKey: " << d << endl;
    cout << "N: " << N << endl;

    ifstream encryptedDataFile;

    //encryptedDataFile.open(argv[2]);
    encryptedDataFile.open("outFile");

    if (!encryptedDataFile) {
        cerr << "Data File Not Open" << endl;
        return -1;
    }
    string eData;

    int count1 = 0;
    while (encryptedDataFile >> eData) {
        BigInteger tempD(eData);
        data[count1] = tempD;
        count1 ++;
    }

    ofstream decryptedOutFile;

    //decryptedOutFile.open(argv[3]);
    decryptedOutFile.open("dOutFile");

    if (!decryptedOutFile) {
        cerr << "Decrypted File Not Open" << endl;
        return -1;
    }

    for (int i = 0; i < count1; i ++) {
        data[i].display(cout);
        cout << "  ";

        BigInteger self;
        int comp = 1;
        self = data[i];
        while (comp < d) {
            data[i] = data[i] * self;
            comp ++;
        }

        int decryptedRes = 0;
        string currRes = "";
        for (int j = data[i].getSize() -1 ; j >=0; j --) {
            currRes.push_back(data[i].getCurrIndexData(j));
        }
        for (int k = 0; k < currRes.length(); k++) {
            decryptedRes = (decryptedRes * 10 + (int)currRes[k] - '0' ) % N;
        }
        cout <<"curr " <<  currRes << "  Result  " << decryptedRes << endl;

        decryptedOutFile << (char)decryptedRes;
    }
    return 0;
}
