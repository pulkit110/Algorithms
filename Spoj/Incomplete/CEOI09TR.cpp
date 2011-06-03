#include <iostream>
#include <vector>

using namespace std;

struct triangle {
	int x1, x2, y1, y2;
};

bool createTriangle (triangle A, vector <int> X, vector <int> Y);

int main()
{
	triangle T;
	int K, M, x, y;
	vector <int> X;
	vector <int> Y;
	vector <triangle>  v;
	vector <bool> ans;

	cin >> K >> M;

	for (int i = 0; i < K; i ++) {
		cin >> x >> y;
		X.push_back(x);
		Y.push_back(y);
	}

	for (int i = 0; i < M; i ++) {
		cin >> T.x1 >> T.y1 >> T.x2 >> T.y2;
		v.push_back(T);
		ans.push_back(createTriangle(v[i], X, Y));
	}

	for (int i = 0; i < (int)ans.size(); i ++) {
		if (ans[i]) cout << "Y" << endl;
		else cout << "N" << endl;
	}

	
	return 0;
}

bool createTriangle (triangle A, vector <int> X, vector <int> Y)
{
	for (int i = 0; i < (int)X.size(); i ++) {
		if ( ((A.x1*Y[i] - A.y1*X[i]) < 0) && ((A.x1*Y[i] - A.y1*X[i]) < 0) ) {
			if ( (A.x2-A.x1) > 0 ) {
				if( (((A.x2-A.x1)*(Y[i]-A.y2))-((A.y2-A.y1)*(X[i]-A.x2))) < 0 ) {
					return true;
				}
			} else if ( (((A.x1-A.x2)*(Y[i]-A.y2)) - ((A.y1-A.y2)*(X[i]-A.x2))) < 0) {
					return true;
			}
		}
	}
	return false;
}
