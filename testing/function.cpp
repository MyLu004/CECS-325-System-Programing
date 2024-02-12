#include <iostream>
#include <cmath>
using namespace std;

//void: mean the function not gonna return anything
void sayHi(string name, int age){
    cout << "Hello "<< name << " ,you are "<< age <<endl;
}


//main function: will run everytime the program running, compiler
int main()
{
    cout << "this run first"<<endl;
    sayHi("kinoko",19);
    sayHi("Nancy",19);
    sayHi("Jerry",20);
    return 0;
}