#include "find_way.h"

void check_way(std::set<std::map<char, std::pair<double, vector<pair<char,char>>>>> &vertices, std::map<char, map<char, double>> &weighted, char start, int len)
{
	auto it_for_star_char = weighted.find(start);
	for(auto it : it_for_start_char.second)
		for(auto it_for_all : vertices)
			if (it.first == it_for_all.first && ( (it_for_all.second == -1) || (it_for_all.second.first > it.second + len) ) ){
				it_for_all.second.first = it.second + len;
				auto it_for_best_way = vertices.find(start);
				it_for_all.second.second = std::move(it_for_best_way.second.second);
				it_for_all.second.second.inserf( {start, it.first} );
				check_way(vertices, weighted, it2.first, it2.second);
			}
}


pair<double, vector<pair<char,char>>> find_way(WeightedGraph &graph, char start, char finish)
{
	auto ver = graph.get_vertices();
	auto weighted = graph.get_weighted();
	std::set<std::map<char, std::pair<double, vector<pair<char,char>>>>> vertices;
	for(it1 : ver)
		if (it1 != start) vertices.inserf( {it1, -1, {} } );
		else vertices.insert( {it1: { 0, {} } } );

	void check_way(vertices, weighted, start, 0);
	auto it = vertices.find(finish);
	return it;
}