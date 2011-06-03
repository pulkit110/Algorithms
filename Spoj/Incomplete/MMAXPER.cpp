#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int x1, x2, lastmax, lastmin;

	cin >> x1 >> x2;
	int sum1, sum2, sum3;
	sum1 = sum2 = sum3 = x1 + x2;
	if (x1 > x2) {lastmax = x1;lastmin = x2;}
	else {lastmax = x2; lastmin = x1;}
	bool boolLarge = false;

	int max, min;

	for (int i = 1; i < T; ++i) {
		cin >> x1 >> x2;
		if (x1 > x2) {max = x1;min = x2;}
		else {max = x2; min = x1;}
		sum1 += max + min;

		
		if (boolLarge) {
			if (min > lastmax) {
				sum2 = sum1 + min - 2*lastmax;
			} else {
				sum2 = sum1 - min;
			}
		} else {
			if (lastmin > min) {
				sum2 = sum1 - min;
			} else {
				sum2 = sum1 + min-2*lastmin;
			}
		}

		if (boolLarge) {
			if (max > lastmax) {
				sum3 = sum1 + max - 2*lastmax;
			} else {
				sum3 = sum1 - max;
			}
		} else {
			if (lastmin > max) {
				sum3 = sum1 - max;
			} else {
				sum3 = sum1 + max-2*lastmin;
			}
		}

		if (sum2 > sum3) {sum1 = sum2; boolLarge = false;}
		else {sum1 = sum3; boolLarge = true;}

		/*if (i%2 != 0) {
			if (x1 > x2) {max = x1;min = x2;}
			else {max = x2; min = x1;}
			sum1 += max + min;
			sum2 += max + min;
			if (lastmin > max) {
				sum1 -= max;
			} else {
				sum1 += max-lastmin;
			}
			if (min > lastmax) {
				sum2 += min - lastmax;
			} else {
				sum2 -= min;
			}
		} else {
			if (x1 > x2) {max = x1;min = x2;}
			else {max = x2; min = x1;}
			sum1 += max + min;
			sum2 += max + min;
			if (lastmin > max) {
				sum2 -= max;
			} else {
				sum2 += max-lastmin;
			}
			if (min > lastmax) {
				sum1 += min - lastmax;
			} else {
				sum1 -= min;
			}
		}*/
		lastmin = min;
		lastmax = max;
		//cout << endl << "Step " << i << ", Sum is " << sum1 << endl << endl;
	}

	if (T > 1) {
		if (boolLarge) {sum1 -= lastmax;}
		else {sum1 -= lastmin;}
	}

	cout << (sum1) << endl;
	return 0;
}
