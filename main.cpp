#include <iostream>
#include <vector>
#include "Graph.h"
#include "SixDegrees.h"
#include "MakeGraph.h"

using namespace GUITesting;

bool isValidNum(string num);
void bfsSearch(Graph* g);
void dijkstras(Graph* g);
void listPages(Graph* g);
void readFiles(Graph* g, std::vector<string>& files);

int main() {
    MakeGraph setupForm;
    setupForm.ShowDialog();
    /*
    SixDegrees form;
    form.ShowDialog();
    */

    Graph* g = new Graph;

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
                break;
            case '4' :
                delete g;
                g = new Graph;
                readFiles(g, fileNames);
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

    if (value < 1)
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
    g->printBFSPath(start, dest);
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
    //g->printDijkstrasPath(start, dest);
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
    // String^ fileNumInput;
    // std::cout << "How many files would you like to use to build this graph?" << std::endl;
    // use txt_numFiles here V
    // fileNumInput = setupForm.txt_numFiles->Text;
    string fileNum;

    getline(std::cin, fileNum);
    std::cout << std::endl;

    while (!isValidNum(fileNum))
    {
        // display "Invalid Number" in gui
        // std::cout << "It seems you didn't enter a valid number, please input a positive number:" << std::endl;
        getline(std::cin, fileNum);
        std::cout << std::endl;
    }

    // remove invalid number msg if present
    // hide "OK" button

    int numFiles = std::stoi(fileNum);

    // show prompt and box 
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
