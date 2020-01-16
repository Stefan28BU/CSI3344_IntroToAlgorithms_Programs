#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Multiplies str1 and str2, and prints result.
string multiply(string num1, string num2)
{
     int n1 = num1.size();
     int n2 = num2.size();
    //int n1 = strlen(num1);
    //int n2 = strlen(num2);
    if (n1 == 0 || n2 == 0)
       return "0";

    // will keep the result number in vector
    // in reverse order
    //vector<int> result(n1+n2,0);
    vector<int> result(n1+n2, 0);

    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;

    // Go from right to left in num1
    for (int i=0; i<n1; i++)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0;

        // Go from right to left in num2
        for (int j=0; j<n2; j++)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';

            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position.
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;

            // Carry for next iteration
            carry = sum/10;

            // Store result
            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }

    // ignore '0's from the right
    //int i = result.size() - 1;
    int i = 0;
    //while (i>=0 && result[i] == 0)
    while ( result[i] == 0 && i < result.size())
       i++;

    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == result.size())
       return "0";

    // generate the result string
    cout << "size  " << result.size() << endl;
    string s = "";
    char *res = "";
    while (i < result.size())
        s += to_string(result[i++]);
        //s += result[i--];
        //res += result[i--];

    return s;
}

// Driver code
int main()
{
    char *char1 = "0012";
    char *char2 = "002";
    string s = multiply(char1, char2);

    int size1 = strlen(char1);

    cout << s << endl;



    return 0;
}