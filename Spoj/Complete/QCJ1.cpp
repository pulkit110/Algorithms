#include <iostream>
#include <vector>
#include <string>

using namespace std;

void distance (vector <string> v, int maxsize);

int main()
{
	string s;
	vector <string> v;
	int N;

	cin >> N;
	getline(cin, s,'\n');
	getline(cin, s,'\n');
	int maxsize= 0;
	
	for (int i = 0; i < N; ++ i) {
		getline(cin , s, '\n');
		int size = s.length();
		if (size >= maxsize) {
			maxsize = size;
		}
		v.push_back(s);
	}

	distance (v, maxsize);

	return 0;
}

void distance (vector <string> v, int maxsize)
{
	cout << "Total Walk Distance = " << maxsize << endl;
	int up = 0;
	int down = 0;
	int forward = 0;
	char turn = v[v.size()-1][0];

	for (int j = 0; j < maxsize; ++j) {
		for (int i = 0; i < v.size(); ++i) {
			if (j < v[i].size()) {
				if (v[i][j] == '/') {
					if (turn == '/') {
						++up;
						break;
					} else if (turn == '\\') {
						cout << "Down " << down << " steps\n";
						down = 0;
						++ up;
						turn = '/';
						break;
					} else if (turn == '_') {
						cout << "Walk " << forward << " steps\n";
						forward = 0;
						++ up;
						turn = '/';
						break;
					}
				} else if (v[i][j] == '\\') {
					if (turn == '\\') {
						++down;
						break;
					} else if (turn == '/') {
						cout << "Up " << up << " steps\n";
						up = 0;
						++down;
						turn = '\\';
						break;
					} else if (turn == '_') {
						cout << "Walk " << forward << " steps\n";
						forward = 0;
						++down;
						turn = '\\';
						break;
					}
				} else if (v[i][j] == '_') {
					if (turn == '_') {
						++forward;
						break;
					} else if (turn == '/') {
						cout << "Up " << up << " steps\n";
						up = 0;
						++forward;
						turn = '_';
						break;
					} else if (turn == '\\') {
						cout << "Down " << down << " steps\n";
						down = 0;
						++forward;
						turn = '_';
						break;
					}
				}
			}
		}
	}
	if (turn == '\\') {
		cout << "Down " << down << " steps\n";
	} else if (turn == '_') {
		cout << "Walk " << forward << " steps\n";
	} else if (turn == '/') {
		cout << "Up " << up << " steps\n";
	}
/*
	for (int j = 0; j < maxsize; ++ j) {
		if (v[i][j] == ' ') {
			if (i > 0 && j < v[i-1].length() && v[i-1][j] != ' ')
				--i;
			else if (i < v.size() && j < v[i+1].length() && v[i-1][j] != ' ')
				++i;
			else {
				return;
			}
		}
		if (v[i][j] == '/') {
			up++;
			bool flag = true;
			while (flag) {
				if (i > 0 && j+1<v[i-1].size() && v[i-1][j+1] == '/') {
					--i;
					++j;
					++ up;
				} else {
					flag = false;
					cout << "Up " << up << " steps\n";
				}
			}
			continue;
		} else if (v[i][j] == '_') {
			forward++;
			bool flag = true;
			while (flag) {
				if (j+1<v[i].size() && v[i][j+1] == '_') {
					++j;
					++ forward;
				} else {
					flag = false;
					cout << "Walk " << forward << " steps\n";
					if (i < v.size()-1)
						++i;
					else return;
				}
			}
			continue;
		} else if (v[i][j] == '\\') {
			down++;
			bool flag = true;
			while (flag) {
				if (i < v.size()-1 && j+1<v[i+1].size() && v[i+1][j+1] == '\\') {
					++i;
					++j;
					++down;
				} else {
					flag = false;
					cout << "Down " << down << " steps\n";
				}
			}
			continue;
		}
	}*/
}
