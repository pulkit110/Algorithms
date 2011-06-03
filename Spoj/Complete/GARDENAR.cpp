#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void calculateArea(vector <double> A, vector <double> B, vector <double> C);

int main()
{
	int T;
	double a, b, c;
	vector <double> A, B, C;
	
	cin >> T;

	for (int i = 0; i < T; i ++) {
		cin >> a >> b >> c;
		a /= 10;
		b /= 10;
		c /= 10;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
	}

	calculateArea(A, B, C);

	return 0;
}

void calculateArea(vector <double> A, vector <double> B, vector <double> C)
{
	for (int i = 0; i < (int)A.size(); i++) {
		
		
		double m = (A[i]*A[i]*A[i]*A[i]) + (B[i]*B[i]*B[i]*B[i]) + (C[i]*C[i]*C[i]*C[i]);
		double n = (A[i]*A[i]) + (B[i]*B[i]) + (C[i]*C[i]);

		
		double temp = (12.0*n*n - 24.0*m);
	
		
		temp = sqrt(temp)*100;

		double side = (2.0*n*100.0 + temp)/4.0;		//3(a^4+b^4+c^4+s^4) = (a^2+b^2+c^2+s^2)^2

		double area = 1.73205081*side/4.0;

		printf("%.2lf\n", area);
	}
}