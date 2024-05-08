#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
#include <typeinfo>
#include <climits>

using namespace std;

class BigInt
{
private:
    vector<char> v;
    BigInt fiboHelper(BigInt n, BigInt a = 0, BigInt b = 1)
    {
        if (n == 0)
        {
            return a;
        }
        else if (n == 1)
        {
            return b;
        }
        else
        {
            return fiboHelper(n - 1, b, a + b);
        };
    };

public:
    BigInt(){};

    BigInt(int myNumber)
    {
        // cout << "Entering BigInt()\n";
        if (myNumber == 0)
            v.push_back(0);
        else // pushing other value rather than 0
            while (myNumber > 0)
            {
                char digit = myNumber % 10;
                // cout << int(digit) << endl;

                v.push_back(digit);
                myNumber /= 10;
            }
        reverse(v.begin(), v.end());

    };

    BigInt(string myStr)
    {

        for(int i = 0; i <= myStr.size(); i++){
            if (isdigit(myStr[i]))
            {
                // cout<<"digit push back:"<< myStr[i] - '0'<<endl;
                v.push_back(myStr[i] - '0');
            }
        }
    };

    BigInt operator+(BigInt n)
    {
        // get the bigger size
        int maxSize = max(v.size(), n.v.size());
        if(v.size()< maxSize){
            int different_size = maxSize - v.size();
            for (int i=0; i < (maxSize - v.size()); i++){
                v.insert(v.begin(),0);
            };
        }

        if(n.v.size()< maxSize){
            int different_size = maxSize - n.v.size();
            for (int i=0; i < (different_size); i++){
                n.v.insert(n.v.begin(),0);
            };
        }

        // vector to store the result
        vector<char> result;
        int carry = 0;

        for (int i = maxSize - 1; i >= 0; --i)
        {
            int sum = v[i] + n.v[i] + carry;
            result.insert(result.begin(), sum % 10); // Insert the digit at the beginning
            carry = sum / 10;                        // if it large than 10, then carry = 1
        }

        // if we have the carry at the end, then insert
        if (carry != 0)
        {
            result.insert(result.begin(), carry); // Insert the carry if it exists
        }

        // Construct a BigInt object using the result vector
        BigInt sumResult;
        sumResult.v = result;

        return sumResult;
    };

    BigInt operator-(BigInt number)
    {
        int maxSize = max(v.size(), number.v.size());
        if(v.size()< maxSize){
            int different_size = maxSize - v.size();
            for (int i=0; i < (maxSize - v.size()); i++){
                v.insert(v.begin(),0);
            };
        }

        if(number.v.size()< maxSize){
            int different_size = maxSize - number.v.size();
            for (int i=0; i < (different_size); i++){
                number.v.insert(number.v.begin(),0);
            };
        }

        // vector to store the result
        vector<char> result(maxSize, 0);
        int borrow = 0; // init the borrow

        for (int i = maxSize - 1; i >= 0; --i)
        {
            int diff = v[i] - number.v[i] - borrow;

            if (diff < 0)
            {
                diff += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }

            // result.insert(result.begin(), diff + '0');
            result[i] = diff + '0'; // Store the digit in result vector
        };
        // Remove leading zeroes from the result
        while (result.size() > 1 && result[0] == '0')
        {
            result.erase(result.begin());
        };

        // BigInt sumResult(0);
        // sumResult.v = result;
        return BigInt(string(result.begin(), result.end()));
    };

    BigInt operator-(int myNumber)
    {
        BigInt myVal = myNumber; // Convert the integer to a BigInt object
        return *this - myVal;    // Call the existing operator- for BigInt
    };

    // INCREMENT
    // post-increment
    BigInt operator++(int)
    {
        BigInt myVal = *this;
        *this = *this + 1;
        return myVal;
    };

