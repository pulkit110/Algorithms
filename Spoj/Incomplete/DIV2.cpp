#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void div2();

int main ()
{
	div2();
	//int x;
	//cin >> x;
	return 0;
}

void div2()
{
	int count = 0;
	vector <int> d;
	d.push_back(0);
	vector <int> m;
	vector <vector <int> > divisors;
	divisors.push_back (m);

	for (int i =1 ; i <= 1000000; i ++) {
		d.push_back (2);
		//cout << endl << i << ": ";
		float rt = sqrt((float)i);
		for (int j = i/2; j > rt; j --) {
			if (i%j == 0) {
				m.push_back (j);
				m.push_back (i/j);
				//cout << j << ", ";
				d[i] += 2;
		//		cout << j << ", " << i/j << ", ";
			}
			
		}
		if (rt == (int)rt) {
			m.push_back (rt);
			//cout << rt;
			d[i] ++;
		}
		//cout << ": " << d[i];
		divisors.push_back (m);
		
		bool flag = false;

		if (d[i] > 3) {
			flag = true;
			for (int j = 0; j < m.size(); j ++) {
				if (d[i]%d[m[j]] != 0) {
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			count ++;
			if (count % 108 == 0) {
				cout << i << endl;
			}
		}
		m.clear();
	}
}
