#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>


using namespace std;

int main(){
    int myArray[10] = {1,2,3,4,5,6,7,8,9,10};

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    for (int i = 9; i> 0 ; --i ){
        int j = rand()% (i+1);

        int temp = myArray[i];
        myArray[i] = myArray[j];
        myArray[j] = temp;
    
    }

    //print the shuffle array
    for (int i = 0; i < 10; ++i){
        cout << myArray[i]<<endl;
    }

    return 0;
}