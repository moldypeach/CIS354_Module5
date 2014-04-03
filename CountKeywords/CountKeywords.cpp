#include "CountKeywords.h"

// Default constructor CountKeywords
CountKeywords::CountKeywords()
{
	openFile(fileKeywords, "c++_Keywords_And_MicrosoftExtensions.txt");
	openFile(fileSearch, "source.txt");
}

// user-specified source/search file constructor CountKeywords
CountKeywords::CountKeywords(string keywordsFile, string searchFile)
{
	openFile(fileKeywords, keywordsFile);
	openFile(fileSearch, searchFile);
}

// Open a file
CountKeywords::openFile(ifstream* fileObject, string* filename)
{
	fileObject(filename);
	
	while( fileObject.fail() )
	{
		cout << "\n file: \"" << filename << "\" was not found in program directory.\n" << endl;
		cout << "Please ensure file exists and try again\nfilepath>";
		cin >> filename;
		cout << "\n" << endl;
		openFile(fileObject, filename);
	}
} // end openFile() function