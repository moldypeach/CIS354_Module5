/* Filename:        CountKeywords.h
 * Last Modified:   3 April 2014
 * Author:          Todd Parker
 * Email:           todd.i.parker@maine.edu
 * Course:          CIS354 - Algorithms and Data Structures
 * 
 * CountKeywords.cpp is a 
 */
#ifndef COUNTKEYWORDS_H
#define COUNTKEYWORDS_H
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <regex>
#include <string>

using namespace std;

class CountKeywords
{
public:
	CountKeywords();
	Countkeywords(string, string);
	virtual ~CountKeywords();
	void openFile(ifstream);
private:
	set<string> sourceKeywords;
	multiset<string> foundKeywords;
	ifstream fileKeywords, fileSearch;
	std::regex rx;
}

#endif