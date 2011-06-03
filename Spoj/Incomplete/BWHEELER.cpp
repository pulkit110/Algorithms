#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string s1, string s2)
{
	int l = s1.length();
	//while (l-1>=0 && s1[l-1] == s2[l-1]) l--;
	//if (l-1 >= 0)
		return s1[l-1] < s2[l-1];
	//else return 0;
}


struct elem {
	int ind;
	int rank;
	char ch;
};

bool compareChar(elem l1, elem l2)
{
	return (l1.ch < l2.ch);
}

bool compareind(elem l1, elem l2)
{
	return (l1.ind <= l2.ind);
}
int main()
{
	int n = -1;
	bool flag = true;
	string s;
	vector <string> mat;
	vector <string> newmat;
	vector <elem> lst;
	elem temp = {0,0,0};
	while (flag) {
		cin >> n;
		if (n == 0) {flag = false;break;}
		cin >> s;
		mat.assign(s.length(),"");
		newmat = mat;
		lst.assign(s.length(),temp);
		
		for (int i = 0; i < s.length(); ++i) {
			lst[i].ind = i;
			lst[i].ch = s[i];
		}
		
		sort(lst.begin(), lst.end(), compareChar);
		for (int i = 0; i < s.length(); ++i) {
			lst[i].rank = i;
		}
		sort(lst.begin(), lst.end(), compareind);

		for (int j = 0; j < s.length(); ++j) {
			for (int i = 0; i < s.length(); ++i) {
				newmat[lst[i].rank] = mat[i] + s[i];
			}
			mat = newmat;
		}

		for (int i = s.length()-1; i >= 0; --i)
			cout << mat[n-1][i];

		cout << endl;
	}
	return 0;
}
