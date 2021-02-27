#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

class Node {
private:
	string name;
	vector<string> predecessor;
	int num_pred;
public:
	Node(string name){
		this->name = name;
		this->num_pred = 0;
	}


	void addPredNode(string pred_name){
		predecessor.push_back(pred_name);
		num_pred++;
	}

	void delPredNode(string pred_name){
		predecessor.erase(remove(predecessor.begin(),predecessor.end(),pred_name),predecessor.end());
		num_pred--;
	}

	~Node(){
		predecessor.clear();
	}

};

class Graph {
private:
	vector<Node> nodes;
	int num_node;
public:
	Graph() {
		this->num_node = 0;
	}


	void addNode(Node add_node) {
		nodes.push_back(add_node);
		this->num_node++;;
		
	}

	void deleteNode(int del_nodeindex) {
		nodes.erase(nodes.begin() + del_nodeindex);
		this->num_node--;
	}

	~Graph(){
		nodes.clear();
	}

	vector<int> noPredecessor() {
		vector<int> result;
		for (int i = 0; i < num_node; ++i)
		{
			if (this->nodes.get(i).num_pred == 0)
			{
				result.push_back(i);
			}
		}
		return result;
	}

	bool isAcyclic() {
		return this->noPredecessor.size() != 0;
	}

	bool topologicalSort(vector<vector<string>> * result){
		if (num_node == 0)
		{
			return true;
		}else if (this->isAcyclic())
		{
			vector<string> sub_result;
			vector<int> no_predindex = this->noPredecessor();
			for (int i = 0; i < no_predindex.size(); ++i) //matkul per semesternya
			{
				int index = no_predindex.get(i);
				sub_result.push_back(nodes.get(index).name);
			}
			result->push_back(sub_result);
			for (int j = 0; j < num_node; ++j)//hapus dari list predecessor di node lain
			{
				for (int k = 0; k < no_predindex.size(); ++k)//satu-satu matkulnya
				{
					int another_index = no_predindex.get(k);
					string no_predname = this->nodes.get(another_index).name;
					if (j != another_index)
					{
						this->nodes.get(j).delPredNode(no_predname);
					}
				}
			}
			for (int l = 0; l < no_predindex.size(); ++l)//delete node dari graph
			{
				this->deleteNode(no_predindex.get(l));
			}
			topologicalSort(result);
		}
		return false;
	}

	void result() {
		vector<vector<string>> my_result;
		bool isSolved = topologicalSort(&my_result);
		if (!isSolved)
		{
			cout << "Graphnya tidak asiklik!" << endl;
		}else{
			for (int i = 0; i < my_result.size(); ++i)
			{
				cout << "Semester" << i+1 << " : ";
				for (int j = 0; j < my_result.get(i).size(); ++j)
				{
					if (j != 0)
					{
						cout << ", ";
					}
					cout << my_result.get(i).get(j);
				}
				cout << endl;
			}
		}
	}

};

class Scanner {
public:
	Graph readTxt(string file_name){
		Graph my_graph;
		ifstream file(file_name + ".txt");
		string line;
		while(getline(file,line)){
			line.erase(remove(line.begin(),line.end(),' '), line.end());
			line.erase(remove(line.begin(),line.end(),'.'), line.end());
			stringstream my_line(line);
			string node_name;
			vector<string> node_line;
			while(getline(my_line,node_name, ',')){
				node_line.push_back(node_name);
			}
			Node main_node(node_line.get(0));
			for (int i = 1; i < node_line.size(); ++i)
			{
				main_node.addPredNode(node_line.get(i));
			}
			my_graph.addNode(main_node);
		}
		file.close();
	}
};