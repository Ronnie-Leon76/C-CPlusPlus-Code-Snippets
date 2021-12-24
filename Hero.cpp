#include<iostream>
using namespace std;
const int MAX = 100;
class Hero{
    char m_name[MAX];
    Power* m_powers;
    int m_numberOfPowers;
    public:
        Hero(const Hero& h){
            cout<<"Copy constructor initialized"<<endl;

        }

};
int main(){
    hero1 Hero;
    delete hero1;


}