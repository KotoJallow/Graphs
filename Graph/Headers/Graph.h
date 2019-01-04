#ifndef Graph_h
#define Graph_h
#include "Path.h"
#include "Stack.h"
#include "Queue.h"
#include "List.h"

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

#endif