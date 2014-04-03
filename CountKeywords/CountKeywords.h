/* Filename:        CountKeywords.h
 * Last Modified:   3 April 2014
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
//#include <algorithm>
#include <set>
#include <regex>
#include <string>
#include <iterator>
#include <sstream>
#include <iomanip>

using namespace std;

class CountKeywords
{
public:
	CountKeywords();
	CountKeywords(string, string);
	void openFile(ifstream&, string&); // utility function to open a file for processing
	void printFoundKeywords(); // utility function to output results to console window
private:
	set<string> sourceKeywords; // set storing keywords
	multiset<string> foundKeywords; // multiset to store any found keywords
	ifstream fileKeywords, fileSearch; // input stream of filenames
	string keyFileIn, searchFileIn; // filenames for keywords and search file, respectively

	void createKeywordSet(); // utility function to create set of keywords from keyFileIn
	void tokenizeSearchFile(); // utility function to tokenize searchFileIn and store matches into foundKeywords
};

#endif