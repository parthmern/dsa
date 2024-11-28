#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> &a, vector<int> &b) {
    int n = a.size();
    int m = b.size();
    int total_len = n + m;
    int gap = (total_len / 2) + (total_len % 2);

    while (gap > 0) {
        int i = 0, j = gap;

        while (j < total_len) {
            // Compare elements in the first array
            if (j < n && a[i] > a[j]) {
                swap(a[i], a[j]);
            }
            // Compare elements across both arrays
            else if (j >= n && i < n && a[i] > b[j - n]) {
                swap(a[i], b[j - n]);
            }
            // Compare elements in the second array
            else if (j >= n && i >= n && b[i - n] > b[j - n]) {
                swap(b[i - n], b[j - n]);
            }

            i++;
            j++;
        }
        gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
    }
}

int main() {
    vector<int> arrA = {1, 2, 8, 9, 12, 13};
    vector<int> arrB = {3, 4, 7, 10};

    merge(arrA, arrB);

    cout << "Merged arrays: ";
    for (int num : arrA) {
        cout << num << " ";
    }
    for (int num : arrB) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
