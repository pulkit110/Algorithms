#include <iostream>
#include <vector>
#include <string>

#define lint long long int

using namespace std;

lint solve (string s);

int main()
{
	lint T = 0;
	string T1;
	getline (cin, T1);

	for (int i = 0; i < T1.length(); ++i)
		T = T*10 + T1[i] - '0';
	string s;
	vector <lint> ans;
	
	for (lint i =0; i < T; i ++) {
		getline (cin, s, '\n');
		getline (cin, s, '\n');
		ans.push_back (solve(s));
	}

	for (lint i = 0; i < T; i ++) {
		cout << ans[i] << endl;
	}

	return 0;

}

lint solve (string s)
{
	lint ans = 0;

	int type;
	lint num1 = 0, num2 = 0;

	lint i = 0;

	while (s[i] == ' ') ++i;
	
	while (s[i] != ' ' && i < s.length()) {
		num1 = num1*10 + s[i] - '0';
		++i;
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') break;
	}


	while (s[i] == ' ') ++i;
	if (s[i] == '+') type = 1;
	else if (s[i] == '-') type = 2;
	else if (s[i] == '*') type = 3;
	else if (s[i] == '/') type = 4;
	else return ans;
	++i;
	while (s[i] == ' ') ++i;

	while (s[i] != ' ' && i < s.length()) {
		num2 = num2*10 + (s[i] - '0');
		++i;
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '=') break;
	}

	switch (type) {
		case 1: ans = num1 + num2; break;
		case 2: ans = num1 - num2; break;
		case 3: ans = num1 * num2; break;
		case 4: ans = num1 / num2; break;
	}
	
	while (i < s.length()) {
		while (s[i] == ' ' && i < s.length()) ++i;

		if (i >= s.length()) break;
		if (s[i] == '+') type = 1;
		else if (s[i] == '-') type = 2;
		else if (s[i] == '*') type = 3;
		else if (s[i] == '/') type = 4;
		else break;
		++i;
		if (i >= s.length()) break;
		while (s[i] == ' ' && i < s.length()) ++i;
		if (i >= s.length()) break;

		num1 = 0;
		while (s[i] != ' ' && i < s.length()) {
			num1 = num1*10 + s[i] - '0';
			++i;
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '=') break;
		}
		switch (type) {
		case 1: ans += num1; break;
		case 2: ans -= num1; break;
		case 3: ans *= num1; break;
		case 4: ans /= num1; break;
		}
	}

	return ans;
}