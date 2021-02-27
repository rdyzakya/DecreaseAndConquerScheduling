#include "Graph.hpp"

Graph::Graph() {
	num_node = 0;
}


void Graph::addNode(Node add_node) {
	nodes.push_back(add_node);
	num_node++;
}

void Graph::deleteNode(string del_nodename) {
	for (int i = 0; i < nodes.size(); ++i)
	{
		if (del_nodename.compare(nodes[i].getName()) == 0)
		{
			nodes.erase(nodes.begin()+i);
			num_node--;
		}
	}
}

Graph::~Graph(){
	nodes.clear();
}

vector<string> Graph::noPredecessor() {
	vector<string> result;
	for (int i = 0; i < num_node; ++i)
	{
		if (nodes[i].getNumPred() == 0)
		{
			result.push_back(nodes[i].getName());
		}
	}
	return result;
}

bool Graph::isAcyclic() {
	return noPredecessor().size() != 0;
}

void Graph::topologicalSort(vector<vector<string>> * result , bool * solved){
	if (isAcyclic() && num_node > 0)
	{
		vector<string> sub_result = noPredecessor(); //nama matkul yg gaada prerequisite
		result->push_back(sub_result);
		for (int i = 0; i < num_node; ++i) //ngilangin matkul yg gaada di prerequisite yang menjadi prerequisite di matkul lain
		{
			for (int j = 0; j < sub_result.size(); ++j)
			{
				nodes[i].delPredNode(sub_result[j]);
			}
		}
		for (int k = 0; k < sub_result.size(); ++k)//delete node dari graph
		{
			deleteNode(sub_result[k]);
		}
		*solved = false;
		topologicalSort(result , solved);
	}else{
		*solved = true;
	}
}

void Graph::result() {
	vector<vector<string>> my_result;
	bool isSolved;
	topologicalSort(&my_result,&isSolved);
	if (!isSolved)
	{
		cout << "Graphnya tidak asiklik!" << endl;
	}else{
		for (int i = 0; i < my_result.size(); ++i)
		{
			cout << "Semester " << i+1 << " : ";
			for (int j = 0; j < my_result[i].size(); ++j)
			{
				if (j != 0)
				{
					cout << ", ";
				}
				cout << my_result[i][j];
			}
			cout << endl;
		}
	}
}

void Graph::show() {
	for (int i = 0; i < num_node; ++i)
	{
		nodes[i].show();
		cout << endl;
	}
}