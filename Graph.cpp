#include "Graph.h"
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>
using std::string;

unsigned int Graph::hashFunction(string name)
{
    //Standard C++ Hash Function
    std::hash<std::string> str_hash;
    unsigned int hashVal = str_hash(name);
    return hashVal;
}

void Graph::deleteNode(Node* n)
{
    // Recursively clear each list
    if (n != nullptr)
    {
        deleteNode(n->next);
        delete n;
    }
}

Graph::Graph()
{
    vertices = 0;
    mapSize = 200000;
}

Graph::~Graph()
{
    for (auto vertix : graphArray)
    {
        deleteNode(vertix.second);
    }
}

void Graph::inputGraph(std::vector<string> fileNames)
{
    // File reading object
    std::ifstream input;

    // Read the data
    for (int i = 0; i < fileNames.size(); i++)
    {
        // Open the file
        input.open(fileNames[i]);

        // Read data
        // Line Types:
        // 0 - Name of a Page
        // 1 - List of Links
        // 2 - Spacer
        int lineType = 0;
        string line;
        string page;

        if (input.is_open())
        {
            while (!input.eof())
            {
                if (lineType == 0)
                {
                    getline(input, line);
                    graphArray[line] = new Node(line, 0);
                    vertices++;
                    page = line;
                }

                // Help in this section from: https://stackoverflow.com/questions/37957080/can-i-use-2-or-more-delimiters-in-c-function-getline
                if (lineType == 1)
                {
                    getline(input, line);

                    // Create string stream to read through only the comma separated values
                    std::stringstream currentLine(line);
                    string l;

                    // Get the head of the list
                    Node* currentNode = graphArray[page];

                    // Count weight. Weight is the number of links above it on the page + 1;
                    int w = 1;

                    // Input data
                    while (getline(currentLine, l, ','))
                    {
                        // Replace underline with spaces
                        auto underline = l.find('_');
                        while (underline != string::npos) {
                                l.replace(underline, 1, " ");
                                underline = l.find('_');
                        }
    
                        currentNode->next = new Node(l, w);
                        currentNode = currentNode->next;
                        w++;
                    }
                }

                // Empty Line, just getline to skip
                if (lineType == 2)
                {
                    getline(input, line);
                }
                lineType++;
                lineType = lineType % 3;
            }
        }
        // Close file for next loop
        input.close();
    }

    std::cout << "Size of the graph: " << vertices << std::endl;
    std::cout << std::endl;
}

void Graph::printEdges(string name)
{
    std::cout << "Links on the page \"" << name << "\":" << std::endl;
    std::cout << std::endl;

    Node* currentNode = graphArray[name];

    while (currentNode->next != nullptr)
    {
        currentNode = currentNode->next;
        std::cout << currentNode->weight << ". " << currentNode->pageName << std::endl;
    }

    std::cout << std::endl;
}

void Graph::printBFSPath(string start, string destination)
{
    std::queue<std::vector<std::string>> q;
    std::set<int> visited;
    std::vector<std::string> path;

    path.push_back(start);
    visited.insert(hashFunction(start));
    q.push(path);

    while (!q.empty())
    {
        path = q.front();
        q.pop();
        string currPage = path[(path.size() - 1)];

        // Loops through links on page
        for (auto i = graphArray[currPage]; i != nullptr; i = i->next)
        {

            if (visited.count(hashFunction(i->pageName)) == 0)
            {
                visited.insert(hashFunction(i->pageName));

                //New vector made using current path and link added to path
                std::vector<std::string> nextPath = path;
                nextPath.push_back(i->pageName);
                q.push(nextPath);

                if (i->pageName == destination) {
                    for (auto page : nextPath) {
                        std::cout << page << std::endl;
                    }
                    return;
                }
            }
        }
    }
    std::cout << "Path to " << destination << " Not Found!" << std::endl;
}

void Graph::dijkstras(string start, string destination)
{
    // Initialize variables
    std::unordered_set<unsigned int> notVisited;
    std::unordered_map<int, std::pair<int, int>> dijkstras;
    std::unordered_map<int, string> pair;

    // Set all values to INT_MAX so they can be relaxed
    for (auto vertix : graphArray)
    {
        int index = hashFunction(vertix.second->pageName);
        pair[index] = vertix.second->pageName;
        notVisited.insert(index);
        dijkstras[index].first = INT_MAX;
        dijkstras[index].second = -1;
    }

    // Make sure the pages are in the graph
    int startLoc = hashFunction(start);
    int endLoc = hashFunction(destination);

    // Start relaxation
    dijkstras[startLoc].first = 0;
    Node* currList = graphArray[start];

    while (!notVisited.empty())
    {
        // Remove values from notVisited
        notVisited.erase(startLoc);

        // Get the current pages links
        while (currList != nullptr)
        {
            // Relax
            int page = hashFunction(currList->pageName);
            if (dijkstras[startLoc].first + currList->weight < dijkstras[page].first)
            {
                dijkstras[page].first = dijkstras[startLoc].first + currList->weight;
                dijkstras[page].second = startLoc;
            }

            // Go next
            currList = currList->next;
        }

        // Find the lowest value in shortestPath in notVisited
        unsigned int lowestValue = UINT_MAX;
        for (auto v : notVisited)
        {
            if (dijkstras[v].first < lowestValue)
            {
                lowestValue = dijkstras[v].first;
                startLoc = v;
                currList = graphArray[pair[v]];
            }
        }
    }

    // With all values set, go backwards to find path
    std::stack<int> path;
    while (endLoc != -1)
    {
        path.push(endLoc);
        endLoc = dijkstras[endLoc].second;
    }

    if (pair[path.top()] != start)
    {
        std::cout << "Path between \"" << start << "\" and \"" << destination << "\" could not be found." << std::endl;
    }

    // Now print the path
    int loc;
    Node* curr;
    while (!path.empty())
    {
        loc = path.top();
        path.pop();
        curr = graphArray[pair[loc]];
        std::cout << curr->pageName << " - Links down: " << curr->weight << std::endl;
    }
}

void Graph::bellmanFord(string start, string destination) {
    std::unordered_map<string, std::pair<int,string>> distMap;

    for (auto pair : graphArray) {
        distMap[pair.second->pageName] = std::make_pair(INT_MAX, "");
    }


    distMap[start].first = 0;
    distMap[start].second = start;
    
    for (int i = 0; i < graphArray.size() - 1; i++) {
        for (auto u : graphArray) {
            Node* vNode = u.second;
            while(vNode->next) {
                //Loops through all edges
                if (distMap[u.second->pageName].first + vNode->weight < distMap[vNode->pageName].first) {
                    distMap[vNode->pageName].first = distMap[u.second->pageName].first + vNode->weight;
                    distMap[vNode->pageName].second = u.second->pageName;
                }   
                vNode=vNode->next;
            }
        }
    }

    std::stack<std::string> s;
    s.push(destination);

    while (s.top() != start) {
        auto name = distMap[s.top()].second;
        s.push(name);
    }

    while(!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    std::cout << std::endl;

}