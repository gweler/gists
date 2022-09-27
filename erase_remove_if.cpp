#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

bool isOdd(int i)
{
	return i % 2 != 0;
}

int main()
{
	vector<int> v = {1, 2, 3, 4, 5};

	/*
	v.erase(remove_if(v.begin(), v.end(), [](const int& x) {
		return x % 2 == 0;}),
		v.end());
	*/

	v.erase(remove_if(v.begin(), v.end(), isOdd), v.end());

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

	return 0;
}
