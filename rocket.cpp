#include <iostream>
using namespace std;
class Rocket{
    int power;
    public:
        Rocket(int q=7):power(q){
            cout<<"T(1)-"<<power<<endl;
        }
        void increase(){
            power++;
            cout<<"T(2)-"<<power<<endl;
        }
};
class Missile:public Rocket{
    double range;
    public:
        Missile(int r = 9, double z = 11.1):Rocket(r),range(z){
            cout<<"M(1)-"<<range<<endl;
        }
        void increase(){
            range += 100;
            cout<<"M(2)-"<<endl;
        }
};
int main(){
    Rocket little;
    Rocket* ptr;
    ptr = new Missile(8,22.2);
    little.increase();
    ptr->increase();
    delete ptr;
    return 0;
}