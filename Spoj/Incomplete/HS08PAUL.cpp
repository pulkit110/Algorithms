#include <iostream>
#include <vector>
#include <cmath>

#define lint unsigned long long

using namespace std;

bool isprime[10000050]={0};
bool isans[10000050]={0};
lint sum[10000050]={0};
void sieve(lint N);
void noOfPrimes2(lint n);

 int main()
{
	for (lint i = 0; i < 10000050; ++i) {
		isprime[i] = false;
		isans[i] = false;
		sum[i] = 0;
	}
	sieve (10000050);
	isprime[0] = 1;
	isprime[1] = 1;
	noOfPrimes2(10000050);
	lint ans[100000];
	for (lint i = 2; i < 10000050; ++i) {
		if (isans[i] == true) {
			sum[i] = sum[i-1] + 1;
		} else {
			sum[i] = sum[i-1];
		}
	}

	lint T, n;

	scanf ("%ld", &T);

	for (lint i = 0; i < T; ++i) {
		scanf("%ld", &n);
		ans[i] = sum[n];
	}

	for (lint i = 0; i < T; ++i) {
		printf("%d\n", ans[i]);
	}

	return 0;
}

void sieve(lint N)   
{   
  lint i,j;
  
  for (i=4;i<=N;i+=2)   
	   isprime[i]=1;   
  for (i=3;i*i<=N;i+=2)   
	   if (!isprime[i])  
	   {
	      for (j=i*i;j<=N;j+=2*i)   
	          isprime[j]=1;   
	   }
}

void noOfPrimes2(lint n)
{
	lint i, j, temp1, temp2;
	i = j = 1;

	lint rt = sqrt((double)n);
	for (; i <= rt; ++i) {
		for (j = i; j <= rt; ++j) {
			temp1 = i*i + j*j*j*j;
			temp2 = i*i*i*i + j*j;
			if (temp1 <= n) {
				if (!isprime[temp1]) {
					isans[temp1] = true;
				}
			} 
			if (temp2 <= n) {
				if (!isprime[temp2]) {
					isans[temp2] = true;
				}
			} 
			if (temp1 > n && temp2 > n) {
				break;
			}			
		}
	}
}
