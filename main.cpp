#include <iostream>
#include <map>
#include <string>
#include "Lfu.h"
using namespace std;


int main() {
	Lfu<int> cache(3);
	cache.add(2);
	cache.add(33);
	cache.add(111);
	cache.add(111);
	cache.add(33);
	cache.add(111);
	cache.add(4);

	cout << cache;

	return 0;
}
