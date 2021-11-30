#ifndef WIKIPEDIA_GRAPH_H
#define WIKIPEDIA_GRAPH_H
#include <string>
#include <unordered_set>
#include <vector>
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

    int inserted;
    int vertices;
    double sizeFactor;
    Node** graphArray;
    std::unordered_set<string> pages;

    unsigned int hashFunction(string name);
    bool insertHead(string name);
    int find(string name);
    void deleteNode(Node* n);

public:
    Graph();
    ~Graph();
    void inputGraph(std::vector<string> fileNames);
    void printEdges(string name);
    void printBFSPath(string start, string destination);
};

#endif //WIKIPEDIA_GRAPH_H
