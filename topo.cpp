#include <fstream>
#include <string>
#include <vector>

class Node {
private:
	string name;
	vector<string> successor;
	vector<string> predecessor;
public:
	Node(string name){
		this->name = name;
	}

	void addSuccNode(string succ_name){
		successor.push_back(succ_name);
	}

	void addPredNode(string pred_name){
		predecessor.push_back(pred_name);
	}

	void delSuccNode(string succ_name){
		successor.erase(remove(successor.begin(),successor.end(),succ_name),successor.end());
	}

	void delPredNode(string pred_name){
		predecessor.erase(remove(predecessor.begin(),predecessor.end(),pred_name),predecessor.end());
	}

	~Node(){
		successor.clear()
		predecessor.clear();
	}

};

class Graph {
private:
	vector<Node> nodes;
	bool ** adjacency;
	int num_node;
public:
	Graph() {
		this->adjacency = new bool[0][0];
		this->num_node = 0;
	}

	void initializeAdjacency() {
		for (int i = 0; i < num_node; ++i)
		{
			for (int j = 0; j < num_node; ++j)
			{
				adjacency[i][j] = false;
			}
		}
	}

	void addNode(Node add_node) {
		nodes.push_back(add_node);
		this->num_node++;
		delete[] this->adjacency;
		this->adjacency = new bool[num_node][num_node];
		this->initializeAdjacency();
		
	}

	void deleteNode(Node del_node) {
		nodes.erase(remove(nodes.begin(),nodes.end(),del_node),nodes.end());
		delete[] this->adjacency;
		this->num_node--;
		this->adjacency = new bool[num_node][num_node];
		this->initializeAdjacency();
	}

	~Graph(){
		delete[] adjacency;
		nodes.clear();
	}

	void renderAdjacency() {

	}
};