#include <iostream>
#include <vector>

using namespace std;

int findMeetings(vector <int> Agnes, vector <int> Tom);

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		vector <int> Agnes;
		vector <int> Tom;
		int x = -1;
		while (x != 0) {
			cin >> x;
			Agnes.push_back(x);
		}
		Agnes.pop_back();
		int max = 0;
		while (true) {
			cin >> x;
			if (x==0) break;
			while (x != 0) {
				Tom.push_back(x);
				cin >> x;
			}

			int meet = findMeetings(Agnes,Tom);
			Tom.clear();
			if (meet > max) {
				max = meet;
			}
		}
		cout << max << endl;
	}
	return 0;
}

int findMeetings(vector <int> Agnes, vector <int> Tom)
{
	vector <vector <int> > meetings(Tom.size()+1, vector <int> (Agnes.size()+1,0));

	for (int i = 1; i < meetings.size(); ++i) {
		for (int j = 1; j < meetings[i].size(); ++j) {
			if (Tom[i-1] == Agnes[j-1]) {
				meetings[i][j] = meetings[i-1][j-1] + 1;
			} else {
				meetings[i][j] = (meetings[i][j-1]>meetings[i-1][j])?meetings[i][j-1]:meetings[i-1][j];
			}
		}
	}

	return meetings[meetings.size()-1][meetings[0].size()-1];
}