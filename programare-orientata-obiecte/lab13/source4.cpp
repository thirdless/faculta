#include<iostream>
#include<vector>
#include<algorithm>
#include <cstdio>
#include <ctime>
using namespace std;

vector<int> v(8000000);

int main() {
	generate(v.begin(), v.end(), rand);
	clock_t start = clock();
	make_heap(v.begin(), v.end());
	sort_heap(v.begin(), v.end());
	clock_t stop = clock();
	cout << ((double)(stop - start)) / CLOCKS_PER_SEC << endl;
	system("pause");
	return 0;
}
