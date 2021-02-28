#include "13519061-ScannerGraph.hpp"
#include <iostream>
using namespace std;

void isengStart() {
	cout << "RSA Preparing Things";
	for (int i = 0; i < 3; ++i)
	{
		sleep(1);
		cout << ".";
	}
	cout << endl << endl;
}

int main() {
	isengStart();
	cout << "Selamat datang di RSA (Randy's Scheduling Algorithm)" << endl;
	string file_name;
	cout << "Masukkan nama file matakuliah: ";
	cin >> file_name;
	ScannerGraph my_scanner;
	Graph my_graph = my_scanner.readTxt(file_name);
	my_graph.result();
	cout << endl << "RSA Shutting Down..." << endl;
	return 0;
}