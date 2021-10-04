#include <iostream>
#include <map>
#include <string>
#include "my_map.h"
using namespace std;

Lfu::Lfu(size_t size) {
	this->size = size;
}

Lfu::~Lfu() {
	my_map.clear();
}

std::ostream& operator<<(std::ostream& out, const Lfu& l) {
	const map <string, int> &map = l.my_map;
	for (auto it = map.cbegin(); it != map.cend(); ++it) {
		cout << it->first << ": " << it->second << endl;
	}
	return out;
}

bool Lfu::add(const string& address) {
	map <string, int>::iterator it = my_map.find(address);
	
	if (it == my_map.end()) {
		my_map.insert(pair<string, int>(address, 1));
		counter.insert(pair< int, string>(1, address));
		if (my_map.size() > size) {
			del_min_key();
		}
		return false;
	}
	else {
		int key = it->second;
		it->second++;
		for (multimap<int, string>::iterator it = counter.find(key);
			it != counter.end() && it->first == key;
			++it) {

			if (it->second == address) {
				counter.erase(it);
				break;
			}
		}
		counter.insert(std::pair<int, string>(key + 1, address));

	}
	if (my_map.size() > size) {
		del_min_key();
	}
	return true;
}

void Lfu::del_min_key() {
	if (my_map.size() == 0) {
		return;
	}
	multimap<int, string>::iterator it = counter.begin();
	my_map.erase(it->second);
	counter.erase(it);
}