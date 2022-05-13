//
// Created by alexey on 17.12.2021.
//

#include <factory.h>
#include "factory.h"
#include "graph.h"
#include "simple.h"
#include "complete.h"
#include "bipartite.h"
#include "weighted.h"

using namespace std;


int main(int argc, char const *argv[])
{
    GraphFactory Factory;
    vertices left = {'A','B','C','D'};
    vertices right = {'E','F'};
    auto bipartite = Factory.create("bipartite", left, right);
    std::cout << bipartite->to_string() << std::endl;
    return 0;
}