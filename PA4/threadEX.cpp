#include <iostream>
#include  <thread>



static bool s_finished = false;

void Dowork(){

    while(!s_finished){
        std::cout << "woring...\n";
    }
}

int main(){

    //thread type
    std::thread worker(Dowork);
    
    //wait for the thread joining
    worker.join();

    std::cin.get();
    s_finished = true;

    return 0;
}

