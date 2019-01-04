#include "Headers/headers.h"
#include "Headers/Queue.h"

Queue::Queue(){
	first = NULL;
	rear = NULL;
}
bool Queue::isEmpty(){
	return first == NULL;
}
Node* Queue::createNode(int data){
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void Queue::enqueue(int data){
	if(rear == NULL){
		rear = createNode(data);
		first = rear;
	}else{
		Node* temp = rear;
		while(rear->next){
			rear = rear->next;
		}
		rear->next = createNode(data);
	}
}

void Queue::dequeue(){
	if(first != NULL){
		Node* temp = first;
		first = first->next;
		delete temp;
	}
}

int Queue::peek(){
	if(!isEmpty()){
		return first->data;
	}else{
		cout << "Stupidity.\nYou guys are annoying.\nWhy should peek in empty Queue?\nProgram Ends." << endl;
		exit(1);
	}
}

void Queue::display(){
	Node* temp = first;
	while(temp){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}