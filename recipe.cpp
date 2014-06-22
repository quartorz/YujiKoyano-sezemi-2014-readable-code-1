
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Recipe{
	int id;
	string name, url;

	int get_id() const
	{
		return id;
	}
	string &get_name()
	{
		return name;
	}
	string &get_url()
	{
		return url;
	}
	const string &get_name() const
	{
		return name;
	}
	const string &get_url() const
	{
		return url;
	}
	friend ostream &operator<<(ostream &o, const Recipe &r)
	{
		o << r.id+1 << ": " << r.name << ' ' << r.url;
		return o;
	}
};

class User{
	string name;
	vector<Recipe> recipes;

public:
	User() = default;
	User(const User &) = default;
	User(const string &user_name)
		: name(user_name)
	{
	}
	template <class Container>
	User(const string &user_name, const Container &recipes)
		: name(user_name)
		, recipes(begin(recipes), end(recipes))
	{
	}
	void set_name(const string &n)
	{
		name = n;
	}
	string &get_name()
	{
		return name;
	}
	const string &get_name() const
	{
		return name;
	}
	vector<Recipe> &get_recipes()
	{
		return recipes;
	}
};

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