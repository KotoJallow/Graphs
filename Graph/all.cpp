#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>

using namespace std; 

struct Node{
	int data;
	Node* next;	
};

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
struct PathNode{
	int vertex;
	int visitedFrom;
	PathNode *next;
};

class Path{
private:
	PathNode* startPoint;
	PathNode* createPath(int,int);
public:
	Path();
	void insert(int,int);
	int getVisitedFrom(int vertex);
	int getVertex(int vf);
};

Path::Path(){
	startPoint = NULL;
}
PathNode* Path::createPath(int v,int vf){
	PathNode* pn = new PathNode;
	pn->vertex = v;
	pn->visitedFrom = vf;
	pn->next = NULL;
	return pn;
}
void Path::insert(int v,int vf){
	if(startPoint == NULL){
		startPoint = createPath(v,vf);
	}else{
		PathNode* temp = startPoint;
		while(temp->next){
			temp = temp->next;
		}
		temp->next = createPath(v,vf);
	}
}
int Path::getVisitedFrom(int vertex){
	PathNode* temp = startPoint;
	while(temp){
		if(temp->vertex == vertex){
			return temp->visitedFrom;
		}
		temp = temp->next;
	}
	cout << "Stupidity.\nYou guys are annoying.\nWhy should get visited from of false vertex?\nProgram Ends." << endl;
	exit(0);
}

int Path::getVertex(int vf){
	PathNode* temp = startPoint;
	while(temp){
		if(temp->visitedFrom == vf){
			return temp->vertex;
		}
		temp = temp->next;
	}
	cout << "Stupidity.\nYou guys are annoying.\nWhy should get visited from of false vertex?\nProgram Ends." << endl;
	exit(0);
}


struct GraphNode{
	int vertices;
	List edges;
	GraphNode* next;
};


class Graph{
	private:
		Queue q;
		List visited;
		Path p;
		Stack s;
		GraphNode* startPoint;
		GraphNode* createVertices(int);
		GraphNode* createVerticesEdges(int,int);
		GraphNode* vertexIndex;
		void pathStartToPoint(int,int);
		bool verticeExist(int);
	public:
		Graph();
		void init();
		void insert(int v,int e);
		void insert(int v);
		void BSF(int,int);
		void display();	
		GraphNode* getVertexIndex(int);
};

Graph::Graph(){
	startPoint = NULL;
	vertexIndex = NULL;
}
bool Graph::verticeExist(int v){
	GraphNode* temp = startPoint;
	while(temp){
		if(temp->vertices == v){
			vertexIndex = temp;
			return true;
		}
		temp = temp->next;
	}
	return false;
}

GraphNode* Graph::getVertexIndex(int v){
	if(verticeExist(v)){
		return vertexIndex;
	}
	return NULL;
}
GraphNode* Graph::createVertices(int v){
	GraphNode* newGraphNode = new GraphNode;
	newGraphNode->vertices = v;
	newGraphNode->next = NULL;
	return newGraphNode;
}

GraphNode* Graph::createVerticesEdges(int v,int e){
	GraphNode* newGraphNode = createVertices(v);
	newGraphNode->edges.insert(e);
	return newGraphNode;
}

void Graph::insert(int v){
	if(startPoint == NULL){
		startPoint = createVertices(v);
	}else if(verticeExist(v)){
		return;
	}
	else{
		GraphNode* temp = startPoint;
		while(temp->next){
			temp = temp->next;
		}
		temp->next = createVertices(v);
	}
}
void Graph::insert(int v,int e){
	if(startPoint == NULL){
		startPoint = createVerticesEdges(v,e);
	}else if(verticeExist(v)){
		vertexIndex->edges.insert(e);
	}
	else{
		GraphNode* temp = startPoint;
		while(temp->next){
			temp = temp->next;
		}
		temp->next = createVerticesEdges(v,e);
	}	
}

void Graph::pathStartToPoint(int startVertex,int endVertex){
	if(startVertex != endVertex){

		int start = startVertex;
		bool possible = false;

		if(verticeExist(startVertex) && verticeExist(endVertex)){
			s.push(endVertex);
			q.enqueue(startVertex);
			visited.insert(startVertex);
			p.insert(startVertex,-1);
			if(getVertexIndex(startVertex)->edges.nodeExist(endVertex)){
				s.push(startVertex);
			}else{
				while(!q.isEmpty()){
					startVertex = q.peek();
					Node* temp;
					if(getVertexIndex(startVertex)){
						temp = getVertexIndex(startVertex)->edges.getHead();
					}
					else{
						cout << startVertex << " is not a vertex" << endl;
						return;
					}
					while(temp){
						if(!visited.nodeExist(temp->data)){
							q.enqueue(temp->data);
							visited.insert(temp->data);
							p.insert(temp->data,startVertex);
						}
						temp = temp->next;
					}

					q.dequeue();
					if(getVertexIndex(startVertex)->edges.nodeExist(endVertex)){
						possible = true;
						int t = p.getVisitedFrom(endVertex);
						int st = p.getVertex(t);
						while(st != start){
							s.push(t);
							t = p.getVisitedFrom(t);
							st = p.getVertex(t);
						}
						break;
					}
				}
				if(!possible){
					cout << "From " << start << " to " << endVertex << " Impossible." << endl;
					return;
				}
			}
			s.display();
		}else{
			cout << "Impossible" << endl;
			return;
		}

	}else{
		cout << "Two points should be different." << endl;
	}
}

void Graph::BSF(int s,int e){
	pathStartToPoint(s,e);
}

void Graph::display(){
	if(startPoint == NULL){
		return;
	}
	GraphNode* temp = startPoint;
	cout << "Vertices"<< setw(13) << "Edges" << endl;
	while(temp){
		cout << setw(4) << temp->vertices << setw(15); temp->edges.display();
		setw(2);
		temp = temp->next;
	}
	cout << endl;
}

int main(){
int arr[8][8] = { {0, 1, 1, 0, 0, 0, 0, 0}, 
					  {1, 0, 1, 1, 1, 0, 0, 0}, 
					  {1, 1, 0, 0, 1, 0, 1, 1}, 
					  {0, 1, 0, 0, 1, 0, 0, 0},
					  {0, 1, 1, 1, 0, 1, 0, 0}, 
					  {0, 0, 0, 0, 1, 0, 0, 0}, 
					  {0, 0, 1, 0, 0, 0, 0, 1}, 
					  {0, 0, 1, 0, 0, 0, 1, 0}
					};
					
					Graph g;
					g.insert(1,2);
					g.insert(1,3);
					
					g.insert(2,1);
					g.insert(2,3);
					g.insert(2,4);
					g.insert(2,5);
					
					g.insert(3,1);
					g.insert(3,2);
					g.insert(3,5);
					g.insert(3,7);
					g.insert(3,8);
					
					g.insert(4,2);
					g.insert(4,5);
					
					g.insert(5,2);
					g.insert(5,3);
					g.insert(5,4);
					
					g.insert(6,5);
					
					g.insert(7,3);
					g.insert(7,8);
					
					g.insert(8,3);
					g.insert(8,7);
					
					g.display();
	
					g.BSF(1,8);				
          return 0;				
}
