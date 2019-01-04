#include "Headers/headers.h"
#include "Headers/Graph.h"

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
