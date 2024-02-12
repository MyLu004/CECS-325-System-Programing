#ifndef xcan_h
#define xcan_h
#include <string>

using namespace std;

class Can{
    private:
        string contents;
        int size;

    public:
        Can();
        Can(string, int);
        void display();

};

#endif