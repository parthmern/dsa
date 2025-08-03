// https://leetcode.com/problems/find-peak-element/
class Solution {
public:
    int findPeakElement(vector<int>& arr) {

        int s = 0;
        int e = arr.size() - 1;
        int mid = (s+e)/2;

        while( s<e ){

            if( (mid>0 &&( arr[mid] > arr[mid-1])) && ( mid<e &&( arr[mid] > arr[mid+1]) )  ){
                return mid;
            }
            else if( arr[mid] < arr[mid + 1] ){
                  s = mid + 1;
            }else{
                 e = mid - 1;
            }

            mid = (s+e)/2;

        }

        return s;

        
    }
};