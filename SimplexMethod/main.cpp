/*
* Author:                 Yufan Xu
* Assignment Title:       Simplex Problem
* Assignment Description: This program solves a specific linear problem by
*                         applying simplex method. It calculates the maximum
*                         weekly profit for a company, displays the initial
*                         and final table to screen
* Due Date:               11/27/2018
* Date Created:           11/27/2018
* Date Last Modified:     11/27/2018
*/

/*
 * Data Abstraction:
 *      main function only, including:
 *          double, integer, boolean, two dimentional arrays
 * Input:
 * 		this program takes a hard coded linear problem as input, then applies
 * 		    simplex method to solve the problem (the method is not hard coded)
 * Process:
 * 		the program will first display the constraints to this specific
 * 		    linear problem, then display the initial simplex table, then
 * 		    the program will run simplex algorithm and produce a final table
 * Output:
 * 		the program displays constraints, initial table, final table, as well
 * 		    as the answer to the questions on the assignment page
 * Assumptions:
 * 		Assume that the linear problem is only hard coded
 * 		Assume that user only wants the correct solution
 */

#include <iostream>
#include <iomanip>

using namespace std;

//fixed capacity for the simplex tableau
const int columnCapacity = 9;
const int rowCapacity = 5;

int main() {

    //flag determines when to stop the algorithm
    bool flag = true;

    //variable creations and initializations
    double s1 = -1, s2 = 1, s3 = 1, s4 = 1, a1 = 1;

    int tabletProfit = 6;
    int phoneProfit = 8;
    int laptopProfit = 11;

    double tabletCost = 1.0;
    double phoneCost = 1.5;
    double laptopCost = 1.25;

    int tabletTime = 20;
    int phoneTime = 30;
    int laptopTime = 15;

    int tabletGram = 120;
    int phoneGram = 90;
    int laptopGram = 170;

    int minCases = 1200;
    int maxGrams = 200000;
    int maxCosts = 1800;
    int maxMins = 30000;

    //print the constraints for the problem
    cout << endl;
    cout << "For this specific linear problem, here are the constraints:" << endl << endl;
    cout << "max Z = 6x1 + 8x2 + 11x3" << endl;
    cout << "subject to" << endl;
    cout << "________________________________________________________" << endl;
    cout << "   x1 +    x2 +     x3 - s1                + a1 = 1200" << endl;
    cout << "120x1 +  90x2 +  170x3      + s2                = 200000" << endl;
    cout << "   x1 + 1.5x2 + 1.25x3           + s3           = 1800" << endl;
    cout << " 20x1 +  30x2 +  15 x3                + s4      = 30000" << endl;
    cout << "________________________________________________________" << endl;
    cout << "and x1, x2, x3, s1, s2, s3, s4, a1 >= 0" << endl << endl;

    //create simplex tableau
    double table[rowCapacity][columnCapacity];
    string varArr[columnCapacity] = {"x1", "x2", "x3", "s1", "s2", "s3", "s4", "a1", "b"};

    //initialize all values in the table to zero
    int initialVal = 0;
    for (int i = 0; i < rowCapacity; i ++) {
        for (int j = 0 ; j < columnCapacity; j ++) {
            table[i][j] = initialVal;
        }
    }

    //put in the R values of constraints into the table
    int consTraArr[4] = {minCases, maxGrams, maxCosts, maxMins};
    for (int i = 0; i < rowCapacity - 1; i ++) {
        table[i][8] = consTraArr[i];
    }

    //initialize the initial table
    table[0][0] = 1;
    table[0][1] = 1;
    table[0][2] = 1;
    table[0][3] = s1;
    table[0][7] = a1;

    table[1][0] = tabletGram;
    table[1][1] = phoneGram;
    table[1][2] = laptopGram;
    table[1][4] = s2;

    table[2][0] = tabletCost;
    table[2][1] = phoneCost;
    table[2][2] = laptopCost;
    table[2][5] = s3;

    table[3][0] = tabletTime;
    table[3][1] = phoneTime;
    table[3][2] = laptopTime;
    table[3][6] = s4;

    table[4][0] = -tabletProfit;
    table[4][1] = -phoneProfit;
    table[4][2] = -laptopProfit;

    //display the initial table
    cout << endl;
    cout << "Initial tableau: " << endl << endl;
    for (int i = 0; i < columnCapacity; i ++) {
        cout << left << setw(8) << varArr[i];
    }
    cout << endl;

    for (int i = 0; i < columnCapacity; i ++) {
        cout << left << setw(8) << "________";
    }
    cout << endl;

    for (int i = 0; i < rowCapacity-1; i ++) {
        for (int j = 0 ; j < columnCapacity; j ++) {
            cout << left << setw(8)  << table[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < columnCapacity; i ++) {
        cout << left << setw(8) << "________";
    }
    cout << endl;

    for (int i = 0; i < columnCapacity; i ++) {
        cout << left << setw(8)  << table[4][i];
    }
    cout << endl;

    //start the simplex algorithm
    int C = 0;
    while (flag) {

        //find the smallest value in the last row
        double smallestCol = table[4][0];
        for (int i = 1; i < columnCapacity; i++) {
            if (table[4][i] < smallestCol) {
                smallestCol = table[4][i];
            }
        }

        int pivotCol = 0;
        int pivotRow = 0;
        double minRArr[4];

        //determine the pivot column
        while (smallestCol != table[4][pivotCol]) {
            pivotCol++;
        }

        double pivotColArr[rowCapacity];

        //store the values in the pivot column to a temp array
        for (int i = 0; i < rowCapacity; i++) {
            pivotColArr[i] = table[i][pivotCol];
        }

        //ignore first row's theta ratio if its not the first iteration
        //calculate theta ratio
        if (C < 1) {
            for (int i = 0; i < 4; i++) {
                minRArr[i] = table[i][8] / table[i][pivotCol];
            }
        }
        else {
            for (int i = 1; i < 4; i++) {
                minRArr[i] = table[i][8] / table[i][pivotCol];
            }
        }

        double minRatio = minRArr[0];

        //ignore first row's theta ratio if its not the first iteration
        //determine the smallest ratio
        if (C < 1) {
            for (int i = 1; i < 4; i++) {
                if (minRArr[i] < minRatio) {
                    minRatio = minRArr[i];
                }
            }
        }
        else {
            for (int i = 2; i < 4; i++) {
                if (minRArr[i] < minRatio) {
                    minRatio = minRArr[i];
                }
            }
        }

        //find the pivot row
        if (C < 1) {
            while (minRatio != minRArr[pivotRow]) {
                pivotRow++;
            }
        }
        else {
            pivotRow = 1;
            while (minRatio != minRArr[pivotRow]) {
                pivotRow++;
            }
        }

        //determine the pivot value
        double pivotVal = table[pivotRow][pivotCol];

        //make the pivot row divided by its pivot value
        for (int i = 0; i < columnCapacity; i++) {
            table[pivotRow][i] = table[pivotRow][i] / pivotVal;
        }

        //updates other rows so that pivot value becomes 1
        //others on the column become 0
        for (int i = 0; i < rowCapacity; i++) {
            if (i != pivotRow) {
                for (int j = 0; j < columnCapacity; j++) {

                    //pull the multiplier from temp column array
                    double temp = pivotColArr[i];

                    //update all elements in current row if its not pivot row
                    table[i][j] = table[i][j] - temp * table[pivotRow][j];
                }
            }
        }

        //determine if all elements in the last row is non-negative
        //if true then we have the answer, loop stops
        //otherwise go to the next iteration until the condition becomes true
        int count = 0;
        for (int i = 0; i < columnCapacity; i++) {
            if (table[4][i] >= 0) {
                count ++;
            }

            if (count == columnCapacity) {
                flag = false;
            }
            else {
                flag = true;
            }
        }
        C++;
    }

    //display the final simplex tableau
    cout << endl << endl;
    cout << "Final tableau: " << endl << endl;
    for (int i = 0; i < columnCapacity; i ++) {
        cout << left << setw(10) << varArr[i];
    }
    cout << endl;

    for (int i = 0; i < columnCapacity; i ++) {
        cout << left << setw(10) << "__________";
    }
    cout << endl;

    for (int i = 0; i < rowCapacity-1; i ++) {
        for (int j = 0 ; j < columnCapacity; j ++) {
            cout << left << setw(10) << fixed << setprecision(4) << table[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < columnCapacity; i ++) {
        cout << left << setw(10) << "__________";
    }
    cout << endl;

    for (int i = 0; i < columnCapacity; i ++) {
        cout << left << setw(10) << fixed << setprecision(4) << table[4][i];
    }
    cout << endl << endl;

    //display answers and observations
    cout << endl;
    cout << "Based on the final tableau, none of x1, 392.9825 of x2, \n";
    cout << "and 968.4211 of x3 will produce the maximum weekly profit. \n";
    cout << "The original maxiumum profit: $13796.4912\n";
    cout << endl;
    cout << "Since in reality we can never produce and sell an incomplete\n";
    cout << "product, the final answer should be:\n";
    cout << "Case production # for Tablet:       0" << endl;
    cout << "Case production # for Cell Phone: 393" << endl;
    cout << "Case production # for Laptop:     968" << endl;
    cout << endl << "The rounded numbers still fulfill the constraints";
    cout << endl;
    cout << "So, the rounded maximum weekly profit is: $13792\n" << endl;

    return 0;
}


