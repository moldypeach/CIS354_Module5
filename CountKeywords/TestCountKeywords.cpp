/* Filename:        TestCountKeywords.cpp
 * Last Modified:   2 April 2014
 * Author:          Todd Parker
 * Email:           todd.i.parker@maine.edu
 * Course:          CIS354 - Algorithms and Data Structures
 * 
 * TestCountKeywords.cpp is a 
 */
#include <iostream>
#include <fstream> // for file operations
#include <iterator>
#include <algorithm>
#include <set>
#include <regex>
#include <sstream>
#include <string>
#include <regex>
#include <stdexcept>
#include "SignatureBlock.h"

using namespace std;

int main()
{
	SignatureBlock::printHeader();

	cout << "This program loads C++ keywords and MSDN extensions from a file in the program directory,"
			 "and then prompts the user to specify a source file with which to search for said keywords.\n" << endl;

	ifstream keywordsFile("c++_Keywords_And_MicrosoftExtensions.txt");

	if( keywordsFile.fail() )
	{
		cout << "\"c++_Keywords_And_MicrosoftExtensions.txt\" was not found in program directory\n" << endl;
	}
	else
	{
		//std::regex rx ("[^_[:alpha:]]");
		std::regex rx ("[_\\s<]");
		set<string> keywordSet; // set of keywords
		multiset<string> foundKeyword; // set of keywords found in searchFile
		istream_iterator<string> keywordsFileIterator(keywordsFile); // input stream iterator for keywordsFile

		// Insert each line of keywordsFile into keywordSet. These are the c++ keyword tokens
		while( !keywordsFile.eof() )
		{
			keywordSet.insert( *keywordsFileIterator );
			keywordsFileIterator++;
		} // end while !keywordsFile.eof()
		keywordsFile.close(); // close keywordsFile - keywords stored in keywordSet

		cout << "\nPlease specify a file to search for c++ keywords:\n>";
		string searchFileName;
		cin >> searchFileName;
		cout << "\n\n" << endl; // Insert newlines for readability
		ifstream searchFile( searchFileName );
		
		// Outputs the user-specified source file line-by-line
		//string temp;
		//while ( !searchFile.eof() )
		//{
		//	getline(searchFile, temp);
		//	cout << temp << endl;
		//}

		string tempLine; // Store current line from searchFile
		string tempKeyword; // Store found keyword
		int pos = 0;

		string test = " ";

		set<string>::iterator iter; // string iterator for keywordSet
		//<string>::iterator tempLineIterator;
		// iterate through keywordSet
		for(iter=keywordSet.begin(); iter!=keywordSet.end();++iter)
		{
			//cout << (*iter) << "(" << (*iter).length() << ")" << endl;
			while( !searchFile.eof() )
			{
				getline(searchFile, tempLine);
				pos = tempLine.find( (*iter) );
				while( pos != string::npos )
				{
					if( pos > 0) // if substring match isn't at the first position of the current line
						test = tempLine.at(pos - 1); // retrieve the character immediately before keyword match
					if( std::regex_match( test, rx) ) // if the "match" has an alphanumeric character before or after it, it is not a keyword
					{
						tempKeyword = tempLine.substr( pos, (*iter).length() );
						cout << tempKeyword << endl;
						foundKeyword.insert( tempKeyword );
						pos = tempLine.find( (*iter), pos + 1);
					}
					else
					{
						// do nothing
					}

				}
			}
			searchFile.clear(); // remove eof() flag from searchFile
			searchFile.seekg(0, ios::beg); // return iterator to beginning of searchFile
		}
	cout << foundKeyword.size() << endl;
	} // end else "keywordsFile not found"

	getchar();
	getchar();
	return 0;
} // End main()