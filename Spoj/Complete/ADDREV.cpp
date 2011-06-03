#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T, n1, n2,n3,n4;

	cin >> T;

	for (int i = 0; i < T; ++i) {
		cin >> n1 >> n2;
		n3 = n4 = 0;
		while (n1 != 0) {
			n3 = n3*10 + n1%10;
			n1 /= 10;
		}
		while (n2 != 0) {
			n4 = n4*10 + n2%10;
			n2 /= 10;
		}
		n1 = n3+n4;
		n2 = 0;
		while (n1 != 0) {
			n2 = n2*10 + n1%10;
			n1 /= 10;
		}
		cout << n2 << endl;
	}
}
