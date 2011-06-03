#include <iostream>
#include <vector>

using namespace std;

void findSquare (vector <int> v);
int noOfSquare(int n);

int main()
{
	int x;
	vector <int> v;

	while (true) {
		cin >> x;
		if (x == 0) {			
			break;
		}		
		v.push_back(x);	
	} 
	
	findSquare(v);

	cin >> x;

	return 0;
}

void findSquare (vector <int> v)
{
	int n;
	vector <int> s;

	for (int i = 0; i < (int)v.size(); i ++) {
		n = noOfSquare(v[i]);
		s.push_back (n);
	}

	for(int i = 0; i < (int)s.size(); i ++) {
		cout << s[i] << endl;
	}
}

int noOfSquare(int n)
{
	int count = 0;

	for(int i = 1; i <= n; i ++) {
		count += i*i;
	}

	return count;
}
