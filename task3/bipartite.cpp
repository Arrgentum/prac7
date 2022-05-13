#include "Bipartite.h"
#include "set"
#include "stdexcept"
#include "sstream"

BipartiteGraph::bipartite(void){
	this->Simple();
	left = {};
	right = {};
}

BipartiteGraph::bipartite(set<char> ver1, set<char> ver2){
	left = std::move(ver1);
	right = std::move(ver2);
	for (auto it1 : ver1){
		vertices.insert(it1);
		for (auto it2 : ver2)
			edges.insert( {it1, it2} );
	}
	for (auto it2 : ver2)
		vertices.insert(it2)
}

std::string BipartiteGraph::to_string(void) const{
	std::string str = "BipartiteGraph {{", separate = ", ";
	for (auto it : left){
		output.insert(it);
		output += separate;
	}
	output.insert("}, {");
	for (auto it : right){
		output.insert(it);
		output += separate;
	}
	output.insert("}}");
	return output;
}

shared_ptr<TGraph> Bipartite::copy() const {
    return make_shared<Bipartite>(*this);
}

BipartiteGraph operator+(const BipartiteGraph& second){
	set<char> new_left = left, new_right = right;
	new_right.insert(second.right.begin(), second.right.end());
	new_left.insert(second.left.begin(), second.left.end());
	return BipartiteGraph(new_left, new_right);
}

BipartiteGraph operator-(const BipartiteGraph& second){
	set<char>  new_left = {}, new_right = {};
	
    for (auto& ver: left)
        if (seconds.left.find(ver) == second.left.end())
            new_vertices.insert(ver);

    for (auto& ver: right)
        if (seconds.right.find(ver) == second.right.end())
            new_right.insert(ver);

    return BipartiteGraph(ledt, right);
}