#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "recipe.hpp"

int main(int argc, char *argv[]){
  
	ifstream inStream(argv[2]);
  	string fileText,fileURL;;
  	User user(argv[1]);
  	int lineCounter = 0;

   	while ( inStream >> fileText >> fileURL ) {
    	user.get_recipes().push_back({ lineCounter, fileText, fileURL });
    	lineCounter++;
  	}

  	inStream.close();

	cout << "ユーザー名: " << user.get_name() << endl;
	if(argc < 4){
		for(int id = 0; id < 3 ; id++){
			cout << user.get_recipes()[id] << endl;
		}
	}else{
		int id = atoi(argv[3]) - 1;
		cout << user.get_recipes()[id] << endl;
	}
    
    return 0 ;
}