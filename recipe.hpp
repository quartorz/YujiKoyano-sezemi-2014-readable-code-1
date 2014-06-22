#include <string>
#include <vector>
#include <ostream>

struct Recipe{
	int id;
	std::string name, url;

	int get_id() const
	{
		return id;
	}
	std::string &get_name()
	{
		return name;
	}
	std::string &get_url()
	{
		return url;
	}
	const std::string &get_name() const
	{
		return name;
	}
	const std::string &get_url() const
	{
		return url;
	}
	friend std::ostream &operator<<(std::ostream &o, const Recipe &r)
	{
		o << r.id+1 << ": " << r.name << ' ' << r.url;
		return o;
	}
};

class User{
	std::string name;
	std::vector<Recipe> recipes;

public:
	User() = default;
	User(const User &) = default;
	User(const std::string &user_name)
		: name(user_name)
	{
	}
	void set_name(const std::string &n)
	{
		name = n;
	}
	std::string &get_name()
	{
		return name;
	}
	const std::string &get_name() const
	{
		return name;
	}
	std::vector<Recipe> &get_recipes()
	{
		return recipes;
	}
};
