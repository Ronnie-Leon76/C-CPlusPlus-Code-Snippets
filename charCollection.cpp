#include<iostream>
using namespace std;
class charCollection{
    char* m_nums;
    int m_size;
    public:
        charCollection(char* nums = nullptr, int size = 0);
        char& operator[](int index);
        virtual ~charCollection();
        charCollection(const charCollection& c){
            cout<<"Copy constructor called"<<endl;
        }
};