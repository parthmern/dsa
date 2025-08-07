#include <iostream>
#include <vector>
using namespace std;

int howManyParathas(vector<int> arr, int mid){

    int paratha;

    for(int i=0; i<arr.size(); i++){

        
        int currentParatha = 1;
        int limit = 0;
        
        while ((limit + (currentParatha * arr[i]) )<= mid )
        {
            int forThisParathaTime = (currentParatha * arr[i]);
            limit = limit + forThisParathaTime;
            currentParatha++;
            cout << " forThisParathaTime " << forThisParathaTime << "limit " << limit << "currentParatha " << currentParatha -1 << endl;
        }
        
        cout << "For cook rank " << arr[i] << " total p =" << currentParatha -1 << endl;
        paratha = paratha + currentParatha -1;
        
    }

}

int main() {
	
	vector<int> arr = {1,2,3,4};
    int mid = 15;

    howManyParathas(arr, mid);

    


	return 0;
}