#ifndef TGRAPH_H
#define TGRAPH_H

#include <string>
#include <vector>
#include <memory>
#include "set"
using namespace std;
class WeightedGraph;

class TGraph {
public:
    virtual std::string to_string() const = 0;
    virtual std::set<char> get_vertices() const = 0;
    virtual std::set<std::pair<char, char>> get_edges() const = 0;
    virtual shared_ptr<WeightedGraph> as_weighted(double) = 0;
    virtual vector<char> shortest_path(char, char) = 0;
    virtual shared_ptr<TGraph> copy() const = 0;
};

#endif // TGRAPH_H