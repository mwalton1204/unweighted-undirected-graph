# Graph

This is a basic implementation of an unweighted, undirected graph ADT in C++. The graph class provides various methods for managing vertices and edges, performing graph traversals, and retrieving graph data.

## Features

- `addVertex(int id, string* data)`: Adds a new vertex to the graph.
- `addEdge(int startVertex, int endVertex)`: Adds an edge between two vertices in the graph.
- `removeVertex(int id)`: Removes a vertex and all its associated edges from the graph.
- `removeEdge(int startVertex, int endVertex)`: Removes an edge between two vertices from the graph.
- `getVertices(vector<Vertex>* emptyVector)`: Modifies an empty vector passed by reference to  contain all the vertices in the graph.
- `getEdges(vector<pair<int, int>>* emptyVector)`: Modifies an empty vector passed by reference to  contain all the edges in the graph.
- `breadthFirstSearch(int startVertex)`: Performs a breadth-first search traversal starting from the specified vertex.
- `depthFirstSearch(int startVertex)`: Performs a depth-first search traversal starting from the specified vertex.
- `printAdjMatrix()`: Prints the adjacency matrix representation of the graph.
- `vertexExists(int id)`: Checks if a vertex exists in the graph.
- `edgeExists(int startVertex, int endVertex)`: Checks if an edge exists between two vertices in the graph.
- `getData(int id, Vertex* emptyVertex)`: Retrieves the data from a specific vertex on the graph.

## Usage

Here's an example of how to use the graph class:

```cpp
// Include the graph class header
#include "graph.h"

// Create an instance of the graph
Graph myGraph;

// Create variables for the vertex data
std::string vertex1Data = "Vertex 1";
std::string vertex2Data = "Vertex 2";
std::string vertex3Data = "Vertex 3";

// Add vertices
myGraph.addVertex(1, &vertex1Data);
myGraph.addVertex(2, &vertex2Data);
myGraph.addVertex(3, &vertex3Data);

// Add edges
myGraph.addEdge("A", "B");
myGraph.addEdge("B", "C");
myGraph.addEdge("C", "A");

// Perform a breadth-first search
vector<Vertex> bfs = myGraph.breadthFirstSearch(1);

for (const auto &vertex: bfs) {
std::cout << vertex.id << " ";
}

// Print the adjacency matrix
myGraph.printAdjMatrix();
```


## What I Learned

During the implementation of this graph class in C++, I learned and applied several key concepts and techniques. Some of the notable ones include:

- **Pairs**: I used pairs to represent edges in the graph, where each edge is represented by a pair of vertices.
- **Unordered Sets**: I utilized unordered sets to store vertex ID's efficiently for search operations.
- **Vectors and 2D Vectors**: I used vectors to store Vertices and edge pairs, as well as to represent an adjacency matrix.
- **DFS and BFS Algorithms**: I implemented depth-first search (DFS) and breadth-first search (BFS) algorithms for traversing the graph and exploring its vertices and edges.
- **Passing Variables by Reference**: I leveraged passing variables by reference to efficiently retrieve information from the graph data structure during various operations, such as getting vertices, edges and data.
- **Manipulating Vectors and 2D Vectors**: I gained experience in manipulating vectors and 2D vectors, including adding elements, removing elements, and accessing specific elements based on the requirements of the graph operations.
- **Input and Output Manipulation**: I utilized the iomanip library to format the output, such as printing the adjacency matrix in a visually appealing manner.
- **Markdown Formatting**: I learned and applied Markdown formatting techniques to create a well-structured and readable README file for this project, including headings, code blocks, and emphasis on important points.

These concepts and techniques enabled me to create a basic yet functional graph class implementation in C++.

