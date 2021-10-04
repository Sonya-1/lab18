#include <iostream>
#include <map>
#include <string>
#include "my_map.h"
using namespace std;

int main() {
	Lfu cache(3);
	cache.add("BB");
	cache.add("CC");
	cache.add("AAA");
	cache.add("AAA");
	cache.add("CC");
	cache.add("AAA");
	cache.add("d");

	cout << cache;
	
    return 0;
}
