class MinHeap {
    int[] harr;
    int capacity;
    int heap_size;

    MinHeap(int cap) {
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    }

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return (2 * i + 1); }

    int right(int i) { return (2 * i + 2); }

    // Function to extract minimum value in heap and then to store
    // next minimum value at first index.
    int extractMin() {
        // Your code here.
        int res =  harr[0];
        
        
        deleteKey(0);
        
        return res;
    }

    // Function to insert a value in Heap.
    void insertKey(int k) {
        // Your code here.
        
        // insert at last index and then adjust it
        harr[heap_size] = k;
        int i = heap_size;
        heap_size++;
        
        while(i>0){
            
            int parentIndex = (i-1)/2;
            
            if(harr[parentIndex] > harr[i]){
                // swap
                int temp = harr[parentIndex];
                harr[parentIndex] = harr[i];
                harr[i] = temp;
                i = parentIndex;
            }else{
                break;
            }
            
            
        }
        
        //System.out.println(Arrays.toString(harr));
        
    }

    // Function to delete a key at ith index.
    void deleteKey(int i) {
    
        int hs = heap_size - 1;
    
        if(hs < 0){
            return;
        }
    
        // swap with last
        int temp  = harr[i];
        harr[i] = harr[hs];
        harr[hs] = -1;
    
        heap_size--;  
    
        int child1 = (2*i)+1;
        int child2 = (2*i)+2;
    
        while(i < heap_size){
    
            int smallest = i;
    
            if(child1 < heap_size && harr[child1] < harr[smallest]){
                smallest = child1;
            }
    
            if(child2 < heap_size && harr[child2] < harr[smallest]){
                smallest = child2;
            }
    
            if(smallest == i){
                break;
            }else{
    
                int t = harr[i];
                harr[i] = harr[smallest];
                harr[smallest] = t;
    
                i = smallest;
            }
    
            child1 = (2*i)+1;
            child2 = (2*i)+2;
        }
    }

    // Function to change value at ith index and store that value at first index.
    void decreaseKey(int i, int new_val) {
        harr[i] = new_val;
        while (i != 0 && harr[parent(i)] > harr[i]) {
            int temp = harr[i];
            harr[i] = harr[parent(i)];
            harr[parent(i)] = temp;
            i = parent(i);
        }
       // sstem.out.println(Arrays.toString(harr));
    }

    /* You may call below MinHeapify function in
      above codes. Please do not delete this code
      if you are not writing your own MinHeapify */
    void MinHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l] < harr[i]) smallest = l;
        if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
        if (smallest != i) {
            int temp = harr[i];
            harr[i] = harr[smallest];
            harr[smallest] = temp;
            MinHeapify(smallest);
        }
      //System.out.println(Arrays.toString(harr));
    }
}