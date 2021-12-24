// Interface class
#include<iostream>
#include<cstring>
using namespace std;
class iGems{
    char m_name[31];
    public:
        iGems(const char* name){
            strcpy(m_name,name);
        }
        void shine(){
            cout<<"Shine like a gemstone"<<endl;
        }
        void polish(){
            cout<<"Polish like a gemstone"<<endl;
        }
        virtual void display(iostream& os)const{}
};

// Abstract class 
class Emerald:public iGems{
    int m_purity;
    public:
        void shine(){
            cout<<"Shine like an Emerald"<<endl;
        }
};