#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(char first, char second){

    return first > second ;
}

bool compare(int first, int second){

    return first > second ;
}

int main(){

    // string
    string s = "babbar";
    sort(s.begin(), s.end(), cmp);

    for( auto a: s ){
        cout << a << " ";
    }
    cout << endl;


    // int
    vector<int> v{5,3,1,2,4};

    sort(v.begin(), v.end(), compare);

    for( auto a: v ){
        cout << a << " ";
    }
    cout << endl;

    // vector string
    vector<string> ans{"love", "babbar", "rahul", "sandeep"};

    for( auto x: ans ){
        cout << x << " ";
    }
    cout << endl;
    

    return 0;
}