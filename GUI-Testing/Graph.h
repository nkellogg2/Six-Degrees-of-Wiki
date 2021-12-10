#ifndef WIKIPEDIA_GRAPH_H
#define WIKIPEDIA_GRAPH_H
#include <string>
#include <unordered_map>
#include <vector>
#include <chrono>
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
    int mapSize;
    int numLinks;
    std::unordered_map<std::string, Node*> graphArray;

    unsigned int hashFunction(string name);
    void deleteNode(Node* n);


public:
    Graph();
    ~Graph();
    int getVertices();
    int getNumLinks();
    void inputGraph(std::vector<string> fileNames);
    string getRandomNode();

    void printEdges(string name);
    void printBFSPath(string start, string destination);
    void dijkstras(string start, string destination);
    void bellmanFord(string start, string destination);

    std::vector<string> getEdges(string name);
    std::vector<string> getBFSPath(string start, string destination);
    std::vector<std::pair<int, string>> getDijkstrasPath(string start, string destination);
    std::vector<std::pair<int, string>> getBellmanPath(string start, string destination);
};

// needed renamed function for use in MakeGraph.h without linker errors TODO: (maybe try and remove after merge)
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
