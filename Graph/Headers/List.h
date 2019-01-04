#ifndef List_H
#define List_H 
#include "Node.h"
class List{
	private:
		Node* head;
		Node* createNode(int);
		Node* nodeIndex;
	public:
		List();
		bool nodeExist(int);
		void insert(int);
		Node* getHead();
		void display();
};
#endif