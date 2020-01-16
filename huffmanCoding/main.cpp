/*
* Author:                 Yufan Xu
* Assignment Title:       Huffman Encoding
* Assignment Description: This program uses Huffman coding algorithm to
*                         compress and uncompress the message, this program
*                         takes input from the command line arguments
* Due Date:               11/08/2018
* Date Created:           11/08/2018
* Date Last Modified:     11/08/2018
*/

/*
 * Data Abstraction:
 *      structs, functions, int, map, priority_queue, string, main function
 * Input:
 * 		this program takes command line input, where the first argument should
 * 		    be the -huff or -unhuff command, the second and third should be
 * 		    source and destination file
 * Process:
 * 		the program takes user input from the command line, and perform the
 * 		    huffman coding algorithm. To encode, the program will read from
 * 		    the input file and output the encoded result to an output file,
 * 		    to decode, the program will read the encoded data from a file,
 * 		    and output the decoded data to a file
 * Output:
 * 		The result of both encode and decode are printed to different files
 * 		    enter by the user from the command line
 * Assumptions:
 * 		Assume that user will only enter valid arguments from the command line
 * 		Assume the file to be encode and decode are not large
 */

#include <iostream>
#include <cstring>
#include <queue>
#include <fstream>
#include <map>
#include <bitset>

using namespace std;

//huffman node structure
struct Node {
    char data;
    int freq;
    Node *left, *right;

