# Graphs
Shortest path from a given vertex to another within a graph

Dijkstra algorithm c++

1. The software can be executed using a file containing the vertices and edges.
  The acceptable file standard is:
            "v":{
                  "e1","e2"...."en"
             },
 v is a vertex and e represent the edges.
  Note: Very edge should be defined as a vertex too. An vertex can be without an edge.

2. The software can be executed by directly setting the vertices and edges using the overloaded insert() method.
  insert(v) insert(v,e1) insert(v,e2) .... insert(v,en);
  Note: Very edge should be defined as a vertex too. An vertex can be without an edge.

I have provided two test files testGraphUsingFile.cpp and testGraphDirectly.cpp for 1 & 2 respectively.

Linux users running the make file will create both test CPP files.
