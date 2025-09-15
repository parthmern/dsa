#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    
    int left = 2 * i;
    int right = 2 * i + 1;

    int largest = i;

    if(left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for(int i = n/2; i > 0; i--) {
        heapify(arr, n, i);
    }
}

int main() {
    int arr[6] = {-1, 10, 20, 30, 25, 5};  // -1 is dummy at index 0
    int n = 5;

    buildHeap(arr, n);

    cout << "Heapified array: ";
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
