#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class MyFloat{
    float m_data;
    float& data;
    public:
        MyFloat(float val=0.0){
            m_data = val;
        }
        void prn(){
            cout<<m_data<<endl;
        }
        MyFloat +operator +=(float& val){
            val = 1.5;
            return val;

        }

};
int main(){
    MyFloat I(200),J;
    J = I+=10.3;
    I.prn();
    J.prn();
    return 0;
}