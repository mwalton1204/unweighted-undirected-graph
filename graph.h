/*********************
Name: Michael Walton
COSC-2436-004
Purpose:
 - Design Graph Tree ADT
**********************/

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include "vertex.h"
#include <vector>
#include <utility>
#include <iostream>
#include <unordered_set>
#include <queue>
#include <stack>
#include <iomanip>

using std::vector;
using std::pair;
using std::make_pair;
using std::cout;
using std::unordered_set;
using std::queue;
using std::stack;
using std::setw;

class Graph {

public:
    Graph();
    ~Graph();

    bool addVertex(int, const string*);
    bool addEdge(int, int);
    bool removeVertex(int);
    bool removeEdge(int, int);
    bool getVertices(vector<Vertex>*);
    bool getEdges(vector<pair<int, int>>*);
    vector<Vertex> breadthFirstSearch(int);
    vector<Vertex> depthFirstSearch(int);
    void printAdjMatrix();
    bool vertexExists(int);
    bool edgeExists(int, int);
    bool getData(int, Vertex*);

private:
    int getVertexIndex(int);

    vector<Vertex> vertices;
    vector<pair<int, int>> edges;
    vector<vector<int>> adjMatrix;

};

#endif //GRAPH_GRAPH_H