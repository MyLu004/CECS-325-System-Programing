// Author: My Lu
// CECS 325-02 Prog 6
// Due 05/08/2024

// I certify that this program is my own original work. I did not copy any part of this program from any other source.
// I further certify that I typed each and every line of code in this program

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

        for (int i = 0; i <= myStr.size(); i++)
        {
            if (isdigit(myStr[i]))
            {
                // cout<<"digit push back:"<< myStr[i] - '0'<<endl;
                v.push_back(myStr[i] - '0');
            }
        }
    };

    BigInt operator+(BigInt n)
    {
        BigInt Mytotal;
        int Myremainder = 0;

        int i = v.size() - 1;
        int j = n.v.size() - 1;

        while (i >= 0 || j >= 0 || Myremainder)
        {
            int sum = Myremainder;

            if (i >= 0)
            {
                int digit1 = int(v[i]);
                sum += digit1;
                i--;
            }
            if (j >= 0)
            {
                int digit2 = int(n.v[j]);
                sum += digit2;
                j--;
            }

            Mytotal.v.insert(Mytotal.v.begin(), sum % 10);
            Myremainder = sum / 10;
        }

        return Mytotal;
    };

    BigInt operator-(BigInt n)
    {
        BigInt Mytotal;
        int Myborrow = 0;

        int i = v.size() - 1;
        int j = n.v.size() - 1;

        while (i >= 0 || j >= 0 || Myborrow)
        {
            int Mysum = Myborrow;
            Myborrow = 0;

            if (i >= 0)
            {
                int digit1 = int(v[i]);
                Mysum += digit1;
                i--;
            }
            if (j >= 0)
            {
                int digit2 = int(n.v[j]);
                Mysum -= digit2;
                j--;
            }

            if (Mysum < 0)
            {
                Mysum = Mysum + 10;
                Myborrow = -1;
            }

            Mytotal.v.insert(Mytotal.v.begin(), Mysum);
        }
        // Remove leading zeroes from the result
        while (Mytotal.size() > 1 && Mytotal.v[0] == 0)
        {
            Mytotal.v.erase(Mytotal.v.begin());
        };

        // BigInt sumResult(0);
        // sumResult.v = result;
        return Mytotal;
    };

    // BigInt operator-(int myNumber)
    // {
    //     BigInt myVal = myNumber; // Convert the integer to a BigInt object
    //     return *this - myVal;    // Call the existing operator- for BigInt
    // };

    BigInt operator-(int myNumber)
    {
        BigInt myVal = myNumber; // Convert the integer to a BigInt object
        BigInt result(0);
        result = *this - myVal;
        return result; // Call the existing operator- for BigInt
    };

    // INCREMENT
    // post-increment
    BigInt operator++(int)
    {
        BigInt myVal = *this;
        *this = *this + 1;
        return myVal;
    };

    // pre-increment
    BigInt operator++()
    {
        *this = *this + 1; // Increment the current value
        return *this;
    };

    // MULTPLICATION
    BigInt operator*(BigInt myNumber)
    {
        // int base_case = 0;
        BigInt myCopy = *this;
        BigInt myResult(0);

        if (myCopy >= myNumber)
        {
            while (myNumber > BigInt(0))
            {
                myResult = myResult + myCopy;
                myNumber = myNumber - 1;
            }
        }
        else if (myNumber > myCopy)
        {
            while (myCopy > BigInt(0))
            {
                myResult = myResult + myNumber;
                myCopy = myCopy - 1;
            };
        }
        return myResult;
    };

    // DIVISION
    BigInt operator/(BigInt myNumber)
    {
        BigInt myCount(0);
        BigInt myCopy = *this;
        // cout << "my copy: " << myCopy << endl;
        while (myCopy >= myNumber)
        {
            // cout << "it went here" << endl;
            myCopy = myCopy - myNumber;
            // cout << "my copy: " << myCopy << endl;
            myCount++;
        }
        return myCount;
    }

    // MODULE
    BigInt operator%(BigInt myNumber)
    {
        // BigInt myCount = 0;
        BigInt myCopy(*this);
        // cout << "my copy: " << myCopy << endl;
        while (myCopy >= myNumber)
        {
            // cout << "it went here" << endl;
            myCopy = myCopy - myNumber;
            // myCount++;
        }
        return myCopy;
    }

    BigInt fact()
    {
        BigInt compare(1);
        BigInt myResult(1);
        BigInt myCopy = *this;
        int c = 0;
        while (myCopy >= compare)
        {
            myResult = myResult * myCopy;
            myCopy = myCopy - 1;
            c++;
        }

        cout << c << endl;
        return myResult;
    }

    BigInt fibo()
    {
        return fiboHelper(*this);
    }; // calls fiboHelper

    bool operator==(BigInt n)
    {
        return v == n.v;
    };

    bool operator>=(BigInt n)
    {
        // cout << "my v: " << v << endl;
        // cout << "my n.v: " << n.v << endl;
        // cout << "answer: " << (v >= n.v) << endl;

        if (v.size() > n.v.size())
        {
            return true;
        }

        else if (n.size() > v.size())
        {
            return false;
        }

        else
        {
            for (int i = 0; i <= v.size(); i++)
            {
                if (v[i] > n.v[i])
                {
                    return true;
                }
                else if (n.v[i] > v[i])
                {
                    return false;
                }
                else
                {
                    continue;
                }
            }
        }
        return true;
    };

    bool operator>(BigInt n)
    {
        // cout << "my v: " << v << endl;
        // cout << "my n.v: " << n.v << endl;
        // cout << "answer: " << (v >= n.v) << endl;

        if (v.size() > n.size())
        {
            return true;
        }
        else if (n.size() > v.size())
        {
            return false;
        }

        else
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] > n.v[i])
                {
                    return true;
                }
                else if (n.v[i] > v[i])
                {
                    return false;
                }
                else
                {
                    continue;
                    ;
                }
            }
        }
        return false;
    };

    // iterate through the vector
    void print()
    {
        for (auto it = v.begin(); it != v.end(); ++it)
            cout << (int)*it;
    }

    // return vector size
    int size()
    {
        return v.size();
    };

    friend ostream &operator<<(ostream &out, const BigInt &b)
    {
        if (b.v.size() > 13)
        {
            for (auto it = b.v.begin(); it != b.v.begin() + 7; ++it)
            {
                if (it == b.v.begin())
                {
                    out << int(*it) << ".";
                }
                else
                {
                    out << int(*it);
                }
            }
            out << "e" << b.v.size() - 1; // Print in exponential notation
        }
        else
        {
            for (auto it = b.v.begin(); it != b.v.end(); ++it)
            {
                out << int(*it);
            }
        }
        return out;
    };

    friend BigInt operator+(int val1, BigInt val2)
    {
        BigInt myResult = val2 + BigInt(val1);
        return myResult;
    };
};

