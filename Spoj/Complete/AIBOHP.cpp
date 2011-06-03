#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <vector<int> > dp(6200, vector<int> (6200, 0));
int min_pal (string s);
int maximum (int i, int j);

int main()
{
	int T;
	string str;
//	vector <string> v;

	/*while (true) {		
		getline(cin, str, '\n');
		if(str.empty()) break;
		v.push_back(str);
	}*/

	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		//scanf("%s", str);
		cin >> str;
        cout <<	min_pal(str) << endl;
	//	v.push_back(str);
	}
	
	/*for (int i = 0; i < (int)v.size(); i ++) {
		cout <<	min_pal(v[i]) << endl;
	}*/
	return 0;
}

int min_pal (string s)
{
	//string rev_s;
	

/*	for (int i = 0; i < (int)s.length(); i ++) {
		rev_s[i] = s[s.length()-i-1];
	}*/
	int n = s.size();	
	int max = 0;
	bool flag = false;


	for (int i = 1; i <= (int)s.length(); i ++) {
		for (int j = 1; j <= n-i; j ++) {
			if (s[n - j] == s[i-1]) {
				dp[i][j] = dp[i-1][j-1]+1;						
			} else {
				dp[i][j] = maximum(dp[i-1][j], dp[i][j-1]);				
			}
			if (i+j == s.size()) {                    
				if (dp[i][j] > max) {
					max = dp[i][j];
					if (dp[i][j] == maximum(dp[i-1][j],dp[i][j-1])) {flag = true;}
					else flag = false;
				} else if (dp[i][j] == max && dp[i][j] == maximum(dp[i-1][j],dp[i][j-1])) {
                       flag = true;
                }
			}
		}
	}
	if (flag) return ((int)s.length()- 2*max - 1);
	else return ((int)s.length()- 2*max);
}

int maximum (int i, int j)
{
	if (i >= j) 
		return i;
	return j;
}