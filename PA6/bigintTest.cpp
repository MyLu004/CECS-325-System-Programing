
#include <iostream>
// #include <algorithm>
// #include <random>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <vector>
#include <iomanip>
using namespace std;



class BigInt{
    private:
        vector<char> v;
        BigInt fiboHelper(BigInt n, BigInt a = 0, BigInt b = 1);
    public:
        BigInt();
        BigInt(int);
        BigInt(string);
        BigInt operator+ (BigInt);
        BigInt operator- (BigInt);
        BigInt operator- (int);
        BigInt operator* (BigInt);
        BigInt operator/ (BigInt);
        BigInt operator% (BigInt);
        BigInt operator++(int);
        BigInt operator++( );
        BigInt operator[](int); // index function
        void print();
        int size();
        BigInt fibo(); // calls fiboHelper
        BigInt fact();
        friend ostream& operator<<(ostream&, const BigInt&);
        friend BigInt operator+ (int, BigInt);
};

void testUnit()
{
    int space = 10;
    cout << "\a\nTestUnit:\n"<<flush;
    system("whoami");
    system("date");
    // initialize variables
    BigInt n1(25);
    BigInt s1("25");
    BigInt n2(1234);
    BigInt s2("1234");
    BigInt n3(n2);
    BigInt fibo(12345);
    BigInt fact(50);
    BigInt imax = INT_MAX;
    BigInt big("9223372036854775807");
    // display variables
    cout << "n1(int) :"<<setw(space)<<n1<<endl;
    cout << "s1(str) :"<<setw(space)<<s1<<endl;
    cout << "n2(int) :"<<setw(space)<<n2<<endl;
    cout << "s2(str) :"<<setw(space)<<s2<<endl;
    cout << "n3(n2) :"<<setw(space)<<n3<<endl;
    cout << "fibo(12345):"<<setw(space)<<fibo<<endl;
    cout << "fact(50) :"<<setw(space)<<fact<<endl;
    cout << "imax :"<<setw(space)<<imax<<endl;
    cout << "big :"<<setw(space)<<big<<endl;
    cout << "big.print(): "; big.print(); cout << endl;
    cout << n2 << "/"<< n1<< " = "<< n2/n1 <<" rem "<<n2%n1<<endl;
    cout << "fibo("<<fibo<<") = "<<fibo.fibo() << endl;
    cout << "fact("<<fact<<") = "<<fact.fact() << endl;
    cout << "10 + n1 = " << 10+n1 << endl;
    cout << "n1 + 10 = " << n1+10 << endl;
    cout << "(n1 == s1)? --> "<<((n1==s1)?"true":"false")<<endl;
    cout << "n1++ = ? --> before:"<<n1++<<" after:"<<n1<<endl;
    cout << "++s1 = ? --> before:"<<++s1<<" after:"<<s1<<endl;
    cout << "s2 * big = ? --> "<< s2 * big<<endl;
    cout << "big * s2 = ? --> "<< big * s2<<endl;
}