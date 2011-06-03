#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct friends {
	int n;
	int k;
}f;

int check (friends fr, vector <int> n);
bool compare (int i, int j);

int main ()
{
	vector <vector <int> > v;
	vector <int> temp;
	vector <int> ans;
	vector <friends> s;
	int T, x;

	cin >> T;

	for (int i = 0; i < T; i ++) {
		cin >> f.n >> f.k;
		s.push_back(f);
		for (int j = 0; j < f.k; j ++) {
			cin >> x;
			temp.push_back(x);
		}
		v.push_back(temp);
		temp.clear();
	}

	for (int i = 0; i <(int)v.size(); i ++) {
		ans.push_back(check(s[i], v[i]));
		if (ans[i] != -1) {
			cout << "Scenario #" << i+1 << ":\n" << ans[i] << endl;
		} else {
			cout << "Scenario #" << i+1 << ":\nimpossible" << endl;
		}
	}

	//cin >> x;

	return 0;
}

int check (friends fr, vector <int> n)
{
	int sum = 0;
	sort (n.begin(), n.end(), compare);

	for (int i = 0; i <(int)n.size(); i ++) {
		sum += n[i];
		if (sum >= fr.n) {
			return i+1;
		}
	}
	return -1;
}

bool compare (int i, int j) {
	return (i > j);
}
