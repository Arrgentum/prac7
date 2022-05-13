#include <map>
#include <stdexcept>
#include "factory.h"
#icnlude "graph.h"

class GraphFactory::TImpl{
private:
	class ICreator {
	public:
		virtual ~ICreator(){}
		virtual shared_ptr<TGraph> create(vertices) = 0;
        virtual shared_ptr<TGraph> create(vertices, edges) = 0;
        virtual shared_ptr<TGraph> create(vertices, vertices) = 0;
        virtual shared_ptr<TGraph> create(vertices, weighted_edges) = 0;
    };

public:
    TImpl() {
        RegisterAll();
    }

	template <class T>
	class Creator : public ICreator {
		public:
        shared_ptr<TGraph> create(vertices v) override {
            if (is_constructible_v<T, vertices>) {
                return make_shared<T>(v);
            }
            return nullptr;
        }

        shared_ptr<TGraph> create(vertices v, edges e) override {
            if  (is_constructible_v<T, vertices, edges>) {
                return make_shared<T>(v, e);
            }
            return nullptr;
        }

        shared_ptr<TGraph> create(vertices v1, vertices v2) override {
            if  (is_constructible_v<T, vertices, vertices>) {
                return make_shared<T>(v1, v2);
            }
            return nullptr;
        }

        shared_ptr<TGraph> create(vertices v, weighted_edges e) override {
            if  (is_constructible_v<T, vertices, weighted_edges>) {
                return make_shared<T>(v, e);
            }
            return nullptr;
        }
    };

    map<string, shared_ptr<ICreator>> registered;

    void registerAll() {
        registered["simple"] = make_shared<Creator<SimpleGraph>>();
        registered["complete"] = make_shared<Creator<CompleteGraph>>();
        registered["bipartite"] = make_shared<Creator<BipartiteGraph>>();
        registered["weighted"] = make_shared<Creator<WeightedGraph>>();
    }
};


shared_ptr<TGraph> GraphFactory::create(const string& type, vertices v) {
    printf("complete");
    if (type == "complete")
        return registered[type]->create(v);
}

shared_ptr<TGraph> GraphFactory::create(const string& type, vertices v, edges e) {
    printf("simple\n");
    if (type == "simple")
        return registered[type]->create(v, e);
}

shared_ptr<TGraph> GraphFactory::create(const string& type, vertices v1, vertices v2) {
    printf("bipartite\n");
    if (type == "bipartite")
        return registered[type]->create(v1, v2);
}

shared_ptr<TGraph> GraphFactory::create(const string& type, vertices v, weighted_edges e) {
    printf("weighted\n");
    if (type == "weighted")
        return registered[type]->create(v, e);
}



int main(int argc, char const *argv[])
{
    GraphFactory Factory;
    vertices left = {'A','B','C','D'};
    vertices right = {'E','F'};
    auto bipartite = Factory.create("bipartite", left, right);
    std::cout << bipartite->to_string() << std::endl;
    return 0;
}