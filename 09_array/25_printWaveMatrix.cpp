#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector< vector<int> > v  {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
        {17,18,19,20}
    };

    int counter = 0;
    cout << v.size() << v[0].size() << endl;

    for(int i=0; i<v[0].size(); i++){
        
        for(int j=0; j<v.size(); j++){

            cout << v[counter][i]<< endl;
           
            if(i%2==0){
                
                counter++;
            }else{
                counter--;
            }

            

            if(counter == v.size()){
                cout << "counter is " << counter << endl;
                counter = counter - 1;
            }

            if(counter < 0){
                cout << "counter is " << counter << endl;
                counter++;
            }

            
            
        }

    }

    return 0;
}