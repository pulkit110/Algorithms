#include <iostream>
#include <vector>
#include <cmath>

#define lint long long

using namespace std;

int main()
{
	int T, k;
	lint n,terms,sum,remaining,start;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		cin >> n >> k;
		sum = 0;
		vector <lint> coins(k,0);
		terms = (-1+sqrt((double)1.0+8*n))/2.0;
		terms /= k;

		for (lint j = 1; j <= k; ++j) {
			coins[j-1] = terms/2.0*(2*j+(terms-1)*k);
			sum += coins[j-1];
		}
		remaining = n - sum;
		
		start = terms*k+1;
		
		for (lint j = 1; j <= k; ++j) {
			if (remaining-start >= 0) {
				coins[j-1] += start;
			} else {
				coins[j-1] += remaining;
				break;
			}
			remaining -= start;
			start++;
		}
		for (int j = 0; j < k; ++j) {
			cout << coins[j] << " ";
		}
		cout << endl;
	}


	return 0;
}
