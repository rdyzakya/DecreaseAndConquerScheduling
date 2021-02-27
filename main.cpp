#include "ScannerGraph.hpp"
#include "Graph.hpp"
#include <iostream>
using namespace std;

int main() {
	string file_name;
	cout << "Masukkan nama file: ";
	cin >> file_name;
	ScannerGraph my_scanner;
	Graph my_graph = my_scanner.readTxt(file_name);
	my_graph.result();
	return 0;
}