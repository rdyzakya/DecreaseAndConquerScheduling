#include "13519061-Node.hpp"

//constructor
Node::Node(string name){
		this->name = name;
		this->num_pred = 0;
	}

//menambah node predecessor berupa namanya saja
void Node::addPredNode(string pred_name){
	predecessor.push_back(pred_name);
	num_pred++;
}

//menghapus node predecessor berupa namanya saja
void Node::delPredNode(string pred_name){
	predecessor.erase(remove(predecessor.begin(),predecessor.end(),pred_name),predecessor.end());
	num_pred = predecessor.size();
}

//destructor
Node::~Node(){
	predecessor.clear();
}

//dibuat untuk debugging
void Node::show() {
	cout << this->name << endl << "Predesesor: " << endl;
	for (int i = 0; i < num_pred; ++i)
	{
		cout << predecessor[i] << endl;
	}
}

//getter untuk nama node
string Node::getName() {
	return name;
}

//getter untuk jumlah predecessor dari node
int Node::getNumPred() {
	return num_pred;
}