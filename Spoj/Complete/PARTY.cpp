#include <iostream>

#include <vector>

#include <algorithm>



using namespace std;



struct party {

	int weight;

	int fun;

};



//void MaximizeFun(vector <int> weight, vector <int> fun, int W, int N);

void MaximizeFun(vector <party> parties, int W, int N);



bool compare(party p1, party p2)

{

	if (p1.fun == p2.fun) {

		return (p1.weight < p2.weight);

	}

	return (p1.fun > p2.fun);

}

int main()

{

	int W, N, w, f;

	bool flag = true;

//	vector <int> weight;

//	vector <int> fun;

	vector <party> parties;

	party temp;

	while (flag) {

		cin >> W >> N;

		if (W==0 && N==0) {

			flag = false;break;

		}

		for (int i = 0; i < N; ++i) {

			cin >> temp.weight >> temp.fun;

			parties.push_back(temp);

			//weight.push_back(w);

			//fun.push_back(f);

		}

		MaximizeFun(parties, W, N);

		parties.clear();

		//weight.clear();

		//fun.clear();

	}



	return 0;

}



//void MaximizeFun(vector <int> weight, vector <int> fun, int W, int N)

void MaximizeFun(vector <party> parties, int W, int N)

{

	sort(parties.begin(), parties.end(), compare);

	vector <vector <int> > A (N+1, vector<int> (W+1,0));

	vector <vector <int> > w (N+1, vector<int> (W+1,0));



	for (int i = 1; i <= N; ++i) {

		for (int j = 1; j <= W; ++j) {

			if (parties[i-1].weight>j) {

				A[i][j] = A[i-1][j];

				w[i][j] = w[i-1][j];

			} else {

				if (A[i-1][j] > parties[i-1].fun + A[i-1][j-parties[i-1].weight]) {

					A[i][j] = A[i-1][j];

					w[i][j] = w[i-1][j];

				} else if (A[i-1][j] == parties[i-1].fun + A[i-1][j-parties[i-1].weight]) {

					A[i][j] = A[i-1][j];

					w[i][j]	= min(w[i-1][j],parties[i-1].weight + w[i-1][j-parties[i-1].weight]);

				} else {

					A[i][j] = parties[i-1].fun + A[i-1][j-parties[i-1].weight];

					w[i][j] = parties[i-1].weight + w[i-1][j-parties[i-1].weight];

				}

			}

		}

	}

	cout << w[N][W] << " " << A[N][W] << endl;

}

