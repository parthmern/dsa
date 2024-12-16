#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {

    int low = 0;
    int high = arr.size()-1;

    while( abs(low-high) >= k ){
        
        int diffAtLow = abs(x-arr[low]) ; 
        int diffAtHigh = abs(x-arr[high]);

        if(diffAtLow > diffAtHigh ){
            low ++ ;
        }
        else{
            high --;
        }

    }

    cout << low << high << endl;

    vector<int> ans;
    for(int i=low; i<=high; i++){
        ans.push_back(arr[low]);
        low++;
    }

    return ans;
        
}

int lowerBound(vector<int>& arr, int x){
    int s =0, e=arr.size()-1;
    int ans = -1;
    
    while(s<=e){
        int mid = (s+e)/2;

        if(arr[mid]>=x){
            
            ans=mid;
            e=mid-1;
        }
        else if(x>arr[mid]){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }

    return ans;
}


vector<int> bsMethod(vector<int>& arr, int k, int x){

    // lower bound using bs
    int h = lowerBound(arr,x);
    cout << "h" << h << endl;

    int l = h-1;

    while (k--)
    {
        int diffAtLow = abs(x-arr[l]);
        int diffAtHigh = abs(x-arr[h]);

        if(diffAtLow > diffAtHigh){
            h++;
        }
        else{
            l--;
        }
    }

    cout << l+1 << h-1 << endl;

    return vector<int>(arr.begin()+(l+1), arr.end()+h);
    

}

int main(){


    vector<int> v{1,1,2,3,4,5};


    int totalEle = 4; // k
    int x = 3;

    findClosestElements(v, totalEle, x);

    bsMethod(v, totalEle, x);

    return 0;
}