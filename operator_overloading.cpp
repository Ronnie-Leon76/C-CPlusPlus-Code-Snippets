#include<iostream>
class Truck{
    int id;
    float speed;
    public:
        Truck();
        Truck(int myid, float myspeed);
        void read(std::istream& is);
        void display(std::ostream& os)const;
        void operator >>(std::istream& input){
            input>>id>>speed;
        }
        void operator <<(std::ostream& os){
            os<<"Truck information: "<<id<<speed;
        }
        
};