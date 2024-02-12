#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string name = "John";
    int age = 15;
    cout <<"Hello World!" << endl;
    cout <<"what up there, I am "<< name << "and I am "<<age<< " years old"<< endl;

    

    //user input
    int myAge;
    cout << "Enter your age: ";
    //get the input/ Only work for char [single character] and number
    cin >> myAge;
    cout << "You are " << myAge << " years old"<<endl;

    //clear the input buffer
    cin.ignore();

    //user input; string
    string myName;
    cout << "Please enter your name: ";
    getline(cin, myName);

    cout << "Hello my friend: "<< myName;

    return 0; 
}

