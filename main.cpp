#include <iostream>
#include "Graph.h"

int main() {
    Graph g;

    string fileName;
    std::cout << "Enter the name of the file you would like to use: " << std::endl;
    getline(std::cin, fileName);

    g.inputGraph(fileName);

    string input = "";

    while (input != "STOP")
    {
        std::cout << "Enter the name of the page to display their links, or enter \"STOP\" to end the program: " << std::endl;
        getline(std::cin, input);
        g.printEdges(input);
    }
    return 0;
}
