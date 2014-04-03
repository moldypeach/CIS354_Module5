/* Filename:        CountKeywords.cpp
 * Last Modified:   3 April 2014
 * Author:          Todd Parker
 * Email:           todd.i.parker@maine.edu
 * Course:          CIS354 - Algorithms and Data Structures
 * 
 * CountKeywords.cpp is the implementation of CountKeywords.h. The two functions of note are
 * openFile(ifstream&, string&) and tokenizeSearchFile(). openFile() receives an ifstream and
 * a filename, and, will prompt a user until a valid file is provided. tokenizeSearchFile()
 * receives takes the document possessing keywords to search for, then uses an iterator to
 * walk through the ifstream. Because some keywords have adjacent characters that are not in
 * of themselves keywords (e.g. the '<' and '>' of template<typename T>), regex_replace is
 * used to remove any character that is not a letter or underscore. The removed characters 
 * are replaced with a blank space. This process sometimes leaves a string with whitespace 
 * separated tokens, which are then passed to a stringstream object for individual compari-
 * son with each of the keywords in sourceKeywords set. Upon a match, the found keyword is
 * then inserted into the multiset "foundKeywords". 
 */
#include "CountKeywords.h"

// Default constructor CountKeywords
CountKeywords::CountKeywords()
{
	keyFileIn = "c++_Keywords_And_MicrosoftExtensions.txt";
	searchFileIn = "source.txt";
	openFile(fileKeywords, keyFileIn);
	openFile(fileSearch, searchFileIn);
	createKeywordSet();
	tokenizeSearchFile();
}

// user-specified source/search file constructor CountKeywords
CountKeywords::CountKeywords(string keywordsFile, string searchFile)
{
	keyFileIn = keywordsFile;
	searchFileIn = searchFile;
	openFile(fileKeywords, keyFileIn);
	openFile(fileSearch, searchFileIn);
	createKeywordSet();
	tokenizeSearchFile();
}

// Open a file
void CountKeywords::openFile(ifstream& fileObject, string& filename)
{
	fileObject.open(filename);
	// prompt user until valid file is provided
	while( fileObject.fail() )
	{
		cout << "\n file: \"" << filename << "\" was not found in program directory.\n" << endl;
		cout << "Please ensure file exists and try again\nfilepath>";
		cin >> filename;
		cout << "\n" << endl;
		fileObject.open(filename);
	}
} // end openFile() function

// Create set from keywords
void CountKeywords::createKeywordSet()
{
	istream_iterator<string> fileKeywordsIterator(fileKeywords); // input stream iterator for fileKeywords

	// Insert each line of keywordsFile into keywordSet. These are the c++ keyword tokens
	while( !fileKeywords.eof() )
	{
		sourceKeywords.insert( *fileKeywordsIterator );
		fileKeywordsIterator++;
	} // end while !keywordsFile.eof()
	fileKeywords.close(); // close keywordsFile - keywords stored in keywordSet	
} // end createKeywordSet() function

// Tokenize file to search for keywords
void CountKeywords::tokenizeSearchFile()
{
	regex rx ("[^_A-Za-z]"); // Match any character that isn't a letter or underscore
	istream_iterator<string> searchFileIterator(fileSearch); // input stream iterator for fileSearch
	set<string>::iterator keywordsIterator; // string iterator for sourceKeywords set
	string rxMatchesRemoved; // store string remaining after regex_replace match(s) is processed
	string singleToken; // store individual tokens passed by stringstream
	string fmt = " "; // replace regex matches with a blank space

	while( !fileSearch.eof() ) // while not at the end of the user-specified file to process, find keyword tokens
	{
		rxMatchesRemoved = regex_replace ( (*searchFileIterator), rx, fmt); // string after regex_replace match
		// for each singleToken, search set of keywords; and, on match insert keyword into multiset
		for( keywordsIterator = sourceKeywords.begin(); keywordsIterator != sourceKeywords.end(); keywordsIterator++)
		{
			stringstream ss(rxMatchesRemoved);
			while( ss >> singleToken ) // while read input has valid return
			{	
				if( singleToken.compare( (*keywordsIterator) ) == 0 )
					foundKeywords.insert(singleToken);
			}
		}
		searchFileIterator++; // increment iterator for fileSearch
	} // end while !fileSearch.eof() loop
} // end tokenizeSearchFile() function

// Print contents of foundKeywords multiset
void CountKeywords::printFoundKeywords()
{
	char dash = '-';
	multiset<string>::iterator foundKeywordsIterator;

	cout << "Keywords source: \"" << keyFileIn << "\"" << endl;
	cout << "Search document: \"" << searchFileIn << "\"\n" << endl;
	cout << "Total numer of keywords is: " << sourceKeywords.size() << endl;
	cout << "Total number of keywords found is: " << foundKeywords.size() << "\n" << endl;
	cout << setfill('_') << left << setw(80) << "" << endl;
	cout << setfill(' ') << setw(5) << "" << setw(30) << "KEYWORD" << setw(20) << "" << setw(20) << "FREQUENCY" << endl;
	cout << setfill('_') << left << setw(80) << "" << endl;
	for( foundKeywordsIterator = foundKeywords.begin(); foundKeywordsIterator != foundKeywords.end(); foundKeywordsIterator++)
	{
		cout << setfill(' ') << left << setw(5) << "" << setw(30) << (*foundKeywordsIterator) << setw(25) << "" << setfill(' ') << setw(20) << foundKeywords.count( (*foundKeywordsIterator) );
		cout << setfill('_') << left << setw(80) << "";
	}
} // end printFoundKeywords() function