#include <iostream>
#include <vector>
#include "Graph.h"

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

int main() {
    Graph g;

    string fileNum;
    std::cout << "How many files would you like to use to build this graph?" << std::endl;
    getline(std::cin, fileNum);
    std::cout << std::endl;

    while (!isValidNum(fileNum))
    {
        std::cout << "It seems you didn't enter a valid number, please input a positive number:" << std::endl;
        getline(std::cin, fileNum);
        std::cout << std::endl;
    }

    int numFiles = std::stoi(fileNum);

    std::vector<string> fileNames;

    for (int i = 0; i < numFiles; i++)
    {
        string fileName;
        std::cout << "Enter the name of the file you would like to use: " << std::endl;
        getline(std::cin, fileName);
        std::cout << std::endl;
        fileNames.push_back(fileName);
    }

    g.inputGraph(fileNames);

    string input = "";

    while (input != "STOP")
    {
        std::cout << "Enter the name of the page to display their links, or enter \"STOP\" to end the program: " << std::endl;
        getline(std::cin, input);
        if (input != "STOP")
            g.printEdges(input);
    }
    return 0;
}
