#ifndef WEIGHTED_GRAPHS_H
#define WEIGHTED_GRAPHS_H

#include "simple.h"

class WeightedGraph: public SimpleGraph{
private:
	std::map<char, map<char, double>> weighted;
public:
	void weighted(void);
	void weighted(map<char, map<char, double>> wei);
	void weighted(set<string> ver, vector<double> wei);
	void weighted(set<char> v, set<std::pair<char, char>> e, double default_value);
	std::map<char, map<char, double> > WeightedGraph::get_weighted(void);
	std::string to_string(void) const;
	shared_ptr<WeightedGraph> remake_in_weighted_graph(const Simple& simple, double default_value);
	shared_ptr<TGraph> copy() const override;
};

#endif //WEIGHTED_GRAPHS_H