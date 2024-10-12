#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int countingStudents(vector<int> arr, int totalPages) {
    int student = 1;
    int pages = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (pages + arr[i] <= totalPages) {
            pages += arr[i];
        } else {
            student++;
            pages = arr[i];

            //cout << "Student " << student << " starts with " << pages << " pages." << endl;
        }
    }

    return student;
}

int binarySearch(vector<int> arr, int s, int e, int maxStudent) {
    int start = s;
    int end = e;
    int result = e; 

    int mid = start + (end - start) / 2;

    while (end >= start) {
        
        int studentNow = countingStudents(arr, mid);
        
        cout << "mid->" << mid << " student->" << studentNow << endl;

        if (studentNow <= maxStudent) {
            // Update result to the current mid as it could be the answer
            result = mid;
            
            // Search in the left half
            end = mid - 1;
        } else {
            // Search in the right half
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    cout << "mid in end" << mid << endl;

    return result;
}

int main() {
    vector<int> v{25, 46, 28, 49, 24};
    auto maxElement = *max_element(v.begin(), v.end());
    int sum = accumulate(v.begin(), v.end(), 0);

    cout << binarySearch(v, maxElement, sum, 4) << endl;

    return 0;
}
