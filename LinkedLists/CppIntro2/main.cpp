#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <vector>
#include "HashMap.h"
#include <array>
#include <list>

using namespace std;

int main() {
	srand(time(0));
	HashMap<int, string> map;

	map.Insert(1, "hello");
	map.Insert(4, "test");
	map.Insert(5, "asfd");
	
	map.Replace(1, "goodbye");
	
	cout << map.Get(1);

	system("PAUSE");
}
