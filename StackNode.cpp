//Oliver Rochester
//this is the cpp file for the stack node
//this implements all methods for viewing and retrieving and setting information from nodes in the stack
#include <iostream>
#include <string>
#include <cstdlib>
#include "StackNode.h"
using namespace std;

//constructor that takes in a string and a node
StackNode::StackNode(string s, StackNode* n) {

	S = s;
	next = n;
}

//destructor
StackNode::~StackNode() {

	delete next;
}

//method that returns the string in the node
string StackNode::getS() {

	return S;
}
//method that returns the node that next is pointing to
StackNode* StackNode::getnext() {

	return next;
}
//method that changes what next points to
void StackNode::setnext(StackNode* n) {

	next = n;
}
