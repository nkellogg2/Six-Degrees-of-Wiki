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
    int numLinks;
    double sizeFactor;
    Node** graphArray;
    std::unordered_set<string> pages;

    unsigned int hashFunction(string name);
    void insertHead(string name);
    int find(string name);
    void deleteNode(Node* n);


public:
    Graph();
    ~Graph();
    int getNumVertices();
    int getPagesInserted();
    int getNumLinks();
    void inputGraph(std::vector<string> fileNames);
    std::vector<string> getEdges(string name);
    void printEdges(string name);
    void printBFSPath(string start, string destination);
    std::vector<std::pair<int, string>> getBFSPath(string start, string destination);
    void bellmanFord(string start, string destination);
    std::vector<std::pair<int, string>> getBellmanPath(string start, string destination);
};

// needed renamed function for use in MakeGraph.h without linker errors
bool inline isValidNumber(string num)
{
    for (int i = 0; i < num.length(); i++)
    {
        if (!std::isdigit(num[i]))
        {
            return false;
        }
    }

    int value = std::stoi(num);

    if (value < 1)
        return false;

    return true;
}

#endif //WIKIPEDIA_GRAPH_H