    // MULTPLICATION
    BigInt operator*(BigInt myNumber)
    {
        int base_case = 0;
        BigInt myResult, myOther;
        BigInt InitBaseCase(1);

        // checking the vector size
        if (v.size() < myNumber.size())
        {
            myOther = myOther + *this;
            myResult = myResult + myNumber;
        }
        else
        {
            base_case = 1;
            myOther = myOther + myNumber;
            myResult = myResult + *this;
        };

        while (!(myOther == InitBaseCase))
        {
            myResult = myResult + *this;
            myOther = myOther - 1;
        };

        return myResult;
    };

    // pre-increment
    BigInt operator++()
    {
        *this = *this + 1; // Increment the current value
        return *this;
    };

    BigInt fibo()
    {
        return fiboHelper(*this);
    }; // calls fiboHelper

    bool operator==(const BigInt &n) const
    {

        if (v.size() != n.v.size())
        {
            return false;
        }
        else
        {
            for (int i = 0; i <= v.size(); i++)
            {
                if (v[i] != n.v[i])
                {
                    return false;
                };
            }
            return true;
        }
    };

    // iterate through the vector
    void print()
    {
        for (auto it = v.begin(); it != v.end(); ++it)
        {
            cout << int(*it); // print the value
        }
    };

    // return vector size
    int size()
    {
        return v.size();
    };

    friend ostream &operator<<(ostream &out, const BigInt &b) {
    if (b.v.size() > 13) {
        for (auto it = b.v.begin(); it != b.v.begin() + 7; ++it) {
            out << int(*it);
        }
        out << "e" << b.v.size() - 1; // Print in exponential notation
    } else {
        for (auto it = b.v.begin(); it != b.v.end(); ++it) {
            out << int(*it);
        }
    }
    return out;       
};

    friend BigInt operator+(int val1, BigInt val2)
    {
        BigInt myResult = val2 + val1;
        return myResult;
    };
};

int main()
{
    int space = 10;
    cout << "\a\nTestUnit:\n"
         << flush;
    // system("whoami");
    // system("date");
    // initialize variables
    BigInt n1(45);
    BigInt s1("2468357");
    BigInt n2(1234);
    BigInt s2("1234");
    BigInt n3(n2);
    BigInt fibo(25);
    // BigInt fact(50);
    // BigInt imax = INT_MAX;
    // BigInt big("9223372036854775807");
    // display variables
    cout << "n1(int) :" << setw(space) << n1 << endl;
    cout << "s1(str) :" << setw(space) << s1 << endl;
    cout << "n2(int) :" << setw(space) << n2 << endl;
    cout << "s2(str) :" << setw(space) << s2 << endl;
    cout << "n3(n2) :" << setw(space) << n3 << endl;

    cout << "fibo(12345):" << setw(space) << fibo << endl;
    //  cout << "fact(50) :"<<setw(space)<<fact<<endl;
    //  cout << "imax :"<<setw(space)<<imax<<endl;
    //  cout << "big :"<<setw(space)<<big<<endl;
    //  cout << "big.print(): "; big.print(); cout << endl;
    //  cout << n2 << "/"<< n1<< " = "<< n2/n1 <<" rem "<<n2%n1<<endl;
    cout << "fibo(" << fibo << ") = " << fibo.fibo() << endl;
    //  cout << "fact("<<fact<<") = "<<fact.fact() << endl;
    //  cout << "10 + n1 = " << 10 + n1 << endl; //neighbor operator
    //  cout <<"!!!my sum :"<< n1+10 <<endl;
    //  cout << "n1 + 10 = " << n1 + 10 << endl;
    //  cout << "n1 - 2 = " << n1 - 16 <<endl;
    //  cout << "35 - n1 = " << n1 - n2 <<endl;
    //  //cout << "(n1 == s1)? --> "<<((n1==s1)?"true":"false ")<<endl;

    // post-increment
    // cout << "n1++ = ? --> before:"<<n1++<<" after:"<<n1<<endl;
    // cout << "++s1 = ? --> before:"<<++s1<<" after:"<<s1<<endl;
    // cout << "s2 * big = ? --> " << s2 * big << endl;
    //  cout << "big * s2 = ? --> "<< big * s2<<endl;

    // cout << n1*2<<endl;

    return 0;
};