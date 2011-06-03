#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime[500000] = {0};
short int isprod[500000] = {0};
void sieve(int N)   
{   
     int x=sqrt((double)N),i,j;
     
     for (i=4;i<=N;i+=2)   
         isPrime[i]=1;   
     for (i=3;i<=x;i+=2)   
         if (!isPrime[i])  
         {
            for (j=i*i;j<=N;j+=2*i)   
                isPrime[j]=1;   
         }
} 

int main()
{
	sieve(500000);
	isPrime[0] = 1;
	isPrime[1] = 1;

	vector <int> primes;
	
	for (int i = 2; i < 500000; ++i) {
		if (isPrime[i] == 0) primes.push_back(i);
	}
	int psz = primes.size();
   int no = 0;
    for (int i = 50; i <= 999927; ++i) {
        int p = 1;
		int divCount = 0;
		bool flagPrimes = true;
		int lastProd = 0;
		for (int j = 0; j < psz && primes[j] <= i/2; ++j) {
			int num = i;
			if (num%primes[j] == 0) {
				int count = 0;
               while (num%primes[j]==0) {
//                     cout << j << " * ";
                     num /= primes[j];
                     count ++;
               }
               
               divCount++;
			   if (divCount>2) {flagPrimes = false;break;}
			   
               p *= (count+1);
               if (lastProd == 0) lastProd = count+1;
               else if (lastProd == count+1) {divCount = -1; flagPrimes = false; break;}
               if (isPrime[count+1] != 0 && divCount > 1) {flagPrimes = false;divCount = -1; break;}
			   if (isPrime[count+1] != 0) {flagPrimes = false;}


			}
		}
		if ((divCount == 2) && (flagPrimes == true)) {
                 isprod[p] = 1;
				if (no == 0) {
					printf("%d\n", i);// << endl;
				}
				no++;
				if (no == 9) no = 0;
          } /*else if ((divCount == 1) && (flagPrimes == false)) {
                 if (isprod[p] == 1) {
                if (no == 0) {
					printf("%d\n", i);// << endl;
				}
				no++;
				if (no == 9) no = 0;
        } else if (isprod[p] == 0) {
            bool flag = false;
			int psqt = sqrt((double)p);
			for (int j = 0; j < psz && primes[j] <= psqt; ++j) {
				if ((p%primes[j] == 0) && (p/primes[j] != primes[j]) && (isPrime[p/primes[j]]==0)) {
					if (no == 0) {
						printf("%d\n", i);// << endl;
					}
					no++;
					if (no == 9) no = 0;
					isprod[p] = 1;
					flag = true;
					break;
				}
			}
			if (!flag) isprod[p] = -1;
        }
          }*/

    }

	return 0;
}

