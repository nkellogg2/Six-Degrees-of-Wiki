#include "Graph.h"
#include <string>
#include <iostream>
#include <fstream>
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

void Graph::insert(string name)
{
    // Get original hash value for the page name
    unsigned int location = hashFunction(name, vertices);

    // Find first open spot at or after the initial location
    while (graphArray[location]->pageName.empty())
    {
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
    while (graphArray[loc]->pageName.empty() && loops < 1)
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

Graph::Graph()
{
    vertices = 0;
    sizeFactor = 1.5; // NEVER below 1
    graphArray = new Node*[1];
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
        vertices = (int)(lines * sizeFactor);
        delete[] graphArray;
        graphArray = new Node*[vertices];

        // Read data
        // Line Types:
        // 0 - Name of a Page
        // 1 - List of Links
        // 2 - Spacer
        int lineType = 0;
        while (!input.eof())
        {
            getline(input, line);

            if (lineType == 0)
            {
                insert(line);
            }
            if (lineType == 1)
            {
                
            }

            lineType++;
            lineType = lineType % 3;
        }
    }
    else
    {
        std::cout << "Can't Open " << fileName << std::endl;
    }
}