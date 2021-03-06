

#ifndef PROJ0_GRAPH_H
#define PROJ0_GRAPH_H

#include <list>
#include <map>

using namespace std;

template <class T>
class Vertex {
public:
    Vertex(){};
    Vertex(T id){
        this->id = id;
        this->visited = false;
    };

    T id;
    int pre;
    int post;
    bool visited;
    list<T> edges;
};

template <class T>
class Graph {
public:
    map<T, Vertex<T> *> vertices;

    Graph<T> reverse_graph();
    void reset_graph();

};

template <class T>
Graph<T> Graph<T>::reverse_graph(){
    Graph<T> g_r;

    for(auto it = vertices.begin(); it != vertices.end(); it++){
        g_r.vertices[(*it).second->id] = new Vertex<T>((*it).second->id);
    }
    for(auto it = vertices.begin(); it != vertices.end(); it++){
        for(auto it_v = (*it).second->edges.begin(); it_v != (*it).second->edges.end(); it_v++){
            (g_r.vertices[*it_v])->edges.push_back((*it).second->id);
        }
    }

    return g_r;
}

template <class T>
void Graph<T>::reset_graph(){
    for(auto it = vertices.begin(); it != vertices.end(); it++){
        (*it).second->visited = false;
    }
}

#endif //PROJ0_GRAPH_H
