/*********************
Name: Michael Walton
COSC-2436-004
Purpose:
 - Design Graph Tree ADT
**********************/

#include "graph.h"

Graph::Graph() {}

Graph::~Graph() {}

bool Graph::addVertex(int id, const string* data) {
    bool added = false;

    if (!vertexExists(id)) {
        Vertex newVertex = Vertex{id, *data};
        vertices.push_back(newVertex);

        const int newSize = vertices.size();

        for (int i = 0; i < newSize - 1; ++i) { // creates new column in adjacency matrix
            adjMatrix[i].push_back(0);
        }
        adjMatrix.push_back(vector<int>(newSize, 0)); // creates new row in adjacency matrix

        added = true;
    }

    return added;
}

bool Graph::addEdge(int startVertex, int endVertex) {
    bool added = false;
    int indexV1, indexV2 = -1;

    if (!edgeExists(startVertex, endVertex)) {
        if (vertices.size() > 1) {
            indexV1 = getVertexIndex(startVertex);
            indexV2 = getVertexIndex(endVertex);
        }

        if (indexV1 != indexV2 && indexV1 > -1 && indexV2 > -1) {
            edges.push_back(make_pair(startVertex, endVertex)); // add to vector of edge pairs
            adjMatrix[indexV1][indexV2] = 1; // update adjacency matrix
            adjMatrix[indexV2][indexV1] = 1;
            added = true;
        }
    }

    return added;
}

bool Graph::removeVertex(int id) {
    bool removed = false;

    for (int i = 0; i < vertices.size(); ++i) {
        if (vertices[i].id == id) {
            vertices.erase(vertices.begin() + i);  // remove the vertex from vector of vertices

            adjMatrix.erase(adjMatrix.begin() + i);  // remove row in adjacency matrix
            for (auto& row : adjMatrix) {
                row.erase(row.begin() + i);  // remove corresponding column from each row in adjacency matrix
            }

            auto edgeIterator = edges.begin();
            while (edgeIterator != edges.end()) { // removes edges related to removed vector
                if (edgeIterator->first == id || edgeIterator->second == id) {
                    edgeIterator = edges.erase(edgeIterator);
                } else {
                    ++edgeIterator;
                }
            }

            removed = true;
        }
    }

    return removed;
}

bool Graph::removeEdge(int startVertex, int endVertex) {
    bool removed = false;

    if (vertices.size() > 1 && startVertex != endVertex) {
        int indexV1 = getVertexIndex(startVertex);
        int indexV2 = getVertexIndex(endVertex);

        if (indexV1 > -1 && indexV2 > -1) {
            pair<int, int> edgeToRemove = make_pair(startVertex, endVertex);

            for (int i = 0; i < edges.size(); i++) { // remove edge from vector of edge pairs
                if (edges[i] == edgeToRemove) {
                    edges.erase(edges.begin() + i);
                }
            }

            adjMatrix[indexV1][indexV2] = 0; // update adjacency matrix
            adjMatrix[indexV2][indexV1] = 0;

            removed = true;
        }
    }

    return removed;
}

bool Graph::getVertices(vector<Vertex>* emptyVector) {
    bool retrieved = false;
    emptyVector->clear();

    if(vertices.size() > 0) {
        *emptyVector = vertices;
        retrieved = true;
    }

    return retrieved;
}

bool Graph::getEdges(vector<pair<int, int>>* emptyVector) {
    bool retrieved = false;
    emptyVector->clear();

    if(edges.size() > 0) {
        *emptyVector = edges;
        retrieved = true;
    }

    return retrieved;
}

vector<Vertex> Graph::breadthFirstSearch(int startVertex) {
    vector<Vertex> result;
    queue<int> vertexQueue;
    unordered_set<int> visited;

    vertexQueue.push(startVertex);
    visited.insert(startVertex);

    while (!vertexQueue.empty()) {
        int currentId = vertexQueue.front();
        vertexQueue.pop();

        for (const Vertex& vertex: vertices) {
            if (vertex.id == currentId) {
                result.push_back(vertex);
            }
        }

        for (const pair<int, int>& edge : edges) {
            if (edge.first == currentId && visited.count(edge.second) == 0) {
                vertexQueue.push(edge.second);
                visited.insert(edge.second);
            } else if (edge.second == currentId && visited.count(edge.first) == 0) {
                vertexQueue.push(edge.first);
                visited.insert(edge.first);
            }
        }
    }

    return result;
}

vector<Vertex> Graph::depthFirstSearch(int startVertex) {
    vector<Vertex> result;
    stack<int> vertexStack;
    unordered_set<int> visited;

    vertexStack.push(startVertex);
    visited.insert(startVertex);

    while (!vertexStack.empty()) {
        int currentId = vertexStack.top();
        vertexStack.pop();

        for (const Vertex& vertex : vertices) {
            if (vertex.id == currentId) {
                result.push_back(vertex);
            }
        }

        for (const pair<int, int>& edge : edges) {
            if (edge.first == currentId && visited.count(edge.second) == 0) {
                vertexStack.push(edge.second);
                visited.insert(edge.second);
            } else if (edge.second == currentId && visited.count(edge.first) == 0) {
                vertexStack.push(edge.first);
                visited.insert(edge.first);
            }
        }
    }

    return result;
}

void Graph::printAdjMatrix() {
    cout << setw(5) << "";
    for (const Vertex& vertex : vertices) {
        cout << setw(3) << vertex.id;
    }
    cout << "\n\n";

    for (int i = 0; i < adjMatrix.size(); ++i) {
        cout << setw(3) << vertices[i].id << "  ";
        for (int val : adjMatrix[i]) {
            cout << setw(3) << val;
        }
        cout << "\n";
    }
}

bool Graph::vertexExists(int id) {
    bool exists = false;

    for (Vertex v: vertices) {
        if (v.id == id) {
            exists = true;
        }
    }

    return exists;
}

bool Graph::edgeExists(int startVertex, int endVertex) {
    bool exists = false;

    for (const auto& edge : edges) {
        if ((edge.first == startVertex && edge.second == endVertex) || (edge.first == endVertex && edge.second == startVertex)) {
            exists = true;
        }
    }

    return exists;
}

bool Graph::getData(int id, Vertex* emptyVertex) {
    bool retrieved = false;

    for (const auto& vertex : vertices) {
        if (vertex.id == id) {
            emptyVertex->data = vertex.data;
            retrieved = true;
        }
    }

    return retrieved;
}

int Graph::getVertexIndex(int vertexId) {
    int index = -1;

    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i].id == vertexId) {
            index = i;
        }
    }

    return index;
}