#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//int maxSubSum( vector <int> a );

int main()
{
	int M, N,x,y;
	vector <int> a;

	cin >> N;
	for (int j = 0; j < N; ++j) {
		cin >> x;
		a.push_back(x);
	}

	cin >> M;
	int maxSum, thisSum, seqStart, seqEnd;
	for (int i = 0; i < M; ++i) {
		cin >> x >> y;
		x --; y--;
		maxSum = INT_MIN;
		thisSum = seqStart = seqEnd = 0;

		for( int i = x, j = x; j <= y; j++ )
		{
			thisSum += a[ j ];

			if( thisSum > maxSum )
			{
				maxSum = thisSum;
				seqStart = i;
				seqEnd   = j;
			}
			if( thisSum < 0 )
			{
				i = j + 1;
				thisSum = 0;
			}
		}

		cout << maxSum << endl;

	}
	
	return 0;
}
