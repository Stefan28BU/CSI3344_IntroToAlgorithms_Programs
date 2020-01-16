
#include <list>
#include "TestGraph.h"
#include "Successors.h"

using namespace std;

int main(int argc, char * argv[]) {
    if (argc != 2) {
        cerr << "Invalid number of arguments; expecting 1 for file name"
             << endl;
        exit(1);
    }

    ifstream input (argv[1], std::ios::in);

    int v;
    Graph<int> g;
    input >> v;

    if (!buildGraph(g, input)) {
        cerr << "Unable to build graph, please check graph format"
             << endl;
        exit(1);
    }

    list<int> successorList = successors(g, v);
    cout << "Successors:";
    for(auto it = successorList.begin(); it != successorList.end(); it++){
        cout << " " << *it;
    }
    cout << endl;

    return 0;
}