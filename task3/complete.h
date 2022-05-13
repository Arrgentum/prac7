#ifndef COMPLETE_GRAPHS_H
#define COMPLETE_GRAPHS_H
#include "simple.h"


class CompleteGraph:public SimpleGraph{
	void complete(void);
	void complete(set<char> a);
	std::string to_string(void) const;
	shared_ptr<TGraph> copy() const override;
};


#endif //COMPLETE_GRAPHS_H