    //constructor of Node
    Node(char data, int freq) {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

/*
 * description: construct huffman code for each character
 * return: void
 * precondition: objects are passed and exist
 * postcondition: huffman encodings are calculated
 */
void buildHuffmanCode(Node* , string );

/*
 * description: build the huffman encoding tree
 * return: void
 * precondition: objects in the scope
 * postcondition: huffman tree is built
 */
void builtHuffmanTree();

/*
 * description: calculate frequency of each character
 * return: void
 * precondition: object is passed and exists
 * postcondition: characters' frequencies are calculated
 */
void calculateFrequency(string );

/*
 * description: decode the encoded string
 * return: string
 * precondition: objects are passed and exist
 * postcondition: returns decoded string
 */
string decode(Node* , string );

/*
 * description: encode the string
 * return: string
 * precondition: objects are passed and exist
 * postcondition: returns encoded string
 */
string encode(string );

//overloads operator > to compare two huffman nodes
struct Compare {
    bool operator()(Node* l, Node* r) {
        return (l->freq > r->freq);
    }
};

//map to store characters' huffman encoding
map<char, string> HuffmanCodes;

//map to store characters' frequency
map<char, int> frequency;

//min heap to store huffman nodes
priority_queue<Node*, vector<Node*>, Compare> minHeap;

//main function with command line parameters
int main(int argc, char ** argv) {
    char c;

    //validate number of input
    if (argc != 4) {
        cerr << "Invalid number of input." << endl;
        return 1;
    }

    //validate command
    if (strcmp(argv[1], "-huff") != 0 && strcmp(argv[1], "-unhuff") != 0) {
        cerr << "Invalid compress/uncompress command." << endl;
        return 1;
    }

    //check if the user want to run the compression algorithm
    if (strcmp(argv[1], "-huff") == 0) {

        //create a key file and a value file in current directory
        //to store the frequency of each character for future use
        ofstream keyFile("key.txt");
        ofstream valueFile("value.txt");

        //open source file
        ifstream infile;
        infile.open(argv[2]);

        string str;
        int count = 0;

        //read 1 byte a time from source file
        while (infile.get(c)) {

            //put all characters into a string
            str.push_back(c);
            count ++;
        }

        //if there are not enough characters, exit program
        if (count <= 1) {
            cout << "File will not compress" << endl;
            return 1;
        }

        string encodedString;

        //construct frequency map
        calculateFrequency(str);

        //construct minHeap
        //construct huffman encoding
        builtHuffmanTree();

        int j = 0;
        int k = 0;

        //store the key and value of frequency map to files
        for (auto i: frequency) {
            j ++;
            k += i.second;
            keyFile << i.first;
            valueFile << i.second << '\n';
        }

        //if all characters only appeared once, exit program
        if (k <= j) {
            cout << "File will not compress" << endl;
            return 1;
        }

        for (auto v: HuffmanCodes) {
            cout << v.first << ' ' << v.second << endl;
        }

        infile.close();
        infile.open(argv[2]);

        //open output file to store the encoding
        ofstream outfile;
        outfile.open(argv[3], ios::binary);

        string str2;
        while (infile.get(c)) {
            str2 += c;
        }

        char specialChar = '$';

        //write the special character to the beginning of file
        int intRep = (int)specialChar;
        bitset<8> bspec(intRep);
        unsigned long specul = bspec.to_ulong();
        char specChar = (char)specul;
        outfile.write(&specChar, sizeof(specChar));

        //create the encoding as string
        encodedString = encode(str2);

        string strbits = "";

        //write the encoding to output file 1 byte each time
        int cc1 = 0;
        for (int i = 0; i < encodedString.size(); i ++) {
            strbits += encodedString[i];
            if (strbits.size() == 8) {
                cc1 ++;
                bitset<8> bs1(strbits);
                strbits = "";
                unsigned long ul = bs1.to_ulong();
                char ch1 = (char)ul;
                outfile.write(&ch1, sizeof(ch1));
            }
        }

        cout << "number of 1 byte (8 bits): " << cc1 << endl;
        cout << "size of string (in bits)" << encodedString.size() << endl;

        //12990 bits, 1623.75 bytes

        infile.close();
        outfile.close();
    }

    //check if the user want to run the decompression algorithm
    else if (strcmp(argv[1], "-unhuff") == 0) {
        ifstream keyFile;
        ifstream valueFile;
        ifstream infile;
        ofstream outfile;

        //read key and value of frequency map
        keyFile.open("key.txt");
        valueFile.open("value.txt");

        char c1;
        int fr;

        //re-construct the frequency map
        while (keyFile.get(c1)){
            valueFile >> fr;
            frequency.insert(pair<char, int>(c1, fr));
        }

        infile.open(argv[2], ios::binary);
        string decodedString;
        string str;

        infile.read(&c, sizeof(c));

        //if the file does not have the special character, exit program
        if (c != '$') {
            cout << "Input File was not Huffman Encoded." << endl;
            return 1;
        }

        //read one byte at a time and convert into a string of encoding
        while (infile.read(&c, sizeof(c))) {
            int n = (int)c;
            bitset<8> bs(n);
            string sttt = bs.to_string();
            str += sttt;
        }

        //re-construct minHeap
        //re-construct huffman encoding
        builtHuffmanTree();

        for (auto v: HuffmanCodes) {
            cout << v.first << ' ' << v.second << endl;
        }

        //traverse through the huffman tree and find the node
        decodedString = decode(minHeap.top(), str);

        //write decoded data into another output file
        outfile.open(argv[3]);

        outfile << decodedString;

        cout << "\nDecoded string:\n" << decodedString << endl;

        infile.close();
        outfile.close();
    }

    return 0;
}

void builtHuffmanTree() {
    Node *left, *right, *top;

    for (auto v: frequency) {
        minHeap.push(new Node(v.first, v.second));
    }

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }
    buildHuffmanCode(minHeap.top(), "");
}

void calculateFrequency(string str) {
    for (int i=0; i < str.size(); i++) {
        frequency[str[i]]++;
    }
}

string decode(Node* root, string s) {
    string result = "";
    Node* curr = root;
    for (int i = 0; i< s.size(); i++) {
        if (s[i] == '0') {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }

        if (curr->left == NULL && curr->right == NULL) {
            result += curr->data;
            curr = root;
        }
    }
    return result + '\n';
}

void buildHuffmanCode(Node* root, string str) {
    if (root == NULL) {
        return;
    }
    if (root->data != '$') {
        HuffmanCodes[root->data] = str;
    }
    buildHuffmanCode(root->left, str + "0");
    buildHuffmanCode(root->right, str + "1");
}

string encode(string str) {
    string encodedData = "";

    for (auto i: str) {
        encodedData += HuffmanCodes[i];
    }
    return encodedData;
}