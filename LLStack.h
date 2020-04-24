#ifndef _LLSTACK_
#define _LLSTACK_

#include <iostream>
#include <string>
#include <cstdlib>
#include "StackNode.h"
//Oliver Rochester
//header file for the stack.cpp file
//implements the stacknode class as well
using namespace std;

class StackNode;
class LLStack {
private:
	StackNode* head;
public:
	//contructor for the stack 
	LLStack();
	//destructor for the stack
	~LLStack();
	//mthod that pushes a node on to the stack, takes in a string as a parameter
	void PUSH(string s);
	//method that removes a node from the stack
	string POP();
	//method that checks if the stack is empty by cheking if head is null
	bool ISEMPTY();
};


#endif
