#include <iostream>
#include <vector>

#define lint long long
using namespace std;

struct bits {
	lint end0;
	lint end1;
};

void bitCount(vector <int> index, vector <int> n, vector <int> k, int maxN, int maxK);

int main()
{
	int T, x, y, z;
	cin >> T;
	vector <int> index (T);
	vector <int> n (T);
	vector <int> k (T);

	int maxN = 0;
	int maxK = 0;
	for (int i = 0; i < T; ++i) {
		cin >> z >> x >> y;
		index[i] = z;
		n[i] = x;
		k[i] = y;
		if (maxN < x) {
			maxN = x;
		}
		if (maxK < y) {
			maxK = y;
		}
	}

	bitCount(index, n, k, maxN, maxK);

	return 0;
}

void bitCount(vector <int> index, vector <int> n, vector <int> k, int maxN, int maxK)
{
	bits temp;
	temp.end0 = 0;
	temp.end1 = 0;
	vector <vector <bits> > bc(maxK+1, vector <bits> (maxN+1,temp));

	bc[0][1].end0 = bc[0][1].end1 = 1;
	for (int i = 2; i < bc[0].size(); ++i) {
		bc[0][i].end0 = bc[0][i-1].end0 + bc[0][i-1].end1;
		bc[0][i].end1 = bc[0][i-1].end0;
	}

	lint s1 = bc.size();
	lint s2 = bc[0].size();
	for (int i = 1; i < s1; ++i) {
		for (int j = i+1; j < s2; ++j) {
			bc[i][j].end0 = bc[i][j-1].end0 + bc[i][j-1].end1;
			bc[i][j].end1 = bc[i-1][j-1].end1 + bc[i][j-1].end0;
		}
	}

	for (int i = 0; i < n.size(); ++i) {
		cout << index[i] << " " << (bc[k[i]][n[i]].end0+bc[k[i]][n[i]].end1) << endl;
	}

/*	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			cout << bc[i][j].end0 << ", " << bc[i][j].end1 << "  ";
		}
		cout << endl;
	}*/
}