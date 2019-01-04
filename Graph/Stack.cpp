#include "Headers/headers.h"
#include "Headers/Stack.h"

Stack::Stack(){
	top = NULL;
}
void Stack::push(int data){
	Node* n = new Node;
	n->data = data;
	n->next = top;
	top = n;
}
void Stack::pop(){
	if(top){
		Node* temp = top;
		top = top->next;
		delete temp;
	}
}
void Stack::display(){
	Node* temp = top;
	while(temp){
		cout << temp->data;
		temp = temp->next;
		if(temp)
			cout << "->";
	}
	cout << endl;
}