#ifndef WIKIPEDIA_GRAPH_H
#define WIKIPEDIA_GRAPH_H
#include <string>
using std::string;

class Graph
{
private:
    struct Node
    {
        string pageName;
        unsigned int weight;
        Node* next;

        // I'm not sure how I can get the constructor definitions into the Graph.cpp file
        // I could make Node class a public member of Graph but I think it makes more sense for it to be private
        Node()
        {
            pageName = "";
            weight = 0;
            next = nullptr;
        };
        Node(string n, int w)
        {
            pageName = n;
            weight = w;
            next = nullptr;
        };
    };

    int vertices;
    double sizeFactor;
    Node** graphArray;

    unsigned int hashFunction(string name, unsigned int size);
    void insertHead(string name);
    int find(string name);
    void deleteNode(Node* n);

public:
    Graph();
    ~Graph();
    void inputGraph(string fileName);
    void printEdges(string name);
};

#endif //WIKIPEDIA_GRAPH_H
