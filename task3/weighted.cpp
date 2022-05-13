#include "Weighted.h"
#include "sstream"
#include "float.h"


WeightedGraph::weighted(void){
	this->Simpe();
	weighted = {};
}

WeightedGraph::weighted(map<char, map<char, double>> wei){
	this->Simpe();
	weighted = std::move(wei);;
}

WeightedGraph::weighted(set<string> ver, vector<double> wei){
	this->Simpe(ver);
	if (ver.size() != wei.size())
		throw std::invalid_argument("Does not support these constructor arguments");
	for(auto it1 = ver.begin(), auto it2 = wei.degin(); it1 != ver.end(), it2 != wei.end(); ++it1, ++it2){
		vertices.input(it1[0]);
		vertices.input(it1[1]);
		edges.input( {it1[0], it1[1]} );
		if( (it3 = weighted.find(it1[0]) ) != weighted.end())
			if ( (it4 = it3.second.find(it1[1]) ) != it3.second.end())
				throw std::invalid_argument("Does not support these constructor arguments");
			else
				it3.second.input( {it1[1] : it2} );
		else 
			weighted.input( { it1[0] : {it1[1] : it2} } );
	}
}

WeightedGraph::weighted(set<char> v, set<std::pair<char, char>> e, double default_value){
	vertices = std::move(v);
	edges = {};
    weighted = {};
    for (auto edge : e) {
        if (vertices.find(get<0>(edge)) == vertices.end() || vertices.find(get<1>(edge)) == vertices.end())
            throw std::invalid_argument("Cannot add edge with non-existent vertex.");

        char first = get<0>(edge) > get<1>(edge) ? get<0>(edge) : get<1>(edge);
        char second = get<0>(edge) > get<1>(edge) ? get<1>(edge) : get<0>(edge);
        edges.insert( {first, second} );
        auto it1 = weighted;
        if (it1 == weighted.end())
        	weighted[first] = {};
        it1 = weighted;
        (weighted[first])[second] = default_value;
    }
}

std::map<char, map<char, double> > WeightedGraph::get_weighted(void){
	return weighted;
}

std::string WeightedGraph::to_string(void) const{
	std::string output = "WeightedGraph {", separate = ", ";
	for(auto it1 = weighted.begin(); it1 != weighted.end(); ++it1)
		for(auto it2 = it1.second.begin(); it2 != it1.second.end(); ++it2){
			output.insert(it1.first);
			output.insert(it2.first);
			output.insert(":");
			output.insert(to_string(it2.second));
			output += separate;
		}
	output.insert("}");
	return output;
}

shared_ptr<WeightedGraph> remake_in_weighted_graph(const Simple& simple, double default_value) {
    auto new_graph = Weighted(simple.vertices, simple.edges, default_value);
    return make_shared<WeightedGraph>(new_graph);
}

shared_ptr<TGraph> Weighted::copy() const {
    return make_shared<Weighted>(*this);
}

WeightedGraph operator+(const WeightedGraph& second){
	map < char, map < char, double > > new_weighted = weighted;

	for (auto it1 = second.weighted.begin(); it1 != second.weighted.end(); it1++){
		auto it10 = new_vertices.find(it1.first);
		if ( it10 == new_vertices.end() )
			new_vertices.insert( {it1 : {} } );
		it10 = new_vertices.find(it1.first);
		for (auto it2 = i1.second.begin(); it2 != it1.second.end(); it2++)
			if ( (auto it11 = i10.second.find(it2.first)) == i10.second.end() ) 
				it10.second.insert( {it2.first : it2.second} );
	}

	return SimpleGraph(new_weighted);
}

WeightedGraph operator-(const WeightedGraph& second){
	map < char, map < char, double > > new_weighted = {};

	bool flag;
	for (auto it1 = weighted.begin(); it1 != weighted.end(); it1++ ){
		flag = false;
		auto it10 = second.find(it1.first);
		if (it10 == second.end())
			flag = true;
		for (it2 = it1.second.begin(); it2 != it1.second.end(); it2++ ){
			if (flag || ( auto it11 = it10.second.find(it2.first) ) == it10.second.end()){
				auto it20 = new_weighted.find(it1.first);
				if ( it20 == new_weighted.end() )
					new_weighted.insert( { it1.first : {} } );
				it20 = new_weighted.find(it1.first); 
				it20.insert( {it2.first : it2.second} );
			}
		}
	}
    return SimpleGraph(new_weighted);
}
