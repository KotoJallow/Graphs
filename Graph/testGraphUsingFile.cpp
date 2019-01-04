#include "Headers/headers.h"
#include "Headers/PatternParser.h"


int main(int argc,char **argv){
	PatternParser p ;
	int s,e;
	if(argc > 3){
		p.readFile(argv[1]);
		if(argc == 4){
			s = atoi(argv[2]);
			e = atoi(argv[3]);
		}
		p.BSF(s,e);
	}else{
		cout << "Missing command line arguments" << endl;
	}
}

