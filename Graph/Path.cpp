#include "Headers/headers.h"
#include "Headers/Path.h"

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