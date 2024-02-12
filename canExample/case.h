#include <vector>
#include "can.h"

using namespace std;

class Case{
    private:
        vector<Can> storage;
    public:
        Case();
        void add(Can);
        void display();
};