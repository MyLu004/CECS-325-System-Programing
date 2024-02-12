#include <iostream>
#include <cmath>
using namespace std;


//SUPER CLASS
class Chef{
    public:
        void makeChicken(){
            cout << "The chef makes Chicken" << endl;
        };

        void makeSalad(){
            cout << "The chef make salad" <<endl;
        };

        void makeSpecialDish(){
            cout << "The chef make bbq ribs" << endl;
        };
};

//SUB CLASS
//inheritance all the public function from Chef
class ItalianChef: public Chef{
    public:
        void makePasta(){
            cout << "The Chef make pasta" <<endl;
        };

        //can also overwrite the function from Chef
        void makeSpecialDish(){
            cout << "The chef make chicken palm" << endl;
        };
};

int main(){
    cout<< "Normal Chef" <<endl;
    Chef chef;
    chef.makeSalad();
    chef.makeSpecialDish();

    cout<< "Italian Chef" <<endl;
    ItalianChef italianChef;
    italianChef.makeChicken();
    italianChef.makePasta();
    italianChef.makeSpecialDish();

    return 0;
}