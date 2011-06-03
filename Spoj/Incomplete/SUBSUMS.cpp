#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector <int> v;
void Sum (long int s, long int k);

long long int cnt = 0;
long long int x1, x2;

int main ()
{
	long long int N, temp;
	int y;
	
	cin >> N >> x1 >> x2;

	if (x1 > x2) {
		temp = x1;
		x1 = x2;
		x2 = temp;
	}

	for ( int i = 0; i < N; i ++ ) {
			scanf("%d", &y);
			v.push_back(y);
	}
	long int s = 0;

	Sum(s, 0);

	int a = 0;
	if (a >= x1 && a <= x2) {
		cnt ++;
	}

	cout << cnt << endl;


	return 0;
}

void Sum (long int s, long int k)
{

	if (s + v[k] >= x1 && s+v[k] <= x2) {
		cnt ++;
	}
	
	if (k < v.size()-1) {
		Sum (s+v[k], k+1);
	}

//	x[k] = false;

	if (k < v.size()-1) {
		Sum (s, k+1);
	}
}
