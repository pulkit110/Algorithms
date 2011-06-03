#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int t;

	cin >> t;
	for (int i = 0; i < t; ++i) {
		string s1;
		string s2;
		int goal1;
		int goal2;
		int max = 0;
		string winner = "";
		map <string, int> m;
		map <string, int> m1;
		for (int j = 0; j < 16; ++j) {
			cin >> s1;
			cin >> s2;
			scanf("%d", &goal1);
			scanf("%d", &goal2);
			if (goal1 > goal2) {
				m[s1] ++;
				m1[s2]--;
				if (m[s1] + m1[s1] > max) {
					max = m[s1];
					winner = s1;
				}
			} else {
				m[s2] ++;
				m[s1]--;
				if (m[s2] + m1[s2] > max) {
					max = m[s2];
					winner = s2;
				}
			}
		}
		
		/*map < string,int > :: iterator it;
		for(it = m.begin(); it != m.end(); ++ it) {
			printf("%s %d\n",((*it).first).c_str(),(*it).second);
		}*/

		cout << winner << endl;
	}

	//while(1);
	
	return 0;
}