int main()
{
    int space = 10;
    cout << "\a\nTestUnit:\n"
         << flush;
    system("whoami");
    system("date");
    // initialize variables
    BigInt n1(25);
    BigInt s1("25");
    BigInt n2(1234);
    BigInt s2("1234");
    BigInt n3(n2);
    BigInt fibo(12);
    BigInt fact(50);
    BigInt imax = INT_MAX;
    BigInt big("9223372036854775807");
    // display variables
    cout << "n1(int) :" << setw(space) << n1 << endl;
    cout << "s1(str) :" << setw(space) << s1 << endl;
    cout << "n2(int) :" << setw(space) << n2 << endl;
    cout << "s2(str) :" << setw(space) << s2 << endl;
    cout << "n3(n2) :" << setw(space) << n3 << endl;
    cout << "fibo(12345):" << setw(space) << fibo << endl;
    cout << "fact(50) :" << setw(space) << fact << endl;
    cout << "imax :" << setw(space) << imax << endl;
    cout << "big :" << setw(space) << big << endl;
    cout << "big.print(): ";
    big.print();
    cout << endl;
    cout << n2 << "/" << n1 << " = " << n2 / n1 << " rem " << n2 % n1 << endl;
    cout << "fibo(" << fibo << ") = " << fibo.fibo() << endl;
    cout << "fact(" << fact << ") = " << fact.fact() << endl;
    cout << "10 + n1 = " << 100 + n1 << endl;
    cout << "n1 + 10 = " << n1 + 10 << endl;
    cout << "(n1 == s1)? --> " << ((n1 == s1) ? "true" : "false") << endl;
    cout << "n1++ = ? --> before:" << n1++ << " after:" << n1 << endl;
    cout << "++s1 = ? --> before:" << ++s1 << " after:" << s1 << endl;
    cout << "s2 * big = ? --> " << s2 * big << endl;
    cout << "big * s2 = ? --> " << big * s2 << endl;
    return 0;
};