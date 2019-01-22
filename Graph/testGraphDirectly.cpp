#include "Headers/headers.h"
#include "Headers/PatternParser.h"

Graph sampleGraph(){
	Graph g;
	g.insert(14);
	g.insert(17,14);
	g.insert(20,17);
	g.insert(1,5);
	g.insert(1,2);
	g.insert(2);
	g.insert(3,1);
	g.insert(3,12);
	g.insert(3,20);
	g.insert(5,6);
	g.insert(5,19);
	g.insert(6,7);
	g.insert(6,8);
	g.insert(6,10);
	g.insert(6,11);
	g.insert(7);
	g.insert(8);
	g.insert(10);
	g.insert(11,3);
	g.insert(19);
	g.insert(12);

	return g;
}

int main(int argc,char **argv){
	Graph g;
	g = sampleGraph();
	//g.display(); if you want to display the graph : vertes -- edge format uncomment
	g.BSF(1,19);

}

