#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;

	string s1;
	string s2;
	int l;

//	vector <string> ans;

	for (int i = 0; i < T; ++i) {
		cin >> s1 >> s2;

		if (s1.length()<s2.length())
			l = s1.length();
		else 
			l = s2.length();

		string temp = "";
		for (int j =0; j < l; ++j) {
			if (s1[j] == '1' && s2[j] == '1') {
				temp += '1';
			} else {
				temp += '0';
			}
		}
		int k;
		for (k = temp.length()-1; k >= 0 && temp[k] == '0'; --k);	
		
		for (int j = 0; j <= k; j++) cout << temp[j];
		if (k < 0) cout << "relatively prime";
		cout << endl;
		//ans.push_back (temp);
	}

	return 0;
}