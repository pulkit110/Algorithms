#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct point {
	int x;
	int y;
};

int main()
{
	int n;
	cin >> n;

	int x, y;
	vector <point> points;
	point temp;

	for (int i  =0; i < n; ++i) {
		cin >> x >> y;
		temp.x = x;
		temp.y = y;
		points.push_back (temp);
	}

	float max = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			float dist = (points[i].x-points[j].x)*(points[i].x-points[j].x) + (points[i].y-points[j].y)*(points[i].y-points[j].y);
			if (max < dist) {
				max = dist;
			}
		}
	}

	max = sqrt(max);
	max = floor (max*100 + 0.5)/100;
	printf("%.2f",max);

	return 0;
}
