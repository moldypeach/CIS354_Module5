/* Filename:        CountKeywords.h
 * Last Modified:   7 April 2014
 * Author:          Todd Parker
 * Email:           todd.i.parker@maine.edu
 * Course:          CIS354 - Algorithms and Data Structures
 * 
 * CountKeywords.h is the definition code for the processing and output of files for detection
 * of passed keywords (via text files). The default constructor makes use of predefined source
 * documents for the purposes of testing and debugging, and the overloaded constructor takes
 * two strings representing filenames; which allows a user to specify their own documents cont-
 * aining keywords and a source to search for them in. The four functions of CountKeywords do
 * not return any values, and are self-descriptive as to what their purposes are.
 */
#ifndef COUNTKEYWORDS_H
#define COUNTKEYWORDS_H
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <regex>
#include <string>
#include <iterator>
#include <sstream>
#include <iomanip>
#include <numeric>

using namespace std;

class CountKeywords
{
public:
	CountKeywords();
	CountKeywords(string&, string&);
	void printFoundKeywords(); // output results to console window
private:
	set<string> sourceKeywords; // set storing keywords
	map<string, int> foundKeywords; // map to store any found keywords
	ifstream fileKeywords, fileSearch; // input stream of filenames
	string keyFileIn, searchFileIn; // filenames for keywords and search file, respectively
	void openFile(ifstream&, string&); // open a file for processing
	void createKeywordSet(); // create set of keywords from keyFileIn
	void tokenizeSearchFile(); // tokenize searchFileIn and store matches into foundKeywords
	struct sumMap
	{
		int operator()(int total, const std::pair<string, int>& mapElement)
		{
			return total + mapElement.second;
		}
	}; // end sumMap struct
};

#endif