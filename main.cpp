/*********************
Name: Michael Walton
COSC-2436-004
Purpose:
 - Design Graph Tree ADT
**********************/

#include "main.h"

int main(int argc, char** argv) {

    srand (time(NULL));

    Graph graph;
    vector<Vertex> vertices; // empty vector of Vertex objects for retrieving vertices
    vector<pair<int, int>> edges;// empty vector of pairs or ints for retrieving edges
    Vertex emptyVertex; // empty Vertex object for retrieving data
    string testString; // test string for Vertex struct data element

    cout << "<-------------------\tTESTING INITIALIZED GRAPH\t------------------->\n\n";

    printGraphInfo(graph);

    cout << "\nATTEMPTING TO REMOVE VERTEX THAT DOES NOT EXIST [ID: 1]...\n";
    if (graph.removeVertex(1)) {
        cout << "VERTEX REMOVED\n";
    } else {
        cout << "VERTEX NOT REMOVED\n";
    }

    cout << "\nATTEMPTING TO REMOVE EDGE THAT DOES NOT EXIST [1, 2]...\n";
    if (graph.removeEdge(1, 2)) {
        cout << "EDGE REMOVED\n";
    } else {
        cout << "EDGE NOT REMOVED\n";
    }

    cout << "\nATTEMPTING TO RETRIEVE DATA FROM VERTEX THAT DOES NOT EXIST [ID: 1]...\n";
    if (graph.getData(1, &emptyVertex)) {
        cout << "DATA: " << emptyVertex.data << "\n\n";
    } else {
        cout << "DATA NOT RETRIEVED\n\n";
    }

    cout << "\n";

    cout << "<-------------------\tADDING VERTICES TO CREATE A 9x9 MATRIX AND RETRIEVING DATA FROM A VERTEX\t------------------->\n\n";

    for (auto i = 1; i < 10; i++) { //makes 9x9 matrix
        testString = to_string(i) + ", but a string!";
        cout << "ATTEMPTING TO ADD VERTEX [ID: " << i << ", DATA: " << testString << "]...\n";
        if (graph.addVertex(i, &testString)) {
            cout << "VERTEX ADDED\n\n";
        } else {
            cout << "VERTEX NOT ADDED\n\n";
        }
    }

    printData(1, graph);

    printGraphInfo(graph);

    cout << "<-------------------\tCHECKING IF VERTICES EXIST\t------------------->\n\n";

    for (int i = 0; i < 11; i++) {
        cout << "CHECKING IF VERTEX WITH ID " << i << " EXISTS...\n";
        if (graph.vertexExists(i)) {
            cout << "VERTEX WITH ID " << i << " EXISTS\n\n";
        } else {
            cout << "VERTEX WITH ID " << i << " DOES NOT EXIST\n\n";
        }
    }


    cout << "<-------------------\tADDING EDGES BETWEEN VERTICES SYSTEMATICALLY\t------------------->\n\n";

    for (int i = 1; i < 10; i++) {
        cout <<  "ATTEMPTING TO ADD EDGE BETWEEN VERTEX IDs [" << i << ", " << i+1 << "]...\n";
        if (graph.addEdge(i, i+1)) {
            cout << "EDGE ADDED\n\n";
        } else {
            cout << "EDGE NOT ADDED\n\n";
        }
    }

    printGraphInfo(graph);

    cout << "<-------------------\tCHECKING IF EDGES EXIST\t------------------->\n\n";

    for (int i = 0; i < 11; i++) {
        cout << "CHECKING IF EDGE BETWEEN VERTEX IDs [" << i << ", " << i+1 << "] EXISTS...\n";
        if (graph.edgeExists(i, i+1)) {
            cout << "EDGE BETWEEN VERTEX IDs [" << i << ", " << i+1 << "] EXISTS\n\n";
        } else {
            cout << "EDGE BETWEEN VERTEX IDs [" << i << ", " << i+1 << "] DOES NOT EXIST\n\n";
        }
    }

    cout << "<-------------------\tREMOVING FIRST, MIDDLE, LAST VERTEX\t------------------->\n\n";

    cout << "ATTEMPTING TO REMOVE VERTEX [ID: 1 DATA: " << testString << "]...\n";
    testString = to_string(1) + ", but a string!";
    if (graph.removeVertex(1)) {
        cout << "VERTEX REMOVED\n\n";
    } else {
        cout << "VERTEX NOT REMOVED\n\n";
    }

    testString = to_string(5) + ", but a string!";
    cout << "ATTEMPTING TO REMOVE VERTEX [ID: 5 DATA: " << testString << "]...\n";
    if (graph.removeVertex(5)) {
        cout << "VERTEX REMOVED\n\n";
    } else {
        cout << "VERTEX NOT REMOVED\n\n";
    }

    testString = to_string(9) + ", but a string!";
    cout << "ATTEMPTING TO REMOVE VERTEX [ID: 9 DATA: " << testString << "]...\n";
    if (graph.removeVertex(9)) {
        cout << "VERTEX REMOVED\n\n";
    } else {
        cout << "VERTEX NOT REMOVED\n\n";
    }

    printGraphInfo(graph);

    cout << "<-------------------\tREMOVING FIRST, MIDDLE, LAST EDGES\t------------------->\n\n";

    cout <<  "ATTEMPTING TO REMOVE EDGE BETWEEN VERTEX IDs [1, 2]...\n";
    if (graph.removeEdge(1, 2)) {
        cout << "EDGE REMOVED\n\n";
    } else {
        cout << "EDGE NOT REMOVED\n\n";
    }

    cout <<  "ATTEMPTING TO REMOVE EDGE BETWEEN VERTEX IDs [4, 5]...\n";
    if (graph.removeEdge(4, 5)) {
        cout << "EDGE REMOVED\n\n";
    } else {
        cout << "EDGE NOT REMOVED\n\n";
    }

    cout <<  "ATTEMPTING TO REMOVE EDGE BETWEEN VERTEX IDs [8, 9]...\n";
    if (graph.removeEdge(8, 9)) {
        cout << "EDGE REMOVED\n\n";
    } else {
        cout << "EDGE NOT REMOVED\n\n";
    }

    printGraphInfo(graph);

    cout << "<-------------------\tEMPTYING MATRIX\t------------------->\n\n";

    cout <<  "ATTEMPTING TO EMPTY MATRIX...\n";
    graph.getVertices(&vertices);
    for (const auto& vertex : vertices) {
        graph.removeVertex(vertex.id);
    }

    graph.getVertices(&vertices);
    if (vertices.size() == 0) {
        cout << "MATRIX EMPTIED\n\n";
    } else {
        cout << "MATRIX NOT EMPTIED\n\n";
    }

    printGraphInfo(graph);

    cout << "<-------------------\tCREATING MATRIX OF RANDOM SIZE (2 to 15) USING RANDOM VALUES (0 to 99)\t------------------->\n\n";

    int matrixSize = rand() % 15 + 2;

    cout << "CREATING A " << matrixSize << " x " << matrixSize << " MATRIX OF RANDOM ID's...\n\n";

    for (auto i = 0; i < matrixSize; i++) {
        int testId = rand() % 99;
        testString = to_string(testId) + ", but a string!";
        cout << "ATTEMPTING TO ADD VERTEX [ID: " << testId << ", DATA: " << testString << "]...\n";
        if (graph.addVertex(testId, &testString)) {
            cout << "VERTEX ADDED\n\n";
        } else {
            cout << "VERTEX NOT ADDED\n\n";
        }
    }

    printGraphInfo(graph);

    cout << "<-------------------\tCREATING RANDOM QTY OF EDGES BETWEEN RANDOM VERTICES\t------------------->\n\n";

    int minEdges = 2;
    int maxEdges = matrixSize * 2;
    int qtyEdges = rand() % maxEdges + minEdges;

    graph.getVertices(&vertices);

    cout << "ADDING " << qtyEdges << " RANDOM EDGES BETWEEN VERTICES ON THE MATRIX...\n\n";

    for (int i = 0; i < qtyEdges; i++) {
        int startVertex = vertices[rand() % matrixSize].id;
        int endVertex = vertices[rand() % matrixSize].id;

        cout <<  "ATTEMPTING TO ADD EDGE BETWEEN VERTEX IDs [" << startVertex << ", " << endVertex << "]...\n";
        if (graph.addEdge(startVertex, endVertex)) {
            cout << "EDGE ADDED\n\n";
        } else {
            cout << "EDGE NOT ADDED\n\n";
        }
    }

    printGraphInfo(graph);

    cout << "<-------------------\tREMOVING RANDOM VERTICES\t------------------->\n\n";

    int qtyToRemove = rand() % matrixSize + 1;

    cout << "ATTEMPTING TO REMOVE "<< qtyToRemove << " VERTICES...\n\n";

    for (int i = 0; i < qtyToRemove; i++) {
        int vertexToRemove = vertices[rand() % matrixSize].id;
        testString = to_string(i) + ", but a string!";
        cout << "ATTEMPTING TO REMOVE VERTEX [ID: " << vertexToRemove << " DATA: " << testString << "]...\n";
        if (graph.removeVertex(vertexToRemove)) {
            cout << "VERTEX REMOVED\n\n";
        } else {
            cout << "VERTEX NOT REMOVED\n\n";
        }
    }

    printGraphInfo(graph);

    cout << "<-------------------\tEMPTYING CURRENT MATRIX AND CREATING NEW 5 x 5 MATRIX\t------------------->\n\n";

    cout <<  "EMPTYING MATRIX...\n";
    graph.getVertices(&vertices);
    for (const auto& vertex : vertices) {
        graph.removeVertex(vertex.id);
    }
    cout << "\n";

    cout <<  "CREATING BASIC 5 x 5 MATRIX...\n";
    for (auto i = 1; i < 6; i++) {
        testString = to_string(i) + ", but a string!";
        graph.addVertex(i, &testString);
    }

    printGraphInfo(graph);

    int qtyOperations = rand() % 30 + 10;
    cout << "<-------------------\tPERFORMING " << qtyOperations << " RANDOMIZED OPERATIONS\t------------------->\n\n";

    graph.getVertices(&vertices);
    graph.getEdges(&edges);

    for (int i = 0; i < qtyOperations; i++) {

        int operationType = rand() % 7 + 1;
        int randId = rand() % 99 + 1;
        int randIndex;
        int randIndex2;

        if (!vertices.empty()) { // avoids cases where empty vertices vector would cause division by 0
            randIndex = rand() % vertices.size();
            randIndex2 = rand() % vertices.size();
        }

        switch (operationType) {
            case 1: // add vertex with random id between 1-99
                testString = to_string(randId) + ", but a string!";
                cout << "ATTEMPTING TO ADD VERTEX [ID: " << randId << " DATA: " << vertices[randIndex].data << "]...\n";
                if (graph.addVertex(randId, &testString)) {
                    cout << "VERTEX ADDED\n\n";
                } else {
                    cout << "VERTEX NOT ADDED\n\n";
                }

                break;

            case 2: // remove random vertex
                if (!vertices.empty()) {
                    testString = to_string(randId) + ", but a string!";
                    cout << "ATTEMPTING TO REMOVE VERTEX [ID: " << vertices[randIndex].id << " DATA: "
                         << vertices[randIndex].data << "]...\n";
                    if (graph.removeVertex(vertices[randIndex].id)) {
                        cout << "VERTEX REMOVED\n\n";
                    } else {
                        cout << "VERTEX NOT REMOVED\n\n";
                    }
                }

                break;

            case 3: // add edge between 2 random vertices
                if (!vertices.empty() && randIndex >= 0 && randIndex2 >= 0 && randIndex < vertices.size() && randIndex2 < vertices.size()) {
                    cout << "ATTEMPTING TO ADD EDGE BETWEEN VERTEX IDs [" << vertices[randIndex].id << ", "
                         << vertices[randIndex2].id << "]...\n";
                    if (graph.addEdge(vertices[randIndex].id, vertices[randIndex2].id)) {
                        cout << "EDGE ADDED\n\n";
                    } else {
                        cout << "EDGE NOT ADDED\n\n";
                    }
                }

                break;

            case 4: // remove edge between 2 random vertices
                if (!vertices.empty() && randIndex >= 0 && randIndex2 >= 0) {
                    cout << "ATTEMPTING TO REMOVE EDGE BETWEEN VERTEX IDs [" << vertices[randIndex].id << ", "
                         << vertices[randIndex2].id << "]...\n";
                    if (graph.removeEdge(vertices[randIndex].id, vertices[randIndex2].id)) {
                        cout << "EDGE REMOVED\n\n";
                    } else {
                        cout << "EDGE NOT REMOVED\n\n";
                    }
                }

                break;

            case 5: // check if vertex with random id between 1-99 exists
                cout << "CHECKING IF VERTEX WITH ID " << randId << " EXISTS...\n";
                if (graph.vertexExists(randId)) {
                    cout << "VERTEX WITH ID " << randId << " EXISTS\n\n";
                } else {
                    cout << "VERTEX WITH ID " << randId << " DOES NOT EXIST\n\n";
                }

                break;

            case 6: // check if edge between random vertices exists
                if (!vertices.empty() && randIndex >= 0 && randIndex2 >= 0 && randIndex < vertices.size() && randIndex2 < vertices.size()) {
                    cout << "CHECKING IF EDGE BETWEEN VERTEX IDs [" << vertices[randIndex].id << ", "
                         << vertices[randIndex2].id << "] EXISTS...\n";
                    if (graph.edgeExists(randIndex, randIndex2)) {
                        cout << "EDGE BETWEEN VERTEX IDs [" << vertices[randIndex].id << ", " << vertices[randIndex2].id
                             << "] EXISTS\n\n";
                    } else {
                        cout << "EDGE BETWEEN VERTEX IDs [" << vertices[randIndex].id << ", " << vertices[randIndex2].id
                             << "] DOES NOT EXIST\n\n";
                    }
                }

                break;

            case 7: // getting data from random vertex
                if (!vertices.empty()) {
                    printData(vertices[randIndex].id, graph);
                }

                break;
        }
    }

    printGraphInfo(graph);

    return 0;
}