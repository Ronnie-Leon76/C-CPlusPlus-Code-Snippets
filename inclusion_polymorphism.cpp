#include<iostream>
using namespace std;
class Base {
   public:
      virtual void print() {
         cout << "This is base class." << endl;
      }
};
class Derived : public Base {
   public:
      void print() {
         cout << "This is derived class." << endl;
      }
};
int main() {
   Base *ob1;
   Base base_obj;
   Derived derived_obj;
   ob1 = &base_obj; //object of base class
   ob1->print();
   ob1 = &derived_obj; //same pointer to point derived object
   ob1->print();
}