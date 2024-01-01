/*********************
Name: Michael Walton
COSC-2436-004
Purpose:
 - Design Graph Tree ADT
**********************/

#include "functions.h"

void printMatrix(Graph graph) {
    cout << "ADJACENCY MATRIX:\n\n";
    graph.printAdjMatrix();
}

void printVertices(Graph graph) {
    vector<Vertex> vertices;

    cout << "\nVERTICES:\n";
    graph.getVertices(&vertices);
    for (const auto& vertex : vertices) {
        cout << "ID: " << vertex.id << " DATA: " << vertex.data << "\n";
    }
}

void printEdges(Graph graph) {
    vector<pair<int, int>> edges;

    cout << "\n\nEDGES:\n";
    graph.getEdges(&edges);
    for (const auto& edge : edges) {
        cout << "[" << edge.first << ", " << edge.second << "]\n";
    }
}

void printBFS(Graph graph) {
    vector<Vertex> vertices;
    graph.getVertices(&vertices);

    cout << "\n\nBREADTH FIRST SEARCH (START VERTEX = vertices[0]):\n";
    if (!vertices.empty()) {
        vector<Vertex> bfs = graph.breadthFirstSearch(vertices[0].id);
        for (const auto &vertex: bfs) {
            if (vertex.id != bfs[bfs.size() - 1].id) {
                cout << vertex.id << " -> ";
            } else {
                cout << vertex.id << "\n";
            }
        }
    }
}

void printDFS(Graph graph) {
    vector<Vertex> vertices;
    graph.getVertices(&vertices);

    cout << "\n\nDEPTH FIRST SEARCH (START VERTEX = vertices[0]):\n";
    if (!vertices.empty()) {
        vector<Vertex> dfs = graph.depthFirstSearch(vertices[0].id);
        for (const auto &vertex: dfs) {
            if (vertex.id != dfs[dfs.size() - 1].id) {
                cout << vertex.id << " -> ";
            } else {
                cout << vertex.id << "\n";
            }
        }
    }
}

void printData(int id, Graph graph) {
    Vertex emptyVertex;

    cout << "ATTEMPTING TO RETRIEVE DATA FROM VERTEX ID: " << id << "...\n";
    if (graph.getData(id, &emptyVertex)) {
        cout << "DATA: " << emptyVertex.data << "\n\n";
    } else {
        cout << "DATA NOT RETRIEVED\n\n";
    }
}

void printGraphInfo (Graph graph) {
    printMatrix(graph);
    printVertices(graph);
    printEdges(graph);
    printBFS(graph);
    printDFS(graph);
    cout << "\n";
}