#include<iostream>
using namespace std;
class Animal{
    int weight;
    public:
    Animal(){
        weight = 0; cout<<"A";
    }
    Animal& operator+=(int num){
        weight += num;
        cout<<"+"<<weight;
        return *this;
    }
    ~Animal(){
        cout<<weight;
    }
};
class Dog:public Animal{
    double doginess;
    public:
        Dog(){
            cout<<"D";
            doginess = 0;
        }
       Dog& operator+=(int num){
           this->~Animal::operator+=(num);
           doginess += num;
           cout<<"+"<<doginess;
           return *this;
       }
        ~Dog(){
           cout<<doginess; 
        }
};
int main(){
   Dog d;
   Animal a;
   d += 20;
   a += 3;
}