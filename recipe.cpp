
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Recipe{
	std::string name, url;
};
 
int main(int argc, char *argv[]){
  
	ifstream inStream(argv[1]);
  	string fileText,fileURL;;
  	Recipe inputRecipe[3];
  	int lineCounter = 0;

   	while ( inStream >> fileText >> fileURL ) {
    	inputRecipe[lineCounter] = { fileText, fileURL };
    	lineCounter++;
  	}

  	inStream.close();

	if(argc < 3){
		for(int id = 0; id < 3 ; id++){
			cout << id+1 << ": " << inputRecipe[id].name << ' ' << inputRecipe[id].url << endl;
		}
	}else{
		int id = std::atoi(argv[2]) - 1;
		cout << id+1 << ": " << inputRecipe[id].name << ' ' << inputRecipe[id].url << endl;
	}
    
    return 0 ;
}