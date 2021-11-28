#include "Graph.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using std::string;

// Copied Hash function from the UnorderedMap Project
unsigned int Graph::hashFunction(string name, unsigned int size)
{
    unsigned int code = 0;
    unsigned int temp;
    for (int i = 0; i < name.length(); i++)
    {
        int val = name[i];
        if (i % 2 == 0)
        {
            temp = (code << 7) ^ val ^ (code >> 3);
        }
        else
        {
            temp = (code << 11) ^ val ^ (code >> 5);
            temp = ~temp;
        }
        code = code ^ temp;
        i++;
    }
    code = code << 1;
    code = code >> 1;
    return code % size;
}

void Graph::insertHead(string name)
{
    // Get original hash value for the page name
    unsigned int location = hashFunction(name, vertices);

    // Find first open spot at or after the initial location
    while (!graphArray[location]->pageName.empty())
    {
        if (graphArray[location]->pageName == name)
        {
            return;
        }
        location++;
        location = location % vertices;
    }

    graphArray[location]->pageName = name;
}

int Graph::find(string name)
{
    // Get original hash value for the page name
    unsigned int location = hashFunction(name, vertices);

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
    vertices = 0;
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

void Graph::inputGraph(string fileName)
{
    // Open the file
    std::ifstream input;
    input.open(fileName);

    // Read how many lines, then divide by three
    // Not super efficient but this will mean no resizing
    string line;
    int lines = 0;
    if (input.is_open())
    {
        while (!input.eof())
        {
            getline(input, line);
            lines++;
        }

        // Close and reopen to actually read data
        input.close();
        input.open(fileName);

        // Set the graph to the correct size and update vertices;
        // Size factor adds extra space to reduce likelihood of collisions
        lines = lines / 3;

        //Sets the number of data points we'll have. When using larger csv file we can change it
        vertices = 100000;
        delete[] graphArray;
        graphArray = new Node*[vertices];
        for (int i = 0; i < vertices; i ++)
        {
            graphArray[i] = new Node;
        }

        // Read data
        // Line Types:
        // 0 - Name of a Page
        // 1 - List of Links
        // 2 - Spacer
        int lineType = 0;
        string page;
        while (!input.eof())
        {
            if (lineType == 0)
            {
                getline(input, line);
                insertHead(line);
                page = line;
            }
            // Help in this section from: https://stackoverflow.com/questions/37957080/can-i-use-2-or-more-delimiters-in-c-function-getline
            if (lineType == 1)
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
                        for (int i = 0; i < l.length(); i++)
                        {
                            if (l[i] == '_')
                                l[i] = ' ';
                        }

                        //Inserts links into array
                        insertHead(l);
                        
                        // To-Do: Don't insert if it is a 'File:...' or other special link such as pronunciation

                        currentNode->next = new Node(l, w);
                        currentNode = currentNode->next;
                        w++;
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
    else
    {
        std::cout << "Sorry, can't open " << fileName << std::endl;
    }
}

void Graph::printEdges(string name)
{
    int index = find(name);

    if (index == -1)
        std::cout << "Sorry, " << name << " could not be found in this graph" << std::endl;
    else
    {
        std::cout << "Links on the page " << name << ":" << std::endl;

        Node* currentNode = graphArray[index];

        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
            std::cout << currentNode->weight << ". " << currentNode->pageName << std::endl;
        }
    }
    std::cout << std::endl;
}