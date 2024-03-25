#include <iostream>
#include <pthread.h>
#include <string>

using namespace std;

//create a structure to pass parameters to print_message in phread_create 

//defines a structur named 'mmessage' to hold data for each thread
struct message{
    string quote;
    int index;
    int fiboNum;
};

//recursive function to calculate Fibonacci numbers
int fibo(int n){
    if(n == 0 || n == 1)
        return 1;
    else   
        return fibo(n-1) + fibo(n-2);
}

//this is the function that will be called in phthread_create
//Notice this returns a void pointer
//THREAD FUNCTION
void *print_message(void *ptr){
    //cast the incoming unknown pointer to a message pointer
    message *arg = (message*) ptr;
    //print out the index and quote

    cout << "(" << arg->index<<"): "<<arg->quote <<endl;
    //arg is a pointer to a message structure. accessing the index member structure that arg point to
    cout << "(" << arg->index<<"): "<<"Fibo: "<<arg->fiboNum<<" = "<<fibo(arg->fiboNum)<<endl;

    // -> : access the member of a structur or class that is pointed to by a pointer
    // shorthand notation for accessing members through pointers, making the code cleaner and more readeable

    return NULL;
}
//

//initialize 4 strings in an arrya called quotes
string quotes[4] = {"there","is","no","spoon"};

int main(){
    // creating 4 instances of the "message" struct.
    // initializing them with data, and then creating 4 threads to execute the print_message function concurrently with each message instance

    message m0;
    m0.quote = quotes[0];
    m0.index = 0;
    m0.fiboNum = 40;

    message m1;
    m1.quote = quotes[1];
    m1.index = 1;
    m1.fiboNum = 41;

    message m2;
    m2.quote = quotes[2];
    m2.index = 2;
    m2.fiboNum = 37;

    message m3;
    m3.quote = quotes[3];
    m3.index = 3;
    m3.fiboNum = 38;

    pthread_t thread0, thread1, thread2, thread3;

    int iret0, iret1, iret2, iret3; 

    /*
    Create independent threads each of which will execute function
    */

   iret0 = pthread_create( &thread0, NULL, print_message, (void*) &m0);
   iret1 = pthread_create( &thread1, NULL, print_message, (void*) &m1);
   iret2 = pthread_create( &thread2, NULL, print_message, (void*) &m2);
   iret3 = pthread_create( &thread3, NULL, print_message, (void*) &m3);

   //The return value of pthread_create is 0 if successful and non-zero if there is a problem

   cout << "Thread 0 returns:"<< iret0<<endl;
   cout << "Thread 1 returns:"<< iret1<<endl;
   cout << "Thread 2 returns:"<< iret2<<endl;
   cout << "Thread 3 returns:"<< iret3<<endl;

   /*
   wait till threads are complete before main continues. Unless we wait 
   we run the risk of excuting an exit which will terminate the process and all
   threads before the threads have complete
   */

  return 0;

}