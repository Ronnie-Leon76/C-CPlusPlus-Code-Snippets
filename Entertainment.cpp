#include<iostream>
using namespace std;
class Entertainment{
    void modifyData(){

    }
    virtual void displayContent(){

    }
};
class Show: public Entertainment{
    char name[20];
    int showCost;
    // Since one decides what safe empty state means
    // Check if arguments passed to the constructor are empty
    Show(char name, int showCost){
        if(sizeof(name) == 0)
            name = '';
        else
            name = name;
    }
    public:
        Show(int n, const char* m ){
            n = showCost;
            m = name;
        }
        void modifyData(){
            cout<<"Enter show name: "<<endl;
            cin>>name;
            cout<<"Enter show cost: "<<endl;
            cin>>showCost;
        }
        void displayContent(){
            cout<<"The show's name is: "<<name<<endl;
            cout<<"The show cost is: "<<showCost<<endl;
        }
};
int main(){
    Show1 = new Show;
}