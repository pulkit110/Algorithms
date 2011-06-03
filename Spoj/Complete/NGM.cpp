#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	if (s[s.length()-1] == '0') {
		cout << "2";
	}
	else {
		cout << "1" << endl << s[s.length()-1];
	}
	cout << endl;
	return 0;
}
