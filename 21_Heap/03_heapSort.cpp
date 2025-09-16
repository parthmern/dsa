#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left <= n && arr[left] > arr[largest]) {
        largest = left;
    }
    if(right <= n && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for(int i = n/2; i >= 1; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    int index = n;
    while(index > 1) {
        swap(arr[1], arr[index]);
        index--;
        n--;
        heapify(arr, n, 1);
    }
}

int main() {
    int arr[6] = {-1, 4, 10, 3, 5, 1}; // -1 dummy
    int n = 5;

    buildHeap(arr, n);
    heapSort(arr, n);

    cout << "Sorted: ";
    for(int i = 1; i <= n; i++) cout << arr[i] << " ";
}
