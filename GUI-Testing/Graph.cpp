#include "Graph.h"
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>
#include <unordered_set>
#include <unordered_map>
using std::string;

unsigned int Graph::hashFunction(string name)
{
    //Standard C++ Hash Function
    std::hash<std::string> str_hash;
    return str_hash(name);
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
    numLinks = 0;
    mapSize = 200000;
}

Graph::~Graph()
{
    for (auto vertix : graphArray)
    {
        deleteNode(vertix.second);
    }
}


int Graph::getNumLinks() {
    return numLinks;
}

int Graph::getVertices() {
    return vertices;
}

void Graph::inputGraph(std::vector<string> fileNames)
{
    numLinks = 0;
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
                    if (!graphArray[line]) {
                        graphArray[line] = new Node(line, 0);
                    }
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
                        numLinks++;
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
    vertices = graphArray.size();
    std::cout << "Size of the graph: " << vertices << std::endl;
    std::cout << "Number of links: " << numLinks << std::endl;
    std::cout << std::endl;
}

string Graph::getRandomNode() {
    if (vertices == 0) {
        return "";
    }
     // random NON EMPTY unordered_map element
    // 2% chance for each element, runs until one is chosen
    int random = rand() % 101;
    while (true) {
        for (auto vertix : graphArray) {
            if (random < 3) {
                return vertix.first;
            }
            random = rand() % 101;
        }
    }

}

std::vector<string> Graph::getEdges(string name) {
    std::vector<string> edges;
    if (name == "") {
        return edges;
    }
    Node* currentNode;
    if (graphArray[name]) {
        currentNode = graphArray[name];
    }
    else {
        return edges;
    }

    
    if (!currentNode->next) {
        return edges;
    }

    while (currentNode->next != nullptr)
    {
        currentNode = currentNode->next;
        edges.push_back(currentNode->pageName);
    }
    return edges;
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

    if (!graphArray[start] || !graphArray[destination]) {
        std::cout << "Path between \"" << start << "\" and \"" << destination << "\" could not be found." << std::endl;
        return;
    }

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

std::vector<string> Graph::getBFSPath(string start, string destination) {
    std::queue<std::vector<std::string>> q;
    std::set<int> visited;
    std::vector<std::string> path;

    if (!graphArray[start] || !graphArray[destination]) {
        // std::cout << "Path between \"" << start << "\" and \"" << destination << "\" could not be found." << std::endl;
        return path;
    }

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
                    /*for (auto page : nextPath) {
                        std::cout << page << std::endl;
                    }*/
                    return nextPath;
                }
            }
        }
    }
    std::vector<std::string> emptyVec;
    return emptyVec;
}

void Graph::dijkstras(string start, string destination)
{
    // Initialize variables
    std::unordered_set<unsigned int> notVisited;
    std::unordered_map<int, std::pair<int, int>> dijkstras;
    std::unordered_map<int, string> pair;

    if (!graphArray[start] || !graphArray[destination]) {
        std::cout << "Path between \"" << start << "\" and \"" << destination << "\" could not be found." << std::endl;
        return;
    }

    // Set all values to INT_MAX so they can be relaxed
    for (auto vertix : graphArray)
    {
        auto node = vertix.second;
        while (node) {
            int index = hashFunction(node->pageName);
            pair[index] = node->pageName;
            notVisited.insert(index);
            dijkstras[index].first = INT_MAX;
            dijkstras[index].second = -1;
            node = node->next;
        }
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
    int pathWeight = dijkstras[endLoc].first;
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
        std::cout << curr->pageName << std::endl;
    }
    std::cout << "Weight of Path: " << pathWeight << std::endl;
}

