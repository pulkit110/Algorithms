#include <iostream>
#include <vector>

using namespace std;
#define lint long long int

void watermelons (vector <vector<char> > v, lint H);

int main()
{
	int N;
	lint H;
	char c;
	vector <char> temp;
	vector <vector<char> > v;

	cin >> N >> H;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			/*if (i == j) {
				temp.push_back('-1');
				continue;
			}*/
			cin >> c;
			temp.push_back(c);
		}
		v.push_back(temp);
		temp.clear();
	}

	 watermelons(v, H);

	 return 0;
}

void watermelons (vector <vector<char> > v, lint H)
{
	int size = v.size();
	lint t = 0;
	vector <lint> thrown(size);
	vector <lint> prev_thrown(size);

	for (int j = 0; j < size; ++j) {
		if (v[0][j] == '1') {
			thrown[j] = 1;
			t += 1;
		} else {
			thrown[j] = 0;
		}
	}
	prev_thrown = thrown;
	H--;
	thrown.assign(size, 0);
	
	while (H--) {
		for (int i = 0; i < size; ++i) {	
			for (int j = i+1; j < size; ++j) {
				if (v[i][j] == '1') {
					if (prev_thrown[i]%2!= 0) {
						thrown[j] += 1;
						t += 1;					
					} else {
						thrown[j] += 2;
						t += 2;
					}
					if (prev_thrown[j]%2!= 0) {
						thrown[i] += 1;
						t += 1;					
					} else {
						thrown[i] += 2;
						t += 2;
					}
				}
			}
		}
		prev_thrown = thrown;
		thrown.assign(size, 0);
	}
	
	cout << t << endl;
}	
