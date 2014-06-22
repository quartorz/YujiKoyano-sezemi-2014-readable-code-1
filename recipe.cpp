#include <fstream>
using namespace std;
 
int main(){
  
	ofstream fs1("recipe-data.txt");
    fs1 << "オムライス" << endl;
    fs1 << "親子丼" << endl;
    fs1 << "杏仁豆腐" << endl;

    return 0 ;
}