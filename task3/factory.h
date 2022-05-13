#ifndef GRAPHS_FACTORY_H
#define GRAPHS_FACTORY_H

#include <string>
#include <map>
#include <utility>
#include <vector>


#include "graph.h"
#include "simple.h"
#include "complete.h"
#include "bipartite.h"
#include "weighted.h"
#include "find_way.h"


using vertices = set<char>;
using edges = set<pair<char, char>>;
using weighted_edges = vector<double>;


class GraphFactory {
    class TImpl;
    std::unique_ptr<TImpl> Impl;
    public:
        GraphFactory();
        // ~GraphFactory();
        std::shared_ptr<TGraph> create(const string&, vertices) const;
        std::shared_ptr<TGraph> create(const string&, vertices, edges) const;
        std::shared_ptr<TGraph> create(const string&, vertices, vertices) const;
        std::shared_ptr<TGraph> create(const string&, vertices, weighted_edges) const;
};



#endif //GRAPHS_FACTORY_H