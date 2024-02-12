#include <iostream>
#include <cmath>
using namespace std;

class Student{
    public:
        string name;
        string major;
        double gpa;
        Student(string aName, string aMajor, double aGpa ){
            name = aName;
            major = aMajor;
            gpa = aGpa;
        }

        //Function to check if the student has honor
        bool hasHonors(){
            if (gpa >= 3.5){
                return true;
            }
            else{
                return false;
            }
        }

};

int main(){
    Student student1 ("Kinoko","Computer Science", 3.9);
    Student student2 ("Jerry", "Computer Science", 1.9);
    
    cout << student1.hasHonors();

    return 0;
}