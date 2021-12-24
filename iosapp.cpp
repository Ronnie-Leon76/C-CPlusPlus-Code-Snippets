#include<iostream>
#include<cstring>
using namespace std;
class App{
    char m_name[31];
    App(const char* name){
        strcpy(m_name,name);
    }
    public:
    void deploy(){
        cout<<"Deploy app to App store"<<endl;
    }
    virtual void display(iostream& os)const{
        cout<<m_name<<"is an IOS app"<<endl;
    }
};
class iOSApp:public App{
    char m_name[31];
    public:
        iOSApp(const char* name){
            strcpy(m_name, name);
        }
        void deploy(){
            cout<<"Deploy via App Store"<<endl;
        }
        void display(iostream& os)const{
            cout<<m_name<<"is an IOS app"<<endl;
        }

};
class AndroidApp:public App{
    int m_numOfUsers;
    public:
        void deploy(){}
};