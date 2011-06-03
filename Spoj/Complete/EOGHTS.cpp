#include <iostream>
#include <vector>

#define lint unsigned long long

using namespace std;

int main()
{
	lint T, N;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N;
		cout << ((N-1)*250 + 192) << endl;
	}

	return 0;
}