#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct instruction {
	string s;
	bool flag;
	int a, b;
};

int main ()
{
	int T, N, x1, x2, x3;
	scanf("%d", &T);

//	int M[10][10];
	vector <vector <int> > M(10010, vector<int> (10010, 0));
	vector <int> n1;
	vector <int> n2;
	instruction order;

	for (int k = 0; k < T; ++k) {
		scanf("%d", &N);
		for (int i = 0; i < N-1; ++i) {
			scanf("%d %d %d", &x1, &x2, &x3);
			M[x1][x2] = x3;
			n1.push_back(x1);
			n2.push_back(x2);
			//c.push_back(x3);
		}

		while (true) {
			cin >> order.s;
			if (order.s[0] == 'D') {
				break;
			}
			scanf("%d %d %d", &order.a, &order.b);
			if (order.s[0] == 'Q') {
				printf("%d\n", M[order.a][order.b]);
				/*for (int j = 0; j < (int)c.size(); ++j) {
					if ((order.a == n1[j]) && (order.b == n2[j])) {
						printf("%d\n", c[j]);
						break;
					}
				}*/				
			} else {
				M[n1[order.a-1]][n2[order.a-1]] = order.b;
				//c[order.a-1] = order.b;
			}
		}
		n1.clear();
		n2.clear();
		//c.clear();
	}

	return 0;
}

