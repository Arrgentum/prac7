#ifndef BIPARTITEGRAPHS_H
#define BIPARTITEGRAPHS_H
#include "simple.h"


class Bipartite:public SimpleGraph{
private:
	std::set<char> left;
	std::set<char> right;
public:
	void bpartite(void);
	void bpartite(set<char> ver1, set<char> ver2);
	std::string to_string(void) const;
	shared_ptr<TGraph> copy() const override;
};


#endif //BIPARTITEGRAPHS_H