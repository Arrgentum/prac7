#include <utility>
#include <stdexcept>

#include "simple.h"
#include "sstream"

SimpleGraph::simple(set<string> v){
	for(auto it : v){
		if (vertices.find(it[0]) == vertices.end())
			vertices.insert(it[0]);
		if (vertices.find(it[1]) == vertices.end())
			vertices.insert(it[1]);
		if (edges.find(std::pair<char,char>) == edges.end())
			edges.insert( {it[0], it[1]}); 
	}	
}

SimpleGraph::simple(void){
	edges = {};
	vertices = {};
}

std::string SimpleGraph::to_string(void) const{
	std::string output = "SimpleGraph {", separate = ", ";
	for (auto it : vertices){
		output.insert(it);
		output += separate;
	}
	output.insert("}");
	return output;
}	

set<char> SimpleGraph::get_vertices() const {
    return vertices;
}

set<pair<char, char>> SimpleGraph::get_edges() const {
    return edges;
}

shared_ptr<WeightedGraph> SimpleGraph::make_weighted(double default_weight) {
     return remake_in_weighted_graph(*this, default_weight);
}

shared_ptr<TGraph> Simple::copy() const {
    return make_shared<Simple>(*this);
}

SimpleGraph operator+(const SimpleGraph& second){
	set<pair<char,char>> new_edges = edges;
	new_edges.insert(second.edges.begin(), second.edges.end());
	return SimpleGraph(new_edges);
}

SimpleGraph operator-(const SimpleGraph& second){
	set<pair<char,char>> new_edges = {};

    for (auto& edge: edges)
        if (new_vertices.find(edge.first) != new_vertices.end() && new_vertices.find(edge.second) != new_vertices.end() && other.edges.find(edge) == other.edges.end())
           new_edges.insert(edge);
    return SimpleGraph(new_edges);
}

/*
std::unique_ptr<SimpleGraph> operator+(const SimpleGraph& second){
	set<pair<char,char>> new_edges = edges;
	new_edges.insert(second.edges.begin(), second.edges.end());
	return SimpleGraph(new_edges);
}

std::unique_ptr<SimpleGraph> operator-(const SimpleGraph& second){
	set<pair<char,char>> new_edges = {};

    for (auto& edge: edges)
        if (new_vertices.find(edge.first) != new_vertices.end() && new_vertices.find(edge.second) != new_vertices.end() && other.edges.find(edge) == other.edges.end())
           new_edges.insert(edge);
    return SimpleGraph(new_edges);
}
*/
