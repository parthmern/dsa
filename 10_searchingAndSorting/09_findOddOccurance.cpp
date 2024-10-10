#include <iostream>
#include <vector>

using namespace std;

int findOddOcc(vector<int> arr){

    int start = 0 ;
    int end = arr.size()-1;
    int mid = start + (end-start)/2 ;

    while (start<end)
    {   
        // even
        if( mid % 2 == 0){
            
            if( arr[mid] == arr[mid+1] ){
                
                // left side me khada hu - so right serach
                start = mid + 2;

            }
            else{

                // wo mid he ans hoga - and right side me khada hu so left search
                end = mid;

            }

        }
        // odd mid index
        else{

            if( arr[mid] == arr[mid-1] ){
                
                // left side me khada hu - so right serach
                start = mid + 1;

            }
            else{

                // right side me khada hu so left search
                end = mid - 1;

            }

        }

        mid = start + (end-start)/2 ;

    }

    return mid;
    

}

int main(){

    vector<int> v{1,1,2,2,3,3,4,4,3,600,600,4,4};

    cout << "index is " << findOddOcc(v) << endl;

    return 0;
}