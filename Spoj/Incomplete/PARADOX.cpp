#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct state {
	int X;
	string str;
};

bool compare (state s1, state s2)
{
	if (s1.X == s2.X && s1.str == s2.str) {
		return true;
	} else 
		return false;
}

string check (vector<state> v);

int main ()
{
	int N;
	state s;
	vector <string> final;
	vector <state> temp;
	vector <vector<state> > v;

	while (true) {
		cin >> N;
		if (N == 0) {
			break;
		}
		for (int i = 0; i < N; i ++) {
			cin >> s.X >> s.str;
			temp.push_back(s);
		}
		v.push_back(temp);
		temp.clear();
	}
	
	for (int i = 0; i < (int)v.size(); i ++) { 
		cout << check(v[i]) << endl;
	}

	return 0;
}

string check (vector<state> v)
{
	int index;
	string text;
	vector <state> temp;

	temp = v;

	for (int i = 0; i <= (int)temp.size(); i ++) {
		index = temp[i%temp.size()].X;
		text = temp[i%temp.size()].str;
			if (text == "false") {
				if (temp[index-1].str == "false") {
					temp[index-1].str = "true";
				} else {
					temp[index-1].str = "false";
				}
			}
	}

	if (equal (temp.begin(), temp.end(), v.begin(), compare)) {
		string s = "NOT PARADOX";
		return s;
	} else {
		string s = "PARADOX";
		return s;
	}
}			
