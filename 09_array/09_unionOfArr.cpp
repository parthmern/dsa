// Input:

//  vector<int> arra{1,3,5,7,9} ;
//  vector<int> arrb{2,4,6,8} ;

// Output:
//  {1 3 5 7 9 2 4 6 8 }

// for practise not making duplication available in array
// for basic develop

#include <iostream>
#include<vector>  
using namespace std;

int main(){

    vector<int> arra{1,3,5,7,9} ;
    vector<int> arrb{2,4,6,8} ;

    vector<int>ans;

    for(int i=0; i<arra.size(); i++){
        ans.push_back(arra[i]);
    }
    
    for(int i=0; i<arrb.size(); i++){
        ans.push_back(arrb[i]);
    }

    //print ans
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " " ;
    }

    return 0;
}