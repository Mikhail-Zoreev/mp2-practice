#include <iostream>
#include <time.h>
#include <random>

#include "TPyramidSort.h"
#include "TKruskalsAlgorithm.h"
#include "TDijkstrasAlgorithm.h"
#include "Generator.h"

int main()
{
    int* array = new int[100];
    srand(time(0));
    for (int i = 0; i < 100; i++)
    {
        array[i] = rand() % 500;
    }

    TPyramidSort::sort(100, array);
    for (int i = 0; i < 100; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

    TGraph graph(3);
    std::cin >> graph;
    std::cout << graph;

    if (graph.connected())
    {
        std::cout << "Connected" << std::endl;
    }
    else
    {
        std::cout << "Not connected" << std::endl;
        system("pause");
        return 0;
    }

    std::cout << TKruskalsAlgorithm::findTree(Generator::getRandomConnectedGraph(10)) << std::endl;
    std::cout << TDijkstrasAlgorithm::findTree(Generator::getRandomConnectedGraph(10), 0);
    system("pause");
}