#include <iostream>
#include <vector>

using namespace std;

int main(){
    //dont have to specify the size for vector, it automate increase it size

    //type <data type> variablename = {#,#,#}
    vector<int> myVector = {1,2,3,4,5,6,7};

    cout <<"my vector: " << myVector[2] <<endl;

    //give you the first element in the vector
    cout <<"my vector front: " << myVector.front() <<endl;

    //give you the last element in the vector
    cout <<"my vector back: " << myVector.back() <<endl;

    //the size of the vector
    cout <<"my vector size: " << myVector.size() <<endl;

    //capapcity is how many element it currently can hold [the expect] -> only increase
    //size is how many element if holding currently [the current]

    myVector.push_back(8); //push to the back
    cout <<"my vector size: " << myVector.size() <<endl;
    cout <<"my vector capacity: " << myVector.capacity() <<endl;

    //to shrink the capacoty: using function : shrink_to_fit()
    
    myVector.shrink_to_fit();
    cout <<"my vector capacity: " << myVector.capacity() <<endl;

    //insert and erase elements
    //need a pointer to the position of the element to insert element before

    vector<int> myVector2 = {1,2,3,4,5,6};

    //insert at the beginning
    myVector2.insert(myVector2.begin(),9);
    myVector2.insert(myVector2.begin(),7);
    cout<< myVector2[0] << endl;

    //erase the element
    myVector2.erase(myVector2.begin());
    cout << myVector2[0]<<endl;

    //iterate through the array
    for (int value:myVector2){
        cout << value << endl;
    }

    //or longer way
    for (int i = 0; i < myVector2.size(); i++){
        cout << "my array" << "[" << i << "]: " << myVector2[i] <<endl;
    };
    
    return 0;   
    
}