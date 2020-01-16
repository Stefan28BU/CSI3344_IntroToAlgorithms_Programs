//
// Created by 徐宇帆 on 18/8/21.
//


#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"
#include "TestGraph.h"
using namespace std;

int main() {
    ifstream data;
    string line;
    int vertex;

    data.open("GraphData.txt");
    data >> vertex; //read first line of the file which has
    //the vertex you will be finding successors for.

    Graph<int> g;

    switch(buildGraph(g, data)){
        case 1:  cout << "success" << endl;
            break;
        case 0:  cout << "fail" << endl;
            break;
    }

    return 0;
}