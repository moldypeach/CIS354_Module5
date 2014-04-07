/* Filename:        TestCountKeywords.cpp
 * Last Modified:   7 April 2014
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
#include <stdexcept>

using namespace std;

// Function validates user made a proper menu choice
int validateReponse(string& menuChoice)
{
	int responseVal;
	try
	{
		responseVal = stoi(menuChoice, nullptr);		
	}
	catch( invalid_argument e)
	{
		cout << "\n\tERROR: '" << menuChoice << "' is not a valid response\n" << endl;
		responseVal = -1;
	}
	catch ( out_of_range o )
	{
		cout << "\n\tERROR: '" << "' is outside the allowable range\n" << endl;
		responseVal = -1;
	}
	
	return responseVal;
} // end validateResponse() function

int main()
{
	SignatureBlock::printHeader();

	cout << "This program loads C++ keywords and MSDN extensions from a file in the program directory,"
			 "and then prompts the user to specify a source file with which to search for said keywords."
			 "This implementation works only with string-based matching\n" << endl;

	int responseVal; // User menu choice
	do
	{
		cout << "Please enter '0' to run default files or '1' to specify your own:\n>";
		string response;
		cin >> response;
		responseVal = validateReponse(response);
	} while( (responseVal < 0) || (responseVal > 1) );

	CountKeywords* countObject;
	if (!responseVal)
	{
		countObject = new CountKeywords();
	}
	else
	{
		string keywordFile, searchFile;
		cout << "\nPlease specify the filepath for the \"keywords\" document:\n>";
		cin >> keywordFile;
		cout << "\nPlease specify the filepath for the \"search\" document:\n>";
		cin >> searchFile;
		countObject = new CountKeywords(keywordFile, searchFile);
	}

	countObject->printFoundKeywords(); // print results
	cin.ignore(80, '\n'); // clear input stream
	getchar(); // pause program so output may be read

	return 0;
} // End main()