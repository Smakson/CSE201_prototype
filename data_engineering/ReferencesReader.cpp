#include "ReferencesReader.h"
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <sys/stat.h>
#include <sys/types.h>
#include <direct.h>
using namespace std;

ReferencesReader::ReferencesReader(string name) {
	this->filename = name;
	this->delim = "\t";
}

void ReferencesReader::MakeMatrix() {
	/*First attempt at storing a Matrix. The idea is to construct a directory in the form of a tree structure.
	Every row is stored in a file row.txt. The path to the file is obtained by first padding
	the row number with zeroes on the left, cutting it up into  substrings of length three, then appending them,
	for example, to store the 00123184945'th row, we would create the file 001/231/849/45.txt */
	ifstream file(filename);
	string line;
	while (getline(file, line)) {
		vector<string> vec;
		boost::algorithm::split(vec, line, boost::is_any_of(this->delim));
		string id = vec[0];
		string ref = vec[1];
		while (id.length() < 11) {
			id.insert(0, 1, '0');
		}
		string id1 = id.substr(0, 3);
		string id2 = id1 + "/" + id.substr(3, 3);
		string id3 = id2 + "/" + id.substr(6, 3);
		string id4 = id3 + "/" + id.substr(9, 2) + ".txt";

		const char * path1 = id1.c_str();
		const char * path2 = id2.c_str();
		const char * path3 = id3.c_str();
		const char * filepath = id4.c_str();

		const int dir_er1 = _mkdir(path1);
		const int dir_er2 = _mkdir(path2);
		const int dir_er3 = _mkdir(path3);
		
		ofstream output;
		output.open(filepath, ios_base::app);
		output << ref + ",";
		output.close();
	}
	file.close();
}



