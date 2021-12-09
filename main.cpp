#include <iostream>
#include <vector>
#include <chrono>
#include "Graph.h"

bool isValidNum(string num);
void bfsSearch(Graph* g);
void dijkstras(Graph* g);
void bellmanford(Graph* g);
void listPages(Graph* g);
void readFiles(Graph* g);
std::pair<std::string, std::string> getStartStop();

int main() {
    Graph* g = new Graph;

    readFiles(g);

    string input = "";

    while (input != "5")
    {
        std::cout << "What would you like to do? Select the number that corresponds with your choice:" << std::endl;
        std::cout << "1. List page links" << std::endl;
        std::cout << "2. Find the shortest path by pages" << std::endl;
        std::cout << "3. Find the shortest path by links" << std::endl;
        std::cout << "4. Rebuild graph with new files" << std::endl;
        std::cout << "5. Stop the program" << std::endl;
        getline(std::cin, input);
        std::cout << std::endl;

        char i;
        if (!input.empty())
            i= input[0];
        else
            i = '0';
        switch (i)
        {
            case '1' :
                listPages(g);
                break;
            case '2' :
                bfsSearch(g);
                break;
            case '3' :
                dijkstras(g);
                bellmanford(g);
                break;
            case '4' :
                delete g;
                g = new Graph;
                readFiles(g);
                break;
            case '5' :
                break;
            default:
                std::cout << "Sorry, your selection was not available." << std::endl;
                std::cout << "Be sure to only enter a number from the given list" << std::endl;
                std::cout << std::endl;
        }
    }
    return 0;
}

bool isValidNum(string num)
{
    for (int i = 0; i < num.length(); i++)
    {
        if (!std::isdigit(num[i]))
        {
            return false;
        }
    }

    int value = std::stoi(num);

    if (value < 0)
        return false;

    return true;
}

void bfsSearch(Graph* g)
{
    auto pair = getStartStop();

    // Start timer
    auto timer = std::chrono::steady_clock::now();

    g->printBFSPath(pair.first, pair.second);

    // End timer
    auto end = std::chrono::steady_clock::now();

    // Display time
    std::cout << std::endl;
    std::cout << "Time perform BFS in seconds: "
    << std::chrono::duration_cast<std::chrono::seconds>(end - timer).count() << std::endl;
}

void dijkstras(Graph* g)
{
    auto pair = getStartStop();
    
    // Start timer
    auto timer = std::chrono::steady_clock::now();
    
    g->dijkstras(pair.first, pair.second);

    // End timer
    auto end = std::chrono::steady_clock::now();

    // Display time
    std::cout << std::endl;
    std::cout << "Time perform Dijkstra's Algorithm in seconds: "
    << std::chrono::duration_cast<std::chrono::seconds>(end - timer).count() << std::endl;
}

void bellmanford(Graph* g) {
    auto pair = getStartStop();

    // Start timer
    auto timer = std::chrono::steady_clock::now();

    g->bellmanFord(pair.first, pair.second);

    // End timer
    auto end = std::chrono::steady_clock::now();

    // Display time
    std::cout << std::endl;
    std::cout << "Time perform Bellman-Ford Algorithm in seconds: "
    << std::chrono::duration_cast<std::chrono::seconds>(end - timer).count() << std::endl;
}

void listPages(Graph* g)
{
    string input;
    std::cout << "Enter the name of the page to display their links:" << std::endl;
    getline(std::cin, input);
    g->printEdges(input);
}

void readFiles(Graph* g)
{
    std::vector<string> files;
    string fileNum;
    std::cout << "How many files would you like to use to build this graph? (Enter 0 to use general data)" << std::endl;
    getline(std::cin, fileNum);
    std::cout << std::endl;

    while (!isValidNum(fileNum))
    {
        std::cout << "It seems you didn't enter a valid number, please input a positive number:" << std::endl;
        getline(std::cin, fileNum);
        std::cout << std::endl;
    }

    int numFiles = std::stoi(fileNum);

    if (stoi(fileNum) == 0)
    {
        files = {"Data/Apple.csv", "Data/GenghisKhan.csv", "Data/JoeBiden.csv", "Data/KungFuPanda.csv",
                    "Data/LeBronJames.csv", "Data/Philosophy1.csv", "Data/Philosophy2.csv", "Data/Philosophy3.csv",
                    "Data/Wikipedia.csv"};
    }

    for (int i = 0; i < numFiles; i++)
    {
        string fileName;
        std::cout << "Enter the name of the file you would like to use: " << std::endl;
        getline(std::cin, fileName);
        std::cout << std::endl;
        files.push_back(fileName);
    }

    g->inputGraph(files);
}

std::pair<std::string, std::string> getStartStop() {
    string start;
    std::cout << "Enter the name of the starting page:" << std::endl;
    getline(std::cin, start);
    std::cout << std::endl;
    string dest;
    std::cout << "Enter the name of the destination page:" << std::endl;
    getline(std::cin, dest);
    std::cout << std::endl;
    return std::make_pair(start, dest);
}