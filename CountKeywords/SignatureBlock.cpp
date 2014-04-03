#include <iostream>
#include <iomanip>
#include "SignatureBlock.h"
using namespace std;

const char SignatureBlock::star = '*';
const char SignatureBlock::blank = ' '; 

void SignatureBlock::printHeader()         //print DOS header
{  
 for(int l=1;l<=80;l++)
  {
   cout << star;
  }
 cout << setfill(blank) << left <<  setw(40) << star << right << setw(40)
      << star;
 cout << setfill(blank) << left <<  setw(4) << star << setw(72) 
      << "AUTHOR:  Todd Parker" << right << setw(4) << star;
 cout << setfill(blank) << left <<  setw(4) << star << left << setw(73)
      << "COURSE:  CIS354 - Algorithms and Data Structures"
      << right << setw(3) << star;
 cout << setfill(blank) << left <<  setw(4) << star << left << setw(73)
      << "EMAIL:   todd.i.parker@maine.edu"
      << right << setw(3) << star;
 cout << setfill(blank) << left <<  setw(40) << star << right << setw(40)
      << star;
 for(int l=1;l<=80;l++)
  {
   cout << star;
  }
 cout << endl; 
}
