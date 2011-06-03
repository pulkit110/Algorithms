#include <iostream>
#include <vector>
#include <string>

using namespace std;

int min (int a, int b);

int main()
{
	int N, M, F, minimum;
	string s;
	vector <vector <int> > sz;
	cin >> M >> N;
	while (N != 0 && M != 0) {
		cin >> F;
		sz.assign(M,vector<int> (N,0));
		for (int i = 0; i < M; ++i) {
			cin >> s;
			for (int j = 0; j < N; ++j) {
				if (s[j] == 'H') {
					sz[i][j] = 1;
				}
			}
		}
		//cout << "Pulkit";
		minimum = 0;
		for (int i = 1; i < M; ++i) {
			for (int j = 1; j < N; ++j) {
				sz[i][j] = min(sz[i][j - 1], min(sz[i - 1][j], sz[i - 1][j - 1])) + 1;
				if (sz[i][j] > minimum) minimum = sz[i][j];
			}
		}
		cout << (long long)minimum*F << endl;
		cin >> M >> N;
	}
	return 0;
}

int min (int a, int b)
{
	if (a<b) return a;
	else return b;
}
