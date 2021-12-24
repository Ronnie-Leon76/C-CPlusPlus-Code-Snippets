struct Propeller{
    double size;
    char engineType[16];
};
class Drone{
    public:
    Propeller* propllers;
    int numOfPropellers;
    Drone(){}
    Drone(const Drone &drones){
        Drone();
    }
};
// Assignment of one object to another is outside the class
//In the main function
int main(){
    Drone drone1,drone2;
    drone1 = drone2;
}