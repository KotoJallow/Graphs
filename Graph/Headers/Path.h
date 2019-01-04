#ifndef Path_H
#define Path_H
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
#endif