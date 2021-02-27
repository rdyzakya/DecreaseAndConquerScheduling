#include "Node.hpp"

Node::Node(string name){
		this->name = name;
		this->num_pred = 0;
	}


void Node::addPredNode(string pred_name){
	predecessor.push_back(pred_name);
	num_pred++;
}

void Node::delPredNode(string pred_name){
	predecessor.erase(remove(predecessor.begin(),predecessor.end(),pred_name),predecessor.end());
	num_pred = predecessor.size();
}

Node::~Node(){
	predecessor.clear();
}

void Node::show() {
	cout << this->name << endl << "Predesesor: " << endl;
	for (int i = 0; i < num_pred; ++i)
	{
		cout << predecessor[i] << endl;
	}
}

string Node::getName() {
	return name;
}

int Node::getNumPred() {
	return num_pred;
}