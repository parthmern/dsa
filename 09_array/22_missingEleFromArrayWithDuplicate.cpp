// a={1,3,5,3,4}
// 2 is missing

// approach = apply negative marking method and then whatever element is positive that index+1 is missing

#include <iostream>

using namespace std;

int main(){
    int a[] = {1,3,5,3,4} ;
    int size = sizeof(a)/sizeof(a[0]);

    // cout << size << endl; 

    // neg marking method
    for(int i=0; i<size; i++){
        int index = abs(a[i]);

        if(a[index-1]>0){
            a[index-1] *= -1 ;
        }

    }

    for(int i=0; i<size; i++){
        cout << a[i] << " ";
    }
    cout<<endl;

    // now find positive ele
    for(int i=0; i<size; i++){

        if(a[i]>0){
            cout << a[i] << "is postiitve so missing ele is =>" << i+1<< endl;
        }

    }

    // =========================================

    int b[] = {1,3,5,3,4} ;
    int sizee = sizeof(b)/sizeof(b[0]);

    // sorting + swapping method
    int i=0;
    while(i<size){

        int index = b[i]-1;

        if(b[i] != b[index]){
            swap(b[i], b[index]);
        }
        else{
            i++;
        }

    }

    for(int i=0; i<sizee; i++){
        cout << b[i] << " ";
    }
    cout<<endl;

    for(int i=0; i<sizee; i++){
        if(i+1 != b[i]){
            cout << b[i] << "is not matching so=>" << i+1 <<"is missing" <<endl;
        }
    }
    




}