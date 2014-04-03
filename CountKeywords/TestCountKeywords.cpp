/* Filename:        TestCountKeywords.cpp
 * Last Modified:   2 April 2014
 * Author:          Todd Parker
 * Email:           todd.i.parker@maine.edu
 * Course:          CIS354 - Algorithms and Data Structures
 * 
 * TestCountKeywords.cpp is a test program for CountKeywords.h|CountKeywords.cpp.
 * it servers only to print a signature block header, a brief message to the user
 * informating them when the program does, and then a menu to the user prompting 
 * them to either run the default documents or furnish their own. Upon making their
 * choice a CountKeywords object is created, which causes the program to run its
 * course and then print the results.
 */
#include "SignatureBlock.h"
#include "CountKeywords.h"

using namespace std;

int main()
{
	SignatureBlock::printHeader();

	cout << "This program loads C++ keywords and MSDN extensions from a file in the program directory,"
			 "and then prompts the user to specify a source file with which to search for said keywords.\n" << endl;

	cout << "Please enter '0' to run default files or '1' to specify your own:\n>";
	int choice;
	cin >> choice;
	
	if (!choice)
	{
		CountKeywords test;
		test.printFoundKeywords();
	}
	else
	{
		string keywordFile, searchFile;
		cout << "\nPlease specify the filepath for the \"keywords\" document:\n>";
		cin >> keywordFile;
		cout << "\nPlease specify the filepath for the \"search\" document:\n>";
		cin >> searchFile;
		CountKeywords test(keywordFile, searchFile);
		test.printFoundKeywords();
	}

	getchar();
	return 0;
} // End main()