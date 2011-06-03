#include <iostream>
#include <vector>

using namespace std;

char final (int n, int m);

int main()
{
	int T;
	int row, col;
	vector <int> R;
	vector <int> C;

	cin >> T;
	
	for (int i = 0; i < T; i ++) {
		cin >> row >> col;
		R.push_back(row);
		C.push_back(col);
	}

	for (int i = 0; i < (int)R.size(); i ++) {
		cout << final(R[i], C[i]) << endl;
	}

	return 0;
}

char final (int n, int m)
{
	if (n == m) {
		if (n % 2 == 0) {
			return 'L';
		}
		return 'R';
	}

	if (n > m) {
		if (m % 2 == 0) {
			return 'U';
		}
		return 'D';
	}

	if (n % 2 == 0) {
			return 'L';
	}

	return 'R';
}
