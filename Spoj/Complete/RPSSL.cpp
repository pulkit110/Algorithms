#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() 
{
	int T;
	scanf("%d", &T);
	//cin >> T;

	int r1, r2, r3, r4, r5;
	int s1, s2, s3, s4, s5;
	double w, l, t, p, S1, S2, S3;
	for (int i = 0; i < T; ++i) {
		scanf("%d", &r1);
		scanf("%d", &r2);
		scanf("%d", &r3);
		scanf("%d", &r4);
		scanf("%d", &r5);
		scanf("%d", &s1);
		scanf("%d", &s2);
		scanf("%d", &s3);
		scanf("%d", &s4);
		scanf("%d", &s5);
		//cin >> r1 >> r2 >> r3 >> r4 >> r5;
		//cin >> s1 >> s2 >> s3 >> s4 >> s5;

		w = r1*(s2+s4) + r2*(s3+s4) + r3*(s1+s5) + r4*(s3+s5) + r5*(s1+s2);
		l = r1*(s3+s5) + r2*(s1+s5) + r3*(s2+s4) + r4*(s1+s2) + r5*(s3+s4);
		t = r1*s1 + r2*s2 + r3*s3 + r4*s4 + r5*s5;
		if (w == 0 || l == 10000 || t == 10000) {
			printf("0\n");
//			cout << "0" << endl;
			continue;
		}
		w /= 10000.0;
		l /= 10000.0;
		t /= 10000.0;
		S1 = 1.0/(1.0-t);
		S2 = t/((1.0-t)*(1.0-t));
		S3 = t*(1.0+t)/((1.0-t)*(1.0-t)*(1.0-t));
		p = w*w*(S1 + S2 + l*(S1*2 + S2*3 + S3));
		p *= 100;
		printf("%.0f\n", p);
		//cout << (int)(p*100+0.5) << endl;
	}
	return 0;
}

