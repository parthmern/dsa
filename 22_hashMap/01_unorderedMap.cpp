#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    // creation
    unordered_map<string, int> mp;  

    // incertion way
    pair<string, int> p = make_pair("parth", 9);    
    mp.insert(p);   

    pair<string, int> p2("alto", 2);   
    mp.insert(p2);

    mp["fortunar"] = 7; 

    // access
    cout << mp.at("parth") << endl; // 9
    cout << mp["alto"] << endl; // 2
    cout << mp["coool"] << endl; // 0 , error <-- compiler based (here creating one pair cool->0 in map)
    
    // search
    cout << mp.count("parth") << endl;  // 1 exists
    cout << mp.count("innova") << endl; // 0 not exists

    if(mp.find("parth") != mp.end()){
        cout << "found"<< endl;;
    }else{
        cout << "not found" << endl;
    }

    // size
    cout << mp.size() << endl;  // 4 (3 + 1 "coool->0" wala)

    // iterate
    for(auto i: mp){
        // map ki har entry pair hoti he so
        cout << i.first << "-" << i.second << " ";  // fortunar-7 coool-0 alto-2 parth-9
    }

    




    return 0;
}