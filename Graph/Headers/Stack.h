#ifndef Stack_H
#define Stack_H 
#include "Node.h"
class Stack
{
private:
	Node* top;
public:
	Stack();
	void push(int);
	void pop();
	void display();
};
#endif