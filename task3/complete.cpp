#include <sstream>

#include "complete.h"

CompleteGraph::complete(void){
	this->Simple();
}

CompleteGraph::complete(set<char> a){
	vertices = a;
	edges = {};
	for (auto it1 : vertices)
		for (auto it2 : vertices)
			if (it1 != it2){
				char first = vert1 > vert2 ? vert1 : vert2;
                char second = vert1 > vert2 ? vert2 : vert1;
				edges.insert({it1, it2});
			}
}

std::string CompleteGraph::to_string(void) const {
	std::string output = "CompleteGraph {", separate = ", ";
	for (auto it : edges){
		output.insert(it.first);
		output.insert(it.second);
		output += separate;
	}
	output.insert("}");
	return output;
}

shared_ptr<TGraph> Complete::copy() const {
    return make_shared<Complete>(*this);
}

CompleteGraph operator+(const	CompleteGraph& second){
	set<char> new_vertices = vertices;
	new_vertices.insert(second.vertices.begin(), second.vertices.end());
	return CompleteGraph(new_vertices, new_edges);
}

CompleteGraph operator-(const CompleteGraph& second){
	set<char> new_vertices = {};
	
    for (auto& ver: vertices)
        if (seconds.vertices.find(ver) == second.vertices.end())
            new_vertices.insert(ver);

    return CompleteGraph(new_ertices);
}