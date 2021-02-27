#include "ScannerGraph.hpp"

Graph ScannerGraph::readTxt(string file_name){
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
		Node main_node(node_line[0]);
		for (int i = 1; i < node_line.size(); ++i)
		{
			main_node.addPredNode(node_line[i]);
		}
		my_graph.addNode(main_node);
	}
	file.close();
	return my_graph;
}