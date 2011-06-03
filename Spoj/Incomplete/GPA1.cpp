#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

float GPA1 (vector <string> subjects);
int totalMarks (float mark);

int main(){
    
    int t, credit;
    float creditSum = 0.0;
    string mark;
    float GPA;
    cin >> t;
    
    
    float total1, total2, total3, total4, total5, total6;
    
    vector <int> credits;
    vector <string> sub1;
    vector <string> sub2;
    vector <string> sub3;
    vector <string> sub4;
    vector <string> sub5;
    vector <string> sub6;
    
    for (int i = 0; i < t; ++i) {
        creditSum = 0;
         
        credits.clear();
        sub1.clear();
        sub2.clear();
        sub3.clear();
        sub4.clear();
        sub5.clear();
        sub6.clear();
        
        for (int j = 0; j < 6; ++j) {
            cin >> credit;
            creditSum += credit;
            credits.push_back(credit);
        }
        
        for (int k = 0; k < 5; ++k) {
                cin >> mark;
                sub1.push_back(mark);
        }
         
        for (int k = 0; k < 5; ++k) {
                cin >> mark;
                sub2.push_back(mark);
        }
        
        for (int k = 0; k < 5; ++k) {
                cin >> mark;
                sub3.push_back(mark);
        }
        
        for (int k = 0; k < 5; ++k) {
                cin >> mark;
                sub4.push_back(mark);
        }
        
        for (int k = 0; k < 5; ++k) {
                cin >> mark;
                sub5.push_back(mark);
        }
        
        for (int k = 0; k < 5; ++k) {
                cin >> mark;
                sub6.push_back(mark);
        }                      
        
        
      //  for (int i = 0; i < 5; i++) {
         //   cout << sub1[i] << " " << sub2[i] << " " << sub3[i] << " " << sub4[i] << " " << sub5[i] << " " << sub6[i] << " "; cout << endl;}
        
        total1 = GPA1(sub1);
        total2 = GPA1(sub2);
        total3 = GPA1(sub3);
        total4 = GPA1(sub4);
        total5 = GPA1(sub5);
        total6 = GPA1(sub6);
        
       // cout << total1 << " " << total2 << " " << total3 << " " << total4 << " " << total5 << " " << total6 << " "; 
        
        if (total1 == 0.0 || total2 == 0.0 || total3 == 0.0 || total4 == 0.0 || total5 == 0.0 || total6 == 0.0) {
          printf("FAILED, ");
        } else printf("PASSED, ");
        
        GPA = (credits[0]*totalMarks(total1) + credits[1]*totalMarks(total2) + credits[2]*totalMarks(total3) + credits[3]*totalMarks(total4)+ credits[4]*totalMarks(total5) + credits[5]*totalMarks(total6) );        
        GPA = GPA/creditSum;
        
        printf("%.2f\n", GPA);
    }
    
    //while(1);

    return 0;
}

float GPA1 (vector <string> subjects) {
     float mark1, mark2, mark3;
     
     if (subjects[0] == "ab") {subjects[0] = "0";}
     if (subjects[1] == "ab") {subjects[1] = "0";}
     if (subjects[2] == "ab") {subjects[2] = "0";}

     double a = atof(subjects[0].c_str());
     double m = a;             
     double b = atof(subjects[1].c_str());
     double c = atof(subjects[2].c_str());
     if (m > b) m = b;
     if (m > c) m = c;
     mark1 = 45.0*(a+b+c-m)/40.0;

     mark2 = atof(subjects[3].c_str())/2.0;
     
     double attandance = atof(subjects[4].c_str());
     
     if (attandance < 51.0) mark3 = 5.0;
     else if (attandance < 61.0) mark3 = 4.0;
     else if (attandance < 71.0) mark3 = 3.0;
     else if (attandance < 81.0) mark3 = 2.0;
     else if (attandance < 91.0) mark3 = 1.0;
     else mark3 = 0.0;
     
     return (mark1+mark2+mark3);
}

int totalMarks (float mark) {
    if (mark >= 91.0) return 10;
    if (mark >= 81.0) return 9;
    if (mark >= 71.0) return 8;
    if (mark >= 61.0) return 7;
    if (mark > 50.0)  return 6;
    if (mark == 50.0) return 5;
    if (mark < 50.0)  return 0;
}

