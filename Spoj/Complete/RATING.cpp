#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct coder {
	int openRating;
	int highRating;
	int index;	
};

struct rank {
	int openRating;
	int highRating;
	int rating;
	int count_leftChild;
	int count_rightChild;	
	struct rank *left;
	struct rank *right;
	int index;
};

bool compare (coder c1, coder c2) {
	if (c1.openRating == c2.openRating) {
		return (c1.highRating < c2.highRating);
	}
	
	return (c1.openRating < c2.openRating);
}

int main () 
{
	int T;
	//coder *p;
	cin >> T;

	vector <coder> v;
	vector <int> ans(T);

	coder c;
	for (int i = 0; i < T; ++i) {
		cin >> c.openRating >> c.highRating;
		c.index = i;
		v.push_back(c);
	}
	
	sort (v.begin(), v.end(), compare);

	struct rank *root, *temp, *parent;

	root = new rank;
	
	root -> openRating = v[0].openRating;
	root -> highRating = v[0].highRating;
	root -> count_leftChild = 0;
	root -> count_rightChild = 0;
	root -> left = NULL;
	root -> right = NULL;
	root -> rating = 0;
	root -> index = v[0].index;

	ans[v[0].index] = 0;
	

	for (int i = 1; i < (int)v.size(); ++i) {
		temp = root;		
		bool flag = false;;
		while (temp != NULL) {
			parent = temp;

			if (v[i].highRating > temp -> highRating) {
				temp -> count_rightChild ++;
				temp = temp -> right;
				flag = true;
				if (temp != NULL) {
					temp -> rating = parent -> rating + temp -> count_leftChild + 1;					
				}
			} else if (v[i].highRating < temp -> highRating) {
				temp -> count_leftChild ++;
				temp -> rating ++;
				flag = false;
				//ans[temp -> index] = temp -> rating;
				temp = temp -> left;				
				if (temp != NULL) {
					temp -> rating = parent -> rating - 2 - temp-> count_rightChild;
				}
			} else {
				if (v[i].openRating == temp -> openRating) {
					temp -> count_leftChild ++;
					temp -> rating ++;
					temp = temp -> left;
					flag = false;
					if (temp != NULL) {
						temp -> rating = parent -> rating - 2 - temp-> count_rightChild;
					}
				} else {
					temp -> count_rightChild ++;
					temp = temp -> right;
					flag = true;
					if (temp != NULL) {
					temp -> rating = parent -> rating + temp -> count_leftChild + 1;					
					}
				}
			}
		}

		temp = new rank;
		temp -> count_leftChild = 0;
		temp -> count_rightChild = 0;
		temp -> highRating = v[i].highRating;
		temp -> openRating = v[i].openRating;
		temp -> left = NULL;
		temp -> right = NULL;
		//temp -> rating = 0;
		temp -> index = v[i].index;
		if (flag) {
			temp -> rating = parent -> rating + 1;
			parent -> right = temp;
		} else {
			temp -> rating = parent -> rating - 1;
			parent -> left = temp;
		}

		ans[v[i].index] = temp -> rating;
	}

	for (int i = 0; i < (int)ans.size(); ++i) {
		cout << ans[i] << endl;
	}

	//cin >> T;
	return 0; 
}
