
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;



class BigInt{
    private:
        vector<char> v;
        BigInt fiboHelper(BigInt n, BigInt a = 0, BigInt b = 1);
    public:
        BigInt(){
            
        };

        BigInt(int myNumber){
            // cout << "Entering BigInt()\n";
			if (myNumber == 0)
				v.push_back(0);
			else //pushing other value rather than 0
                while (myNumber > 0)
                {
                    char digit = myNumber%10;
                    // cout << int(digit) << endl;
        
                    v.push_back(digit);
                    myNumber /= 10;
                }
        };

        BigInt(string myStr){
            for (int i = myStr.size() - 1; i >= 0; --i) {
                if (isdigit(myStr[i])) {
                    //cout<<"digit push back:"<< myStr[i] - '0'<<endl;
                    v.push_back(myStr[i] - '0');
                }
            }
        };

        BigInt operator+ (BigInt n){
            
            // get the bigger size
            int maxSize = max(v.size(), n.v.size());
            //fill vector with the same size and same light
            v.resize(maxSize, 0); 
            n.v.resize(maxSize, 0); 
            
            //vector to store the result
            vector<char> result;
            int carry = 0;

            for (int i = maxSize - 1; i >= 0; --i) {
                int sum = v[i] + n.v[i] + carry;
                  result.insert(result.begin(), sum % 10); // Insert the digit at the beginning
                carry = sum / 10; //if it large than 10, then carry = 1
            }

            //if we have the carry at the end, then insert
            if (carry != 0) {
                result.insert(result.begin(), carry); // Insert the carry if it exists
            }

    // Construct a BigInt object using the result vector
            BigInt sumResult; 
            sumResult.v = result;
    
            return sumResult;
        };


        //SUBSTRACTION
        BigInt operator- (BigInt number){
            int maxSize = max(v.size(), number.v.size());

            v.resize(maxSize, 0);
            number.v.resize(maxSize, 0);

            //vector to store the result
            vector<char> result(maxSize,0);
            int borrow = 0; //init the borrow

            for (int i = maxSize - 1; i >= 0; --i) {
                int diff = v[i] - number.v[i] - borrow;
        
                if (diff < 0) {
                    diff += 10;
                    borrow = 1;
                } else {
                    borrow = 0;
                }

                //result.insert(result.begin(), diff + '0');
                result[i] = diff + '0'; // Store the digit in result vector
            };
            // Remove leading zeroes from the result
            while (result.size() > 1 && result[0] == '0') {
                result.erase(result.begin());
            };

            //BigInt sumResult(0);
            //sumResult.v = result;
            return BigInt(string(result.rbegin(), result.rend()));
        };

        BigInt operator- (int myNumber){
            BigInt myVal = myNumber; // Convert the integer to a BigInt object
            return *this - myVal; // Call the existing operator- for BigInt
        };

        //MULTPLICATION
        BigInt operator* (BigInt);

        //DIVISION
        BigInt operator/ (BigInt);
        BigInt operator% (BigInt);

        //INCREMENT
        BigInt operator++(int);
        BigInt operator++( );


        BigInt operator[](int); // index function
        
        void print(){

        };

        int size(){

        };
        
        BigInt fibo(); // calls fiboHelper
        BigInt fact();

        //cout function
		friend ostream & operator<<(ostream & out, BigInt b)
		{	
		    cout << "Entering operator<<()\n";
			vector<char>::iterator it = b.v.end()-1;
			while (it != b.v.begin()-1)
				out << int(*it--);
			return out;
        };

        friend BigInt operator+ (int val1, BigInt val2){
            BigInt myResult = val2 + val1;
            return myResult;
        };
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
    //cout << "(n1 == s1)? --> "<<((n1==s1)?"true":"false")<<endl;
    cout << "n1++ = ? --> before:"<<n1++<<" after:"<<n1<<endl;
    cout << "++s1 = ? --> before:"<<++s1<<" after:"<<s1<<endl;
    cout << "s2 * big = ? --> "<< s2 * big<<endl;
    cout << "big * s2 = ? --> "<< big * s2<<endl;
}

int main(){
    // testUnit();
    cout<<"hi"<<endl;
    return 0;
};