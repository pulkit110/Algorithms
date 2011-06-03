#include <iostream>
#include <cmath>

using namespace std;
void label (int x, int count);

int main()
{
	int x;
	int count = 0;

	while (cin >> x) {
		if (x == 0) {
			break;
		}
		count ++;
		label(x, count);
	}
	//while(1);
	return 0;
}

void label (int x, int count)
{
	int s;
	
	s = pow((double)x, (double)count-1);
	cout << "Case " << count << ", N = " << x << ", # of different labelings = " << s << endl;
}
