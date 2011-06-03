#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct person {
	int at, tickets;
	int start, end;
};

struct counter_time {
	int start_time;
	int end_time;
};

void time_spent(int N, int P, vector<person> v);
int main()
{
	person p;
	int C, N, P;
	vector <person> v;

	cin >> C;

	for (int i = 0; i < C; ++i) {
		cin >> N >> P;
		for (int j = 0; j < P; ++j) {
			cin >> p.at >> p.tickets;
			p.start = 0;
			p.end = 0;
			v.push_back(p);
		}
		time_spent(N, P, v);
		v.clear();
	}
//	while(true);
	return 0;
}

void time_spent(int N, int P, vector<person> v)
{
	long long int time = 0;
	long long int global_time = 0;
	counter_time ct;
	ct.start_time = 1;
	ct.end_time = 1;
	vector <counter_time> c(N, ct);

	int min = INT_MAX;
	int min_index = -1;
	int j;
	for (int i = 0; i < (int)v.size(); ++i) {
		min = INT_MAX;
		for (j = 0; j < N; ++j) {
			if (v[i].at >= c[j].end_time) {
				c[j].end_time = v[i].at+5+v[i].tickets;
				global_time += 5+v[i].tickets;
				break;
			}
			if (c[j].end_time < min) {
				min = c[j].end_time;
				min_index = j;
			}
		}
		if (j >= N && min_index != -1) {
//			if (v[i].at <= min)
			v[i].start = min;
			global_time += v[i].start - v[i].at;
			time = 5 + v[i].tickets;
			global_time += time;	
			v[i].end = v[i].start + time;
			c[min_index].end_time = v[i].end;			
		}
	}
	cout << global_time << endl;
}