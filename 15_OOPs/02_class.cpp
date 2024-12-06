#include <iostream>
using namespace std;


class Animal{

    // state
    public:
    int age;
    string name;

    private:
    int weight;

    // behaviour
    public:
    void eat(){
        cout << "eating" << endl;
    }

    void sleep(){
        cout << "sleeping" << endl;
    }
    
    int getWeight(){
        return weight;
    }

    void setWeigth(int w){
        weight = w; 
    }

    void setWeightThis(int weight){
        this->weight = weight;
        // current obj weigth = parameter weight
    }


};


int main(){

    // object creation
    // 1)static allocation
    Animal ramesh;

    ramesh.age = 12;
    cout << "age of ramesh" << ramesh.age << endl;
    ramesh.eat();

    // cout << "private member not accessible" << ramesh.weight << endl;
    // so make getter and setter method
    ramesh.setWeigth(101);
    cout << "weight of ramesh using setter func" << ramesh.getWeight() << endl;


    // ----------------------------------
    // 2)dynamic allocation
    Animal* suresh = new Animal;
    (*suresh).age = 17;
    suresh->age = 17;

    suresh->eat();
    


    return 0;
}