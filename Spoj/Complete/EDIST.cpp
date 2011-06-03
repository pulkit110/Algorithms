#include <iostream>
#include <vector>
#include <string>

using namespace std;

void editDistance (string s1, string s2);
int min (int a, int b, int c);

int main ()
{
	int T;
	string s1, s2;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		cin >> s1 >> s2;
		editDistance(s1, s2);
	}

	
	return 0;
}

void editDistance (string s1, string s2)
{
	int l1 = (int)s1.length();
	int l2 = (int)s2.length();

	vector <vector <int> > v(l1+1, vector<int>(l2+1));

	for (int i = 0; i <= l1; ++i) {
		v[i][0] = i;
	}

	for (int j = 0; j <= l2; ++j) {
		v[0][j] = j;
	}

	for (int i = 1; i < v.size(); ++i) {
		for (int j = 1; j < v[i].size(); ++j) {
			if (s1[i-1] != s2[j-1]) {
				v[i][j] = min((v[i-1][j] +1), (v[i][j-1]+1), (v[i-1][j-1]+1));
			} else {
				v[i][j] = min((v[i-1][j] +1), (v[i][j-1]+1), (v[i-1][j-1]));
			}
		}
	}

	cout << v[l1][l2] << endl;
}

int min (int a, int b, int c)
{
	int min = a;
	if (min > b) {
		min = b;
	} 
	if (min > c) {
		min = c;
	}

	return min;
}