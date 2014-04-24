Source-Code-Keyword-Counter
===========================

(Count the number of keywords in C++ source-code)
Write a program that reads a C++ source-code file and reports the number of keywords in the file.


Use a set for keywords and a multiset for input to complete assignment 22.11.  The program should accept
a filename and report the total number of keywords found, and the count of each keyword included in the file.
Run your program to produce the keyword count report for its own source code.  Don’t forget to include your 
signature block on every page of the output. You may validate your code by running it against this piece of code:

    template<typename T>
     T LinkedList<T>::removeFirst() throw (runtime_error)
     {
     	if (size == 0)
     		throw runtime_error("No elements in the list");
     	else
     	{
     		Node<T>* temp = head;
     		head = head->next;
     		if (head == NULL) tail = NULL;
     		size--;
     		T element = temp->element;
     		delete temp;
     		return element;
     	}
     }

Returning the following data:
Joe Student
CIS 354 Algorithms and Data Structures
Joe.student@maine.edu
Found 9 keywords of the C++ language in the file sample.txt
Breakdown by keyword:
delete (1)
else (1)
if (2)
return (1)
template (1)
throw (2)
typename (1)
