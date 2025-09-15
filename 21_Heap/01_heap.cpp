#include <iostream>
using namespace std;

class Heap{

    public:
    int arr[101];
    int size;

    Heap(){
        size=0;
    }

    void insert(int val){
        // 1) insert val at end
        size++; // 0th index par kuch nhi dalna hai
        int index = size;
        arr[index] = val;

        // 2) take val to right pos
        while(index>1){
            int parentIndex = index/2;
            if(arr[index]>arr[parentIndex]){
                swap(arr[index], arr[parentIndex]);
                index=parentIndex;
            }else{
                break;
            }
        }
    }

    int delete(){
        // 1) replace rootNode with lastNode
        arr[1] = arr[size];
        size--;

        // 2) place rootNode on right pos
        int index = 1;  // top root node
        while(index<size){
            int left = 2*index;
            int right = 2*index+1;
            int largest = index;
            if(left<size && arr[largest]<arr[left]){
                largest = left;
            }
            if(right<size && arr[largest]<arr[right]){
                largest = right;
            }

            if(largest == index){
                break;// val at correct pos
            }else{
                swap(arr[index], arr[largest]);
            }

            index = largest;
        }
            
    }

};

int main(){
    Heap h;
    h.arr[0]=-1;
    h.arr[1]=100;
    h.arr[2]=50;
    h.arr[3]=60;
    h.arr[4]=40;
    h.arr[5]=45;
    h.size = 5;
    h.insert(110);

    for(int i=0; i<=h.size; i++) cout << h.arr[i] << " ";




}   