// Author: Fozhan Babaeiyan Ghamsari
// CECS 325-02 Prog 6
// Due 05/07/2024

// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <climits>
#include <cmath>
using namespace std;

class BigInt
{
private:
    vector<char> v;

    BigInt fiboHelper(BigInt n, BigInt a = 0, BigInt b = 1)
    {
        if (n == 0)
            return a;
        if (n == 1)
            return b;
        return fiboHelper(n - 1, b, a + b);
    }

public:
    BigInt() {}
    BigInt(int num) { *this = BigInt(to_string(num)); }
    BigInt(string s)
    {
        for (auto it = s.rbegin(); it != s.rend(); ++it)
            v.push_back(*it - '0');
    }

    bool operator==(const BigInt &other)
    {
        if (v.size() != other.v.size())
            return false;
        for (size_t i = 0; i < v.size(); ++i)
        {
            if (v[i] != other.v[i])
                return false;
        }
        return true;
    }

    friend bool operator>=(const BigInt &lhs, const BigInt &rhs);
    friend bool operator<=(const BigInt &lhs, const BigInt &rhs);
    friend bool operator>(const BigInt &lhs, const BigInt &rhs);
    friend bool operator<(const BigInt &lhs, const BigInt &rhs);

    BigInt operator+(BigInt other)
    {
        BigInt result;
        int carry = 0;
        size_t max_size = max(v.size(), other.v.size());

        for (size_t i = 0; i < max_size || carry; ++i)
        {
            int digit_sum = carry + (i < v.size() ? v[i] : 0) + (i < other.v.size() ? other.v[i] : 0);
            result.v.push_back(digit_sum % 10);
            carry = digit_sum / 10;
        }

        return result;
    }

    BigInt operator-(BigInt other)
    {
        BigInt result;
        int borrow = 0;

        for (size_t i = 0; i < v.size(); ++i)
        {
            int digit_sub = v[i] - (i < other.v.size() ? other.v[i] : 0) - borrow;
            borrow = 0;
            if (digit_sub < 0)
            {
                digit_sub += 10;
                borrow = 1;
            }
            result.v.push_back(digit_sub);
        }

        while (result.v.size() > 1 && result.v.back() == 0)
            result.v.pop_back();

        return result;
    }

    BigInt operator*(BigInt other)
    {
        BigInt result(0);

        if (v.size() < other.v.size())
        {
            BigInt c(*this);
            while (c > BigInt(0))
            {
                result = result + other;
                c = c - BigInt(1);
            }
        }
        else if (v.size() >= other.v.size())
        {
            BigInt c(other);
            while (c > BigInt(0))
            {
                result = result + *this;
                c = c - BigInt(1);
            }
        }
        return result;
    }

    BigInt operator/(BigInt divisor)
    {
        BigInt quotient, remainder(*this);

        while (remainder >= divisor)
        {
            remainder = remainder - divisor;
            quotient = quotient + BigInt(1);
        }

        return quotient;
    }

    BigInt operator%(BigInt divisor)
    {
        BigInt remainder(*this);

        while (remainder >= divisor)
        {
            remainder = remainder - divisor;
        }

        return remainder;
    }

    BigInt &operator++()
    {
        *this = *this + BigInt(1);
        return *this;
    }

    BigInt operator++(int)
    {
        BigInt temp = *this;
        ++*this;
        return temp;
    }

    char operator[](int index)
    {
        if (index < 0 || index >= v.size())
            throw out_of_range("Index out of range");
        return v[index] + '0';
    }

    void print()
    {
        for (auto it = v.rbegin(); it != v.rend(); ++it)
            cout << (int)*it;
    }

    int size() { return v.size(); }

    BigInt fibo()
    {
        return fiboHelper(*this);
    }

    BigInt fact()
    {
        BigInt result(1);
        for (BigInt i(1); i <= *this; i = i + BigInt(1))
        {
            result = result * i;
        }
        return result;
    }

    friend ostream &operator<<(ostream &os, const BigInt &big)
    {
        if (big.v.size() > 12)
        {
            os << (int)big.v.back() << ".";
            for (size_t i = 1; i < 7 && i < big.v.size(); ++i)
                os << (int)big.v[big.v.size() - 1 - i];
            os << "e" << big.v.size() - 1;
        }
        else
        {
            for (auto it = big.v.rbegin(); it != big.v.rend(); ++it)
                os << (int)*it;
        }
        return os;
    }

    friend BigInt operator+(int n, BigInt big)
    {
        return BigInt(n) + big;
    }
};

bool operator>=(const BigInt &lhs, const BigInt &rhs)
{
    if (lhs.v.size() > rhs.v.size())
        return true;
    else if (lhs.v.size() < rhs.v.size())
        return false;
    else
    {
        for (int i = lhs.v.size() - 1; i >= 0; --i)
        {
            if (lhs.v[i] > rhs.v[i])
                return true;
            else if (lhs.v[i] < rhs.v[i])
                return false;
        }
        return true;
    }
}

bool operator>(const BigInt &lhs, const BigInt &rhs)
{
    if (lhs.v.size() > rhs.v.size())
        return true;
    else if (lhs.v.size() < rhs.v.size())
        return false;
    else
    {
        for (int i = lhs.v.size() - 1; i >= 0; --i)
        {
            if (lhs.v[i] > rhs.v[i])
                return true;
            else if (lhs.v[i] < rhs.v[i])
                return false;
        }
        return false;
    }
}

bool operator<=(const BigInt &lhs, const BigInt &rhs)
{
    return !(lhs > rhs);
}

bool operator<(const BigInt &lhs, const BigInt &rhs)
{
    return !(lhs >= rhs);
}

void testUnit()
{
    int space = 10;
    cout << "\a\nTestUnit:\n"
         << flush;
    system("whoami");
    system("date");

    BigInt n1(25);
    BigInt s1("25");
    BigInt n2(1234);
    BigInt s2("1234");
    BigInt n3(n2);

    BigInt fibo(12345);
    BigInt fact(50);
    BigInt imax = INT_MAX;
    BigInt big("9223372036854775807");

    cout << "n1(int)    :" << setw(space) << n1 << endl;
    cout << "s1(str)    :" << setw(space) << s1 << endl;
    cout << "n2(int)    :" << setw(space) << n2 << endl;
    cout << "s2(str)    :" << setw(space) << s2 << endl;
    cout << "n3(n2)     :" << setw(space) << n3 << endl;
    cout << "fibo(12345):" << setw(space) << fibo << endl;
    cout << "fact(50)   :" << setw(space) << fact << endl;
    cout << "imax       :" << setw(space) << imax << endl;
    cout << "big        :" << setw(space) << big << endl;
    cout << "big.print(): ";
    big.print();
    cout << endl;

    cout << n2 << "/" << n1 << " = " << n2 / n1 << " rem " << n2 % n1 << endl;
    cout << "fibo(" << fibo << ") = " << fibo.fibo() << endl;
    cout << "fact(" << fact << ") = " << fact.fact() << endl;

    cout << "10 + n1 = " << 10 + n1 << endl;
    cout << "n1 + 10 = " << n1 + 10 << endl;

    cout << "(n1 == s1)? --> " << ((n1 == s1) ? "true" : "false") << endl;
    cout << "n1++ = ?  --> before:" << n1++ << " after:" << n1 << endl;
    cout << "++s1 = ?  --> before:" << ++s1 << " after:" << s1 << endl;

    cout << "s2 * big = ? --> " << s2 * big << endl;
    cout << "big * s2 = ? --> " << big * s2 << endl;
}

int main()
{
    testUnit();
    return 0;
}