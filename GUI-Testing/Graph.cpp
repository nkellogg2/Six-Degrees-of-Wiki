#include "Graph.h"
#include <string>
#include <queue>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>
#include <unordered_set>
using std::string;

unsigned int Graph::hashFunction(string name)
{
    //Standard C++ Hash Function
    std::hash<std::string> str_hash;
    return (str_hash(name) % vertices);
}

bool Graph::insertHead(string name)
{
    if (pages.count(name) == 0)
    {
        // Get original hash value for the page name
        unsigned int location = hashFunction(name);

        // Find first open spot at or after the initial location
        while (!graphArray[location]->pageName.empty())
        {
            if (graphArray[location]->pageName == name)
            {
                return false;
            }
            location++;
            location = location % vertices;
        }

        graphArray[location]->pageName = name;
        pages.insert(name);
        inserted++;
        return true;
    }
    return false;
}

int Graph::find(string name)
{
    // Get original hash value for the page name
    unsigned int location = hashFunction(name);

    // Used to detect a loop, only happens when name does not exist in the graph
    unsigned int loc = location;
    int loops = -1;

    // Find the location
    while (graphArray[loc]->pageName != name && loops < 1)
    {
        if (loc == location)
            loops++;
        loc++;
        loc = loc % vertices;
    }

    if (loops == 1)
        return -1;
    return loc;
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
    inserted = 0;
    vertices = 0;
    numLinks = 0;
    sizeFactor = 1.5; // NEVER below 1
    graphArray = new Node*[1];
}

Graph::~Graph()
{
    for (int i = 0; i < vertices; i++)
    {
        deleteNode(graphArray[i]);
    }
    delete[] graphArray;
}

int Graph::getNumVertices() {
    return vertices;
}

int Graph::getNumLinks() {
    return numLinks;
}

int Graph::getPagesInserted() {
    return inserted;
}

void Graph::inputGraph(std::vector<string> fileNames)
{
    // File reading object
    std::ifstream input;

    // Reading the input size
    numLinks = 0;
    int lines = 0;
    for (int i = 0; i < fileNames.size(); i++)
    {
        // Open the files
        input.open(fileNames[i]);

        // Read how many lines, then divide by three
        // Not super efficient but this will mean no resizing
        string line;
        if (input.is_open())
        {
            while (!input.eof())
            {
                getline(input, line);
                lines++;
            }
        }
        else
        {
            std::cout << "Sorry, couldn't open \"" << fileNames[i] << "\""<< std::endl;
            std::cout << std::endl;
        }

        // Close file for next loop
        input.close();
    }

    // Set the graph to the correct size and update vertices;
    // Size factor adds extra space to reduce likelihood of collisions
    lines = lines / 3;
    vertices = (int)(lines * sizeFactor);
    delete[] graphArray;
    graphArray = new Node*[vertices];
    for (int i = 0; i < vertices; i ++)
    {
        graphArray[i] = new Node;
    }

    // Actually read the data
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
        bool duplicate = false;
        if (input.is_open())
        {
            while (!input.eof())
            {
                if (lineType == 0)
                {
                    getline(input, line);
                    duplicate = !insertHead(line);
                    page = line;
                }
                // Help in this section from: https://stackoverflow.com/questions/37957080/can-i-use-2-or-more-delimiters-in-c-function-getline
                if (lineType == 1)
                {
                    // First make sure this page isn't a duplicate page
                    if (!duplicate)
                    {
                        // Find the page, make sure it exists
                        int index = find(page);
                        if (index != -1)
                        {
                            // Get the entire line input
                            getline(input, line);

                            // Create string stream to read through only the comma separated values
                            std::stringstream currentLine(line);
                            string l;

                            // Get the head of the list
                            Node* currentNode = graphArray[index];

                            // Count weight. Weight is the number of links above it on the page + 1;
                            int w = 1;

                            // Input data
                            while (getline(currentLine, l, ','))
                            {
                                // Replace underline with spaces
                                for (int j = 0; j < l.length(); j++)
                                {
                                    if (l[j] == '_')
                                        l[j] = ' ';
                                }

                                // To-Do: Don't insert if it is a 'File:...' or other special link such as pronunciation

                                currentNode->next = new Node(l, w);
                                currentNode = currentNode->next;
                                w++;
                                numLinks++;
                            }
                        }
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
    std::cout << "Pages inserted: " << inserted << std::endl;
    std::cout << "Links added: " << numLinks << std::endl;
    std::cout << std::endl;
}

std::vector<string> Graph::getEdges(string name) {
    std::vector<string> edges;
    int index = find(name);

    if (index == -1) {
        return edges;
    }
    else {
        Node* currentNode = graphArray[index];

        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
            edges.push_back(currentNode->pageName);
        }
        return edges;
    }
}

void Graph::printEdges(string name)
{
    int index = find(name);

    if (index == -1)
    {
        std::cout << "Sorry, \"" << name << "\" could not be found in this graph" << std::endl;
    }
    else
    {
        std::cout << "Links on the page \"" << name << "\":" << std::endl;
        std::cout << std::endl;

        Node* currentNode = graphArray[index];

        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
            std::cout << currentNode->weight << ". " << currentNode->pageName << std::endl;
        }
    }
    std::cout << std::endl;
}

void Graph::printBFSPath(string start, string destination)
{
    int src = find(start);
    int dest = find(destination);
    std::queue<std::vector<std::pair<int, std::string>>> q;
    std::set<int> visited;
    std::vector<std::pair<int, std::string>> path;

    path.push_back(make_pair(src, start));
    visited.insert(src);
    q.push(path);

    while (!q.empty())
    {
        path = q.front();
        q.pop();
        int currPage = path[(path.size() - 1)].first;

        for (auto i = graphArray[currPage]; i != nullptr; i = i->next)
        {
            int currIndex = hashFunction(i->pageName);

            if (visited.count(currIndex) == 0)
            {
                visited.insert(currIndex);

                //New vector made using current path and link added to path
                std::vector<std::pair<int, std::string>> nextPath = path;
                nextPath.push_back(make_pair(currIndex,i->pageName));
                q.push(nextPath);

                if (graphArray[currIndex]->pageName == destination) {
                    for (auto page : nextPath) {
                        std::cout << page.second << std::endl;
                    }
                    return;
                }
            }
        }
    }
    std::cout << "Path to " << destination << " Not Found!" << std::endl;
}

std::vector<std::pair<int, string>> Graph::getBFSPath(string start, string destination) {
    int src = find(start);
    int dest = find(destination);
    std::queue<std::vector<std::pair<int, std::string>>> q;
    std::set<int> visited;
    std::vector<std::pair<int, std::string>> path;

    path.push_back(make_pair(src, start));
    visited.insert(src);
    q.push(path);

    while (!q.empty())
    {
        path = q.front();
        q.pop();
        int currPage = path[(path.size() - 1)].first;

        for (auto i = graphArray[currPage]; i != nullptr; i = i->next)
        {
            int currIndex = hashFunction(i->pageName);

            if (visited.count(currIndex) == 0)
            {
                visited.insert(currIndex);

                //New vector made using current path and link added to path
                std::vector<std::pair<int, std::string>> nextPath = path;
                nextPath.push_back(make_pair(currIndex, i->pageName));
                q.push(nextPath);

                if (graphArray[currIndex]->pageName == destination) {
                    /*for (auto page : nextPath) {
                        std::cout << page.second << std::endl;
                    }*/
                    return nextPath;
                }
            }
        }
    }
    std::vector<std::pair<int, std::string>> emptyVec;
    return emptyVec;
}