#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string s;

    int t;

    cin >> t;

cin.ignore(1000, '\n');

    for (int i = 0; i < t; ++i) {
    	getline (cin, s);
    	string word;
    	for (int j = 0; j < s.length(); ++j) {
    	    if (!isalnum(s[j])) {
    	    	
    	    	if (word == "8") {
    	    	    cout << "ate";
                } else 
    	    	if (word == "w8") {
    	    	    cout << "wait";
                } else
    	    	if (word == "gr8") {
    	    	    cout << "great";
                } else 
    	    	if (word == "4") {
    	    	    cout << "for";
                } else
    	    	if (word == "b4") {
    	    	    cout << "before";
                } else {
                    cout << word;
                }

    	    	word.clear();
    	    	cout << s[j];
            } else {
            	word += s[j];
            }
        }
        if (word == "8") {
    	  	    cout << "ate";
                } else 
    	    	if (word == "w8") {
    	    	    cout << "wait";
                } else
    	    	if (word == "gr8") {
    	    	    cout << "great";
                } else 
    	    	if (word == "4") {
    	    	    cout << "for";
                } else
    	    	if (word == "b4") {
    	    	    cout << "before";
                } else {
                    cout << word;
                }


        cout << endl;
    }
}