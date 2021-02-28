#ifndef __SCANNERGRAPH_HPP__
#define __SCANNERGRAPH_HPP__
#include "13519061-Graph.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unistd.h>

using namespace std;

class ScannerGraph {
public:
	Graph readTxt(string file_name);
};

#endif