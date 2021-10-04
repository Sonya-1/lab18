#ifndef Lfu_H
#define Lfu_H
#include <iostream>
#include <map>
#include <string>
using namespace std;

template <class T>
class Lfu {
private:
	map <T, int> my_map;
	multimap<int, T> counter;
	size_t size;
public:
	Lfu(size_t size) {
		this->size = size;
	}
	friend ostream& operator<<(std::ostream& out, const Lfu& l) {
		const map <T, int>& map = l.my_map;
		for (auto it = map.cbegin(); it != map.cend(); ++it) {
			cout << it->first << ": " << it->second << endl;
		}
		return out;
	}

	bool add(const T& address) {

		auto it = my_map.find(address);

		if (it == my_map.end()) {
			my_map.insert(pair<T, int>(address, 1));
			counter.insert(pair< int, T>(1, address));
			if (my_map.size() > size) {
				del_min_key();
			}
			return false;
		}
		else {
			int key = it->second;
			it->second++;
			for (auto it = counter.find(key); it != counter.end() && it->first == key; ++it) {
				if (it->second == address) {
					counter.erase(it);
					break;
				}
			}
			counter.insert(pair<int, T>(key + 1, address));

		}
		if (my_map.size() > size) {
			del_min_key();
		}
		return true;
	}

	void del_min_key() {
		if (my_map.size() == 0) {
			return;
		}
		auto it = counter.begin();
		my_map.erase(it->second);
		counter.erase(it);
	}
};

#endif