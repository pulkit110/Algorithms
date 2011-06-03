#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct neighbour {
	int city1;
	int city2;
};

neighbour n;
vector <neighbour> d;

void check (vector <vector<int> > v);
bool compare (neighbour n1, neighbour n2);
bool compare1 (neighbour n1, neighbour n2);
void print ( vector <neighbour> d);

int main()
{
	int T;
	int N;
	int x;
	vector <int> temp;
	vector <vector<int> > v;
	vector <vector<neighbour> > ans;
	cin >> T;

	for (int i = 0; i < T; i ++) {
		cin >> N;
		for (int j = 0; j < N; j ++) {
			for (int k = 0; k < N; k ++) {
				cin >> x;
				temp.push_back(x);
			}
			v.push_back(temp);
			temp.clear();
		}
		check(v);
		ans.push_back (d);
		d.clear();
		v.clear();
	}


	for (int i = 0; i < T; i ++) {
		cout << endl;
		print(ans[i]);		
	}
	//cin >> T;
	
	return 0;
}

void print ( vector <neighbour> d)
{
	vector <neighbour> temp1;
	vector <neighbour> ans;
	neighbour tempneighbour;

	sort (d.begin(), d.end(), compare1);

	for (int i = 0; i < (int)d.size(); i ++) {
		if (d[i].city1>d[i].city2) {
			tempneighbour.city2 = d[i].city1;
			tempneighbour.city1 = d[i].city2;
			temp1.push_back(tempneighbour);
			int count = 0;
			for (int j = 0; j < temp1.size(); ++j) {
				if (compare(tempneighbour,temp1[j])) {
					count ++;
				}
			}
			if (count < 2 )
				cout << d[i].city2 << " " << d[i].city1 << endl;
		} else {
			tempneighbour.city2 = d[i].city2;
			tempneighbour.city1 = d[i].city1;
			temp1.push_back(tempneighbour);
			int count = 0;
			for (int j = 0; j < temp1.size(); ++j) {
				if (compare(tempneighbour,temp1[j])) {
					count ++;
				}
			}
			if (count < 2 )
				cout << d[i].city1 << " " << d[i].city2 << endl;
		}
	}
}
void check (vector <vector<int> > v)
{
	for (int i = 0; i < v.size(); i ++) {
		int minIndex = 999999;
		int minValue = 999999;
		for (int j = 0; j < v[0].size(); j ++) {
			if ( i != j) {
				if (v[i][j] < minValue) {
					minIndex = j;
					minValue = v[i][j];
				}
			}
		}
		n.city1 = i + 1;
		n.city2 = minIndex + 1;
		d.push_back(n);
	}
}

bool compare (neighbour n1, neighbour n2)
{
	if (n1.city1 == n2.city1 && n1.city2 == n2.city2)
		return true;
	return false;
}

bool compare1 (neighbour n1, neighbour n2)
{
	if (n1.city1 > n1.city2) {
		int temp = n1.city1;
		n1.city1 = n1.city2;
		n1.city2 = temp;
	}

	if (n2.city1 > n2.city2) {
		int temp = n2.city1;
		n2.city1 = n2.city2;
		n2.city2 = temp;
	}

	if (n1.city1 == n2.city1)
		return (n1.city2<n2.city2);
	else 
		return (n1.city1<n2.city1);
}
