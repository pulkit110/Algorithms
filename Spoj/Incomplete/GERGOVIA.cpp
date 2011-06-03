#include <iostream>
#include <vector>

using namespace std;

void work (vector <int> v);

int main()
{
	int x, y;
	vector <int> V;

	while (cin >> x) {
		if (x == 0) {
			break;
		}
		for (int i = 0; i < x; ++i) {
			cin >> y;
			V.push_back(y);
		}
		work(V);
		V.clear();
	}
	return 0;
}
int abs(int a)
{
	if (a < 0) return -a;
	else return a;
}

void work (vector <int> v)
{
	int amount = 0;

	for (int i = v.size()-1; i >= 0; --i) {
		if (v[i] > 0) {
			if (i != v.size()-1) {
				for (int j = v.size()-1; j > i; --j) {
					if (v[j] < 0) {
						if (v[i] >= abs(v[j])) {
							v[i] += v[j];
							amount += abs(v[j])*(abs(i-j));
							v[j] = 0;
						} else {
							v[j] += v[i];
							amount += abs(v[i])*(abs(i-j));
							v[i] = 0;
							break;
						}
					}
				}
			}
			if (v[i] != 0) {
				for (int j = i-1; j >= 0; --j) {
					if (v[j] < 0) {
						if (v[i] >= abs(v[j])) {
							v[i] += v[j];
							amount += abs(v[j])*(abs(i-j));
							v[j] = 0;
						} else {
							v[j] += v[i];
							amount += abs(v[i])*(abs(i-j));
							v[i] = 0;
							break;
						}
					}
				}				
			}
		}
	}

	cout << amount << endl;

}
