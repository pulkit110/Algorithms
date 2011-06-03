#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <algorithm>

#define MAX 1000000000

using namespace std;

bool isprime[MAX/3];

void make_primes2()
{
	int i,j,lim=sqrt((double)MAX);

	bool bit1=1,bit2;

	for(int i=5;i<=lim;i+=bit1?2:4,bit1=!bit1)
	{
		if(!isprime[i/3])
		{
			bit2=1;
			for(int j=i;;)
			{
				j+=bit2?i<<2:i<<1;
				bit2=!bit2;
				if(j>=MAX)break;
				isprime[j/3]=1;
			}
		}
	}
}

int main()
{
	make_primes2();
	//printf("%lf(s)\n",clock()/1e6);
	int count = 2;
	printf("2\n");
	isprime[0] = 1;
	for (int k = 0; 6*k+1 < 1000000000; ++k) {
		if (isprime[2*k] == 0) {
			count ++;
			if (count == 501) {
				printf("%d\n",6*k+1);
				count = 1;
			}
		}
		if (isprime[2*k+1] == 0) {
			count ++;
			if (count == 501) {
				printf("%d\n",6*k+5);
				count = 1;
			}
		}
		//cout << isprime[i] << endl;
	}

	return 0;
}

