#ifndef __SCANNERGRAPH_HPP__
#define __SCANNERGRAPH_HPP__
#include "Graph.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class ScannerGraph {
public:
	Graph readTxt(string file_name);
};

#endif