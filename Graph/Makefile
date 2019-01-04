execute: cRunTest cRunTestFile
runTest:cRunTest
	./runnableTest
runTestFile:cRunTestFile
	./runnableTestFile graphTestFiles/sample.txt 1 7
cRunTest: path stack queue list graph pParser test
	g++ Path.o Stack.o Queue.o List.o Graph.o PatternParser.cpp testGraphDirectly.o -o runnableTest
cRunTestFile: path stack queue list graph pParser testFile
	g++ Path.o Stack.o Queue.o List.o Graph.o PatternParser.cpp testGraphUsingFile.o -o runnableTestFile
testFile: testGraphUsingFile.cpp
	g++ -c testGraphUsingFile.cpp
test: testGraphDirectly.cpp
	g++ -c testGraphDirectly.cpp
path: Path.cpp
	g++ -c Path.cpp 
stack: Stack.cpp
	g++ -c Stack.cpp
queue:
	g++ -c Queue.cpp
list: List.cpp
	g++ -c List.cpp
graph: Graph.cpp
	g++ -c Graph.cpp
pParser: PatternParser.cpp
	g++ -c PatternParser.cpp
clean:
	rm *.o
