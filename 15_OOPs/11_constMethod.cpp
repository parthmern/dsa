#include <iostream>
using namespace std;

class axis{

    private:
        int x;
        int *y;
        const int z;

    public:
        // axis(){
        //     x = 0;
        //     y = new int(0);
            
        // }

        //------------------------

        // old style
        // axis(int _x, int _y){
        //     x = _x;
        //     *y = _y;
        //     // z = 0;   //error in old style but can do with new way
        // }

        // new updated "initialization list"
        axis(int _x, int _y, int _z) : x(_x) , y(new int(_y)), z(_z) {}         // const can be insitlaize once here only

        int getX() const {  // it means this method cannot modify member variable
            // x = 40 ;     // error
            return x;
        }

        void setX(int val){
            x = val;
        }

        int getY(){
            return *y;
        }

        void setY(int val){
            *y = val;
        }

};

int main(){

    axis obj(1,2,3);

    return 0;
}