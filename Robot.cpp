#include<iostream>
using namespace std;
class Robot{
    int speed;
    public:
        Robot(int q = 3):speed(q){
            cout<<"R2:"<<speed<<endl;
        }
        void increase(){
            speed++;
            cout<<"R1:"<<speed<<endl;
        }
};
class Drone:public Robot{
    double altitude;
    public:
        Drone(int r = 5, double z = 33.3):Robot(r), altitude(z){
            cout<<"D1:"<<altitude<<endl;
        }
        void increase(){
            altitude += 10;
            cout<<"D2:"<<altitude<<endl;
        }
};
int main(){
    Robot little;
    Robot* ptr;
    ptr = new Drone(10,44.44);
    little.increase();
    ptr->increase();
    delete ptr;
    return 0;
}