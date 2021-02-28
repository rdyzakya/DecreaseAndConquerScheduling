#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__
#include "13519061-Node.hpp"
#include <iostream>
using namespace std;

class Graph {
private:
	vector<Node> nodes;
	int num_node;
public:
	Graph();
	void addNode(Node add_node);
	void deleteNode(string del_nodename);
	~Graph();
	vector<string> noPredecessor();
	bool isAcyclic();
	void topologicalSort(vector<vector<string>> * result, bool * solved);
	void result();
	void show();
};
#endif