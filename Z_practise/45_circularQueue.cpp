class MyCircularQueue {
public:
    int* arr;                                                           
    int size;
    int front;
    int rear;
    MyCircularQueue(int k) {
        this->size = k;
        this->arr = new int[k];
        this->front = -1;
        this->rear = -1;
    }
    
    bool enQueue(int value) {
        cout<< front << rear << isFull() << " "<< endl;
        if(isFull()) return false;
        // adding 
        if(isEmpty()){
            front=0;
            rear=0;
            arr[rear] = value;
        }else if(rear == size-1){
            rear = 0;
            arr[rear] = value;
        }else{
            rear++;
            arr[rear] = value;
        }

        return true;
    }
    
    bool deQueue() {
        cout<< "dequ" << front << rear << isEmpty() << " "<< endl;
        if(isEmpty()) return false;

        if(front==rear){
            arr[front] = -1;
            front = -1;
            rear =-1;
            // jab ek he element ho
        }else if(front==size-1){
            arr[front] = -1;
            front=0;
        }else{
            arr[front] = -1;
            front++;
        }
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : arr[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : arr[rear];
    }
    
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }
    
    bool isFull() {
        return ((rear + 1) % size == front) ;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */