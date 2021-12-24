#include<iostream>
using namespace std;

const int MAX = 100;


class Avenger{
    char m_name[MAX];
    Skill* m_skills;
    int m_numberOfSkills;
    public:
        Avenger(const Avenger& t){
            cout<<"Copy constructor called"<<endl;
        }

};
int main(){
    Avenger A1,A2;
}