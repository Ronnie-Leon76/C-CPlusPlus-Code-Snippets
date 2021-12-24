#include<iostream>
using namespace std;
class Base{
    int bval;
    public:
        Base():bval(5){
            cout<<"CB";
        }
        Base(int b):bval(b){
            cout<<"CBB"<<bval;
        }
        ~Base(){
            cout<<"DB";
        }
};
class Derived:public Base{
    double dval;
    public:
        Derived():dval(1){
            cout<<"CD";
        }
        Derived(int d):dval(d){
            cout<<"CDD"<<dval;
        }
        ~Derived(){
            cout<<"DD";
        }
};
int main(){
    Base* pb2 = new Base(4);
    Base* pb = new Derived(28);
    delete pb;
    delete pb2;
    return 0;
}