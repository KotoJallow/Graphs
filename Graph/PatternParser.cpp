#include "Headers/PatternParser.h"

PatternParser::PatternParser(){

}
bool PatternParser::aposFormatted(string s){
	if(s[0] == '\"' && s[s.size()-1]=='\"'){
		return true;		
	}
	return false;
}
string PatternParser::trim(string s){
	string t ="";
	for(int i=0;i<s.size();i++){
		if(!isblank(s[i]) && (s[i] != '\n')){
			t+=s[i];
		}
	}
	return t;
}
bool PatternParser::bracketsFormatted(string s){
	if(s[0] == '{' && s[s.size()-1]=='}'){
		return true;		
	}
	return false;
}

string PatternParser::bracketsData(string s){
	string t = s;
	if(bracketsFormatted(s)){
		t = t.substr(1).substr(0,t.size()-2);
		return t;
	}
	return "";
}

int PatternParser::aposData(string s){
	string t = trim(s);
	if(aposFormatted(t)){
		t = t.substr(1).substr(0,t.size()-2);
	}
	return atoi(t.c_str());
}

void PatternParser::readFile(string fileName){
	//Convert string filename to c string. c_str()
	ifstream fin(fileName.c_str());
	if(!fin){
		cout << "Error in loading file" << endl;
		exit(0);
	}
	string data;
	bool commaFound = false;
	ssize_t nread;
	while(getline(fin,data,',')){
		if(!fin.eof()){
			commaFound = true;
			int vertex,edge;
			int dIndex = data.find(':');
			//get vertices
			if(dIndex != -1){
				string v = trim(data.substr(0,dIndex));
				if(aposFormatted(v)){
					vertex = aposData(v);
					g.insert(vertex); //vertex inserted;
					data.erase(0,dIndex+1);
				}else{
					cout << "Invalid vertex Format" << endl;
					exit(0);
				}
			}else{
				cout << "Invalid vertex edge Format." << endl;
				exit(0);
			}
			//get edges	
			if(bracketsFormatted(data)){
				data = trim(bracketsData(data));

				if(data.size() == 0){
					//do nothing
				}else{
					int end = data.find('-');
					if(end == -1){
						edge = aposData(data); 
						g.insert(vertex,edge); //adjacent of a vertex/ edge inserted
					}else{
						do{
							edge = aposData(data);
							g.insert(vertex,edge); //adjacent of a vertex/ edge inserted
							data.erase(0,end+1);
							end = data.find('-');
						}while(end != -1);
						edge = aposData(data);
						g.insert(vertex,edge); //adjacent of a vertex/ edge inserted
					}
				}
			}else{
				cout << "Brackets not well formatted.";
				exit(0);
			}
		}else{
			if(!commaFound)
			cout << "File format invalid" << endl;
		}
	}
	fin.close();
}
void PatternParser::BSF(int s,int e){
	g.BSF(s,e);
}
