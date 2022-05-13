#ifndef FINDWAY_H
#define FINDWAY_H

using namespace std;

void check_way(std::set<std::map<char, std::pair<double, vector<pair<char,char>>>>> &vertices, std::map<char, map<char, double>> &weighted, char start, int len);

pair<double, vector<pair<char,char>>> find_way(WeightedGraph &graph, char start, char finish);

#endif // FINDWAY_H
