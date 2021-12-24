#include<iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
class Phone{
    double* m_price;
    int m_memorysize;
    public:
        Phone(const double price[], int memorysize);
        Phone(const Phone & G);
        Phone & operator=(const Phone & G);
        virtual ~Phone();
};
class WrappedPhone:public Phone{
    char* m_sendToLabel;
    void setDynamicLabel(const char* val);
    public:
        WrappedPhone(const char* label = nullptr, const double* phonePrice = nullptr, int size = 0);
        
};