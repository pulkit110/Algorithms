#include <iostream>
#include <string>

using namespace std;


int main()
{
	string s;
	string t;

	while (!cin.eof()) {
		cin >> s;
		t.clear();
		for (int i = s.length()-1; i >= 0; --i) {
			t += s[i];
		}
		if (s == t) {cout << s << endl;continue;}

		int count2 = 0;
		int count1 = 0;
		int pos = s.length()-1;
		int store = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == t[count2]) {
				store = i;
				//cout << i << endl;
				count2 ++;
				if (i==s.length()-1) {
					pos = s.length()-count2-1;
					break;
				}
				continue;
			} else if (s[i] != t[count2]) {
				if (count2>0) i = store+1;
				count2 = 0;
			}
		}
		for (int i = pos; i >= 0; --i) {
			s += s[i];
		}
		cout << s << endl;
		
	}

	return 0;
}
