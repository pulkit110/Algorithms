#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int recaman (int k);

int main ()
{
	int x;
	vector <int> v;
	vector <int> final;

	while(true) {
		cin >> x;
		if (x == -1) {
			break;
		}
		v.push_back(x);
	}

	for (int i = 0; i < v.size (); i ++) {
		final.push_back(recaman(v[i]));
	}

	for (int i = 0; i <final.size(); i ++) {
		cout << final[i] << endl;
	}
	
	return 0;
}



int recaman (int k)
{
	vector <bool> present(5000000,false);
	int prev = 0;
	present[0] = true;
	int newnum;
	for (int i = 1; i <= k; i ++) {
		newnum = prev - i;
		if (newnum < 0 || present[newnum]) {
			newnum = prev+i;
		}
		present[newnum] = true;
		prev = newnum;
		//cout << newnum << endl;
	}

	return newnum;
	/*if (k == 0) {
		return 0;
	} else {
		int temp;
		vector <int> vec;
		temp = recaman (k-1) - k;
		if (temp < 0 || ((count(vec.begin(), vec.end(), temp)) != 1)) {
			temp = recaman (k-1) + k;
		}
		vec.push_back (temp);
		return temp;
	}*/
}
