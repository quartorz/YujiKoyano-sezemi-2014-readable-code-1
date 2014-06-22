#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "recipe.hpp"

int main(int argc, char *argv[]){
  
  	string fileText,fileURL;;
  	User users[4];
  	int lineCounter = 0;
  	for(int i = 0; i < 4; i++){
  		// argv : ./a.out user1 data1.txt user2 data2.txt ... useri datai.txt
  		//              0     1         2     3         4 ... 2*i+1     2*i+2
  		users[i].set_name(argv[i * 2 + 1]);
  		ifstream inStream(argv[i * 2 + 2]);
	   	while ( inStream >> fileText >> fileURL ) {
	    	users[i].get_recipes().push_back({ lineCounter, fileText, fileURL });
	    	lineCounter++;
	  	}
  	}

  	int id;
  	if(argc < 10)
  		id = -1;
  	else
  		id = atoi(argv[9]) - 1;

  	for(int i = 0; i < 4; i++){
  		cout << "ユーザー名: " << users[i].get_name() << endl;
  		for(int j = 0; j < 3; j++){
  			if(id == -1 || users[i].get_recipes()[j].get_id() == id)
  				cout << users[i].get_recipes()[j] << endl;
  		}
  		cout << endl;
  	}
    
    return 0 ;
}