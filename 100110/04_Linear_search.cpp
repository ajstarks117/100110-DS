/*In Computer Engg. Dept. of VIT there are S.Y., T.Y., and B.Tech. students. Assume that all these students are on ground for a function. We need to identify a student of 
S.Y. div. (X) whose name is "XYZ" and roll no. is "17". Apply appropriate Searching method to identify the required student.*/

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNo;
    string year;
    string div;
} students[4];

void linearSearch(string targetName, int targetRollNo, string targetYear, string targetDiv){
    for(int i = 0; i<4; i++){
        if(students[i].name == targetName && students[i].rollNo == targetRollNo && students[i].year == targetYear && students[i].div == targetDiv){
            cout << "Student Found: "<< endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Roll No: " << students[i].rollNo << endl;
            cout << "Year: " << students[i].year << endl;
            cout << "Division: " << students[i].div << endl;
        }
    }
}


int main(){
    students[0] = {"ABC", 10, "S.Y.", "A"};
    students[1] = {"XYZ", 17, "S.Y.", "X"};
    students[2] = {"DEF", 25, "T.Y.", "B"};
    students[3] = {"GHI", 30, "B.Tech.", "C"};

    string name; 
    int rollNo; 
    string year;
    string div;
    cout << "Enter name, roll no, year, division of student to search:";
    cin >> name >> rollNo >> year >> div;
    linearSearch(name, rollNo, year, div);

    return 0;
}