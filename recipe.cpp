#include <fstream>
#include <iostream>
#include <string>
using namespace std;
 
int main(int argc, char *argv[]){
  
	ifstream inStream(argv[1]);
  	string inputText[3],fileText;;
  	int lineCounter = 0;

   	while ( getline(inStream, fileText) ) {
    	inputText[lineCounter] = fileText;
    	lineCounter++;
  	}

  	inStream.close();

	ofstream outStream("recipe-data-with-id.txt");
	for(int id = 0; id < 3 ; id++){
		outStream << id+1 << ": " << inputText[id] << endl;
	}
    
    return 0 ;
}