std::vector<std::pair<int, string>> Graph::getDijkstrasPath(string start, string destination) {
    // Initialize variables
    std::unordered_set<unsigned int> notVisited;
    std::unordered_map<int, std::pair<int, int>> dijkstras;
    std::unordered_map<int, string> pair;
    std::vector<std::pair<int, string>> pathVec;

    if (!graphArray[start] || !graphArray[destination]) {
        // std::cout << "Path between \"" << start << "\" and \"" << destination << "\" could not be found." << std::endl;
        return pathVec;
    }

    // Set all values to INT_MAX so they can be relaxed
    for (auto vertix : graphArray)
    {
        auto node = vertix.second;
        while (node) {
            int index = hashFunction(node->pageName);
            pair[index] = node->pageName;
            notVisited.insert(index);
            dijkstras[index].first = INT_MAX;
            dijkstras[index].second = -1;
            node = node->next;
        }
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
    int pathWeight = dijkstras[endLoc].first;
    while (endLoc != -1)
    {
        path.push(endLoc);
        endLoc = dijkstras[endLoc].second;
    }

    if (pair[path.top()] != start)
    {
        // std::cout << "Path between \"" << start << "\" and \"" << destination << "\" could not be found." << std::endl;
        return pathVec;
    }

    // Now print the path
    int loc;
    Node* curr;
    while (!path.empty())
    {
        loc = path.top();
        path.pop();
        curr = graphArray[pair[loc]];
        // std::cout << curr->pageName << std::endl;
        pathVec.push_back(make_pair(0, curr->pageName));

    }
    // std::cout << "Weight of Path: " << pathWeight << std::endl;
    pathVec[0].first = pathWeight;
    return pathVec;
}

void Graph::bellmanFord(string start, string destination) {
    std::unordered_map<string, std::pair<int, string>> distMap;

    if (!graphArray[start] || !graphArray[destination]) {
        std::cout << "Path between \"" << start << "\" and \"" << destination << "\" could not be found." << std::endl;
        return;
    }

    for (auto pair : graphArray) {
        auto node = pair.second;
        while (node) {
            distMap[node->pageName] = std::make_pair(INT_MAX, "");
            node = node->next;
        }
    }


    distMap[start].first = 0;
    distMap[start].second = start;

    for (int i = 0; i < vertices - 1; i++) {
        for (auto u : graphArray) {
            Node* vNode = u.second;
            while (vNode) {
                //Loops through all edges
                if (distMap[u.second->pageName].first + vNode->weight < distMap[vNode->pageName].first) {
                    distMap[vNode->pageName].first = distMap[u.second->pageName].first + vNode->weight;
                    distMap[vNode->pageName].second = u.second->pageName;
                }
                vNode = vNode->next;
            }
        }
    }

    std::stack<std::string> s;
    s.push(destination);

    while (s.top() != start) {
        auto name = distMap[s.top()].second;
        s.push(name);
    }

    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    std::cout << "Weight of Path: " << distMap[destination].first << std::endl;
}

std::vector<std::pair<int, string>> Graph::getBellmanPath(string start, string destination) {
    std::unordered_map<string, std::pair<int, string>> distMap;
    std::vector<std::pair<int, string>> pathVec;

    if (!graphArray[start] || !graphArray[destination]) {
        // std::cout << "Path between \"" << start << "\" and \"" << destination << "\" could not be found." << std::endl;
        return pathVec;
    }

    for (auto pair : graphArray) {
        auto node = pair.second;
        while (node) {
            distMap[node->pageName] = std::make_pair(INT_MAX, "");
            node = node->next;
        }
    }


    distMap[start].first = 0;
    distMap[start].second = start;

    for (int i = 0; i < vertices - 1; i++) {
        for (auto u : graphArray) {
            Node* vNode = u.second;
            while (vNode) {
                //Loops through all edges
                if (distMap[u.second->pageName].first + vNode->weight < distMap[vNode->pageName].first) {
                    distMap[vNode->pageName].first = distMap[u.second->pageName].first + vNode->weight;
                    distMap[vNode->pageName].second = u.second->pageName;
                }
                vNode = vNode->next;
            }
        }
    }

    std::stack<std::string> s;
    s.push(destination);

    while (s.top() != start) {
        auto name = distMap[s.top()].second;
        s.push(name);
    }

    while (!s.empty()) {
        // std::cout << s.top() << std::endl;
        pathVec.push_back(make_pair(0, s.top()));
        s.pop();
    }
    // std::cout << "Weight of Path: " << distMap[destination].first << std::endl;
    pathVec[0].first = distMap[destination].first;
}