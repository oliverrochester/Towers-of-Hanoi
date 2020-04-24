//Oliver Rochester
//main file for for the stack implementation using a linked list
#include <iostream>
#include <string>
#include <cstdlib>
#include "StackNode.h"
#include "LLStack.h"
using namespace std;

// stack constructor, sets head of list to null
LLStack::LLStack() {

	head = NULL;
}
// stack destructor, deletes head
LLStack::~LLStack() {

	delete head;
}
//method that pushes all the disk to the stack in correct order
void LLStack::PUSH(string s) {

	head = new StackNode(s, head);
}

//method that removes a node form the stack
string LLStack::POP() {

	StackNode* h = head;
	head = h->getnext();
	h->setnext(NULL);
	string s = h->getS();
	delete h;
	return s;
}

//method that checks if a stack is empty
bool LLStack::ISEMPTY() {

	return !head;
}