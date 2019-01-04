#include "Headers/headers.h"
#include "Headers/List.h"

List::List(){
	head = NULL;
	nodeIndex = NULL;
}

Node* List::getHead(){
	return head;
}
Node* List::createNode(int data){
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

bool List::nodeExist(int data){
	Node* temp = head;
	while(temp){
		if(temp->data == data){
			nodeIndex = temp;
			return true;
		}
		temp = temp->next;		
	}
	return false;
}

void List::insert(int data){
	if(head == NULL){
		head = createNode(data);
	}else if(nodeExist(data)){
		return;
	}else{
		Node* temp = head;
		while(temp->next){
			temp = temp->next;
		}
		temp->next = createNode(data);
	}
}

void List::display(){
	if(head == NULL){
		cout << endl;
	}
	Node* temp = head;
	while(temp){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}