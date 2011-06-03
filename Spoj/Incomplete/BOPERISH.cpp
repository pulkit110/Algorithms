#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare (int x, int y) {
	return (x > y);
}

int main()
{
	int t, c, i;
	vector <int> v;
	bool flag = false;
		
	while(true) {
		cin >> t;
		if (t == 0) {
			break;
		}
		for (int j = 0; j < t; ++j) {
			cin >> c;
			v.push_back(c);
		}
		sort(v.begin(), v.end(), compare);
		for (i = 0; i < t; ++i) {
			if (v[i] < i+1) {
				flag = true;
				cout << v[i] << endl;
				break;
			}
		}
		if (!flag) {
			cout << i << endl;
		}
		i = 0;
		v.clear();
	}

	//cout << "SA" << endl;
	//while(1);
	return 0;
}
