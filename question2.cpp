#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
class Person{
    char* m_name;
    public:
        Person() : m_name(nullptr){ cout<<"Person(),";}
        Person(const char* name){
            if(name){
                m_name = new char[strlen(name) + 1];
                strcpy(m_name, name);
            }
        }
        ~Person(){
            cout<<"~Person()";
            delete[] m_name;
        }

};
class Student:public Person{
    int m_id;
    public:
        Student(): m_id(0){ cout<<"Student();"}
        Student(int id) : m_id{id}{ cout<<"Student(int)";}
        Student(int id, const char* name):Person(name),m_id{id}{
            cout<<"Student(int,const char*)";
        }
        ~Student(){
            cout<<"~Student(),";
        }
};
int main(){
    Student s1, s;
    cout<<endl;
    return 0;
}
