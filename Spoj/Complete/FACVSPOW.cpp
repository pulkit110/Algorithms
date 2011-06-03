#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//int binary_search (long double A[], long double x);

int main()
{
	int T;
	int y;
	long double *arr;
	arr = new long double[2720000];

	scanf("%d", &T);
 
//	int input[500000];
	
	

	arr[0] = -1.0;
	arr[1] = 0.0;

	for (int i = 2; i < 2720000; i++) {
		arr[i] = arr[i-1] + log((double)i);
	}
	for (int i = 2; i < 2720000; i++) arr[i] /= i;

	for (int i = 0; i < T; i++) {
		scanf("%d", &y);
		printf("%d\n", upper_bound(arr, arr + 2720000, log((double)y)) - arr);
	}

	//cin >> T;

	return 0;
}

/*int binary_search (long double A[], long double x)
{
	int mid;
	int first = 0;
	int last = 279999;

	if (x == A[0]) {
		return first;
	}

	if (x == A[last]/last) {
		 return last;
	}

	while ( first < last ) {
		mid = ( first + last ) / 2;

		if (x == A[mid]/mid) {
			return mid;
		} else if ( x < A[mid]/mid ) {
			last =  mid ;
		} else if ( x > A[mid]/mid ) {
			first = mid ;
		}
		if ( last - first == 1 ) {
		       return last;
		}	       
	}

	return -1; 
}*/