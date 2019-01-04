#ifndef PatternParser_H
#define PatternParser_H
#include "headers.h"
#include "Graph.h"

class PatternParser
{
private:
	int aposData(string);
	bool aposFormatted(string);
	bool bracketsFormatted(string);
	string bracketsData(string);
	string trim(string);
	Graph g;
public:
	PatternParser();
	void readFile(string);
	void BSF(int,int);
};

#endif