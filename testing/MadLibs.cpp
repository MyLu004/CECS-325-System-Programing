#include <iostream>
#include <cmath>
using namespace std;

int main(){
    string color, pluralNoun, charName;

    cout <<"enter the color: ";
    getline(cin,color);

    cout <<"enter the plural Noun: ";
    getline(cin,pluralNoun);

    cout <<"enter the character Name: ";
    getline(cin,charName);

    cout << "Rose are "<<color << endl;
    cout << pluralNoun<<" are blue" << endl;
    cout << "I love " << charName << endl;

    return 0;
}