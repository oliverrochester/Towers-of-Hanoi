//Oliver Rochester
//this is the header file for the stack node file
#ifndef _STACKNODE_
#define _STACKNODE_

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class StackNode {
private:
	string S;
	StackNode* next;
public:
	//constructor that takes in a string and a node
	StackNode(string s, StackNode* n);
	//destructor
	~StackNode();
	//method that retrieves the string from the node
	string getS();
	//method that retrieves the next node 
	StackNode* getnext();
	//method to have a node to point to another node
	void setnext(StackNode* n);
};


#endif
