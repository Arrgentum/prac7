#ifndef SIMPLE_GRAPH_H
#define SIMPLE_GRAPH_H
#include "graph.h"
#include <string>
#include <vector>
#include <set>
#include <memory>
#include "iostream"
using namespace std;
class WeightedGraph;

class SimpleGraph: public TGraph{
protected:
    std::set<char> vertices;
    std::set<std::pair<char, char>> edges;

public:
    void simple(set<string> v);
    void simple(void);
    virtual std::string to_string(void) const;
    set<char> get_vertices() const;
    set<pair<char, char>> get_edges() const;
    shared_ptr<WeightedGraph> make_weighted(double default_weight);
    shared_ptr<TGraph> copy() const override;
};

#endif // SIMPLE_GRAPH_H
