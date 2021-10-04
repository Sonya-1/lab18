#ifndef Map_H
#define Map_H

#include <iostream>
#include <map>
#include <string>
using namespace std;

class Lfu {
private:
	map <string, int> my_map;
	multimap<int, string> counter;
	size_t size;
public:
	Lfu(size_t size);
	~Lfu();
	friend ostream& operator<<(std::ostream& out, const Lfu& l);
	bool add(const string& address);
	void del_min_key();
};

#endif