#include "13519061-Graph.hpp"

//constructor
Graph::Graph() {
	num_node = 0;
}

//menambah node beserta atributnya
void Graph::addNode(Node add_node) {
	nodes.push_back(add_node);
	num_node++;
}

//menghapus node beserta atributnya
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

//destructor
Graph::~Graph(){
	nodes.clear();
}

//mengembalikan list nama node yang tidak memiliki predecessor
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

//mengembalikan keadaan graf asiklik atau siklik
bool Graph::isAcyclic() {
	return noPredecessor().size() != 0;
}

//pemilihan matkul dengan topological sort
void Graph::topologicalSort(vector<vector<string>> * result , bool * solved){
	if (isAcyclic() && num_node > 0)
	{
		vector<string> sub_result = noPredecessor(); //nama node yang tidak memiliki predecessor atau matkul yang tidak memiliki prerequisite
		result->push_back(sub_result);
		for (int i = 0; i < num_node; ++i) //menghilangkan nama node pada list di atas untuk setiap node yang memiliki predecessor dengan nama node terkait
		{
			for (int j = 0; j < sub_result.size(); ++j)
			{
				nodes[i].delPredNode(sub_result[j]);
			}
		}
		for (int k = 0; k < sub_result.size(); ++k)//delete node dari graph, ini bagian decreasenya
		{
			deleteNode(sub_result[k]);
		}
		topologicalSort(result , solved);//rekursi
	}else if (!isAcyclic() && num_node > 0){//jika graph bukan merupakan DAG
		*solved = false;
	}
	else{//jika sorting telah selesai dilaksanakan
		*solved = true;
	}
}

//output hasil dari topological sort
void Graph::result() {
	vector<vector<string>> my_result;
	bool isSolved;
	topologicalSort(&my_result,&isSolved);
	if (!isSolved)
	{
		cout << "Rencana matakuliah tidak dapat dibuat (Graf matakuliah bukan berupa DAG)!" << endl;
	}else{
		cout << "Hasil penjadwalan matakuliah :" << endl;
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

//digunakan untuk debugging
void Graph::show() {
	for (int i = 0; i < num_node; ++i)
	{
		nodes[i].show();
		cout << endl;
	}
}