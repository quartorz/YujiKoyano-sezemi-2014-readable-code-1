#include <fstream>
using namespace std;
 
int main(){
  
	ofstream fs1("recipe-data.txt");
    fs1 << "オムライス" << endl;
    return 0 ;

}