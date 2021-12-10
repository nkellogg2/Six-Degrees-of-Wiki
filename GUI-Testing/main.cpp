#include <iostream>
#include <vector>
#include <chrono>
#include "Graph.h"
#include "SixDegrees.h"
#include "MakeGraph.h"

using namespace GUITesting;

void cmdLine(Graph* g);
bool isValidNum(string num);
void bfsSearch(Graph* g);
void dijkstras(Graph* g);
void bellmanford(Graph* g);
void listPages(Graph* g);
void readFiles(Graph* g, std::vector<string>& files);

int main() {
    
    MakeGraph setupForm;
    Graph* g = new Graph;
    string mode = "";
    while (mode != "0") {
        std::cout << "Enter 1 for Command Line, 2 for GUI, or 0 to exit: " << std::endl;
        getline(std::cin, mode);
        char m;

        if (!mode.empty()) {
            m = mode[0];
        }
        else {
            m = '3';
        }
        switch (m) {
        case '0':
            break;
        case '1':
            cmdLine(g);
            break;
        case '2':
            setupForm.ShowDialog();
            break;
        default:
            std::cout << "Please choose a valid option." << std::endl;
            break;
        }
    }
    return 0;
}

void cmdLine(Graph* g) {
    std::vector<string> fileNames;

    readFiles(g, fileNames);

    string input = "";

    while (input != "5")
    {
        std::cout << "What would you like to do? Select the number that corresponds with your choice:" << std::endl;
        std::cout << "1. List page links" << std::endl;
        std::cout << "2. Find the shortest path by pages" << std::endl;
        std::cout << "3. Find the shortest path by links" << std::endl;
        std::cout << "4. Insert more data files" << std::endl;
        std::cout << "5. Stop the program" << std::endl;
        getline(std::cin, input);
        std::cout << std::endl;

        char i;
        if (!input.empty())
            i = input[0];
        else
            i = '0';
        switch (i)
        {
        case '1':
            listPages(g);
            break;
        case '2':
            bfsSearch(g);
            break;
        case '3':
            std::cout << "Use Bellman-Ford(0) or Dijkstra's algorithm(1)?" << std::endl;
            getline(std::cin, input);
            if (input == "0") {
                bellmanford(g);
            }
            else if (input == "1") {
                dijkstras(g);
            }
            else {
                std::cout << "Invalid selection!" << std::endl;
            }
            break;
        case '4':
            delete g;
            g = new Graph;
            readFiles(g, fileNames);
            break;
        case '5':
            break;
        default:
            std::cout << "Sorry, your selection was not available." << std::endl;
            std::cout << "Be sure to only enter a number from the given list" << std::endl;
            std::cout << std::endl;
        }
    }
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
    string start;
    std::cout << "Enter the name of the starting page:" << std::endl;
    getline(std::cin, start);
    std::cout << std::endl;
    string dest;
    std::cout << "Enter the name of the destination page:" << std::endl;
    getline(std::cin, dest);
    std::cout << std::endl;
    // start timer
    auto timer = std::chrono::steady_clock::now();
    g->printBFSPath(start, dest);
    // end timer
    auto end = std::chrono::steady_clock::now();
    // display time
    std::cout << std::endl << "Time to perform BFS in seconds: " << std::chrono::duration_cast<std::chrono::seconds>(end - timer).count() << std::endl << std::endl;

}

void dijkstras(Graph* g)
{
    string start;
    std::cout << "Enter the name of the starting page:" << std::endl;
    getline(std::cin, start);
    std::cout << std::endl;
    string dest;
    std::cout << "Enter the name of the destination page:" << std::endl;
    getline(std::cin, dest);
    std::cout << std::endl;
    // start timer
    auto timer = std::chrono::steady_clock::now();
    g->dijkstras(start, dest);
    // end timer
    auto end = std::chrono::steady_clock::now();
    // display time
    std::cout << std::endl << "Time to perform BFS in seconds: " << std::chrono::duration_cast<std::chrono::seconds>(end - timer).count() << std::endl << std::endl;

}

void bellmanford(Graph* g) {
    string start;
    std::cout << "Enter the name of the starting page:" << std::endl;
    getline(std::cin, start);
    std::cout << std::endl;
    string dest;
    std::cout << "Enter the name of the destination page:" << std::endl;
    getline(std::cin, dest);
    std::cout << std::endl;
    // start timer
    auto timer = std::chrono::steady_clock::now();
    g->bellmanFord(start, dest);
    // end timer
    auto end = std::chrono::steady_clock::now();
    // display time
    std::cout << std::endl << "Time to perform BFS in seconds: " << std::chrono::duration_cast<std::chrono::seconds>(end - timer).count() << std::endl << std::endl;

}

void listPages(Graph* g)
{
    string input;
    std::cout << "Enter the name of the page to display their links:" << std::endl;
    getline(std::cin, input);
    g->printEdges(input);
}

void readFiles(Graph* g, std::vector<string>& files)
{
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

    if (stoi(fileNum) == 0)
    {
        files = { "Apple.csv", "GenghisKhan.csv", "JoeBiden.csv", "KungFuPanda.csv",
                    "LeBronJames.csv", "Philosophy1.csv", "Philosophy2.csv", "Philosophy3.csv",
                    "Wikipedia.csv" };
    }

    int numFiles = std::stoi(fileNum);

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