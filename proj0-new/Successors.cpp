/*
 * Author:                 Yufan Xu
 * Assignment Title:       Graph
 * Assignment Description: This program takes a text file as
 *                         input and finds all vertices of a
 *                         specific vertex on the graph, then
 *                         it displays the result on screen
 * Due Date:               08/27/2018
 * Date Created:           08/23/2018
 * Date Last Modified:     08/25/2012
 */

#include "Graph.h"

template <class T>
list<T> successors(Graph<T>& g, T t) {

    //create an empty list
    list<T> res;

    //make a list of all the successors of the vertex
    //use find(t) function to find the key value t,
    //which is the vertex that we suppose to find, then
    //find all the successors' IDs by traversing through
    //the edges from that vertex
    res = g.vertices.find(t)->second->edges;

    //return the list of all successors
    return res;
}