#ifndef __NODE_HPP__
#define __NODE_HPP__
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Node {
private:
	string name;
	vector<string> predecessor;
	int num_pred;
public:
	Node(string name);
	~Node();
	string getName();
	int getNumPred();
	void addPredNode(string pred_name);
	void delPredNode(string pred_name);
	void show();
};

#endif