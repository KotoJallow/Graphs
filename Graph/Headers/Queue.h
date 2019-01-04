#ifndef Queue_H
#define Queue_H 
#include "Node.h"
class Queue
{
private:
	Node* first;
	Node* rear;
public:
	Queue();
	bool isEmpty();
	Node* createNode(int);
	void enqueue(int);
	void dequeue();
	void display();
	int peek();
};
#endif