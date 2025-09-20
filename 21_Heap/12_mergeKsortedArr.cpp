// https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

class Node{
    
    public: 
        int data;
        int i;
        int j;
        
        Node(int val, int row, int col){
            data = val;
            i = row;
            j = col;
        }
};

class Compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};

class Solution {
  public:
    
    priority_queue<Node*, vector<Node*>, Compare > minHeap;
    vector<int> ans;
    
    void solve(vector<vector<int>> arr, int K){
        // 1) sare array k first ele insert karna he
        for(int i=0; i<K; i++){
            Node* temp = new Node(arr[i][0], i, 0);
            minHeap.push(temp);
        }
        
        // 2)
        while(minHeap.size() > 0){
            Node* top = minHeap.top();
            ans.push_back(top->data);
            minHeap.pop();
            
            int i = top->i;
            int j = top->j;
            
            if(j+1 < arr[i].size()){
                Node* sameArrayNextEle = new Node(arr[i][j+1], i, j+1);
                minHeap.push(sameArrayNextEle);
            }
            
        }
    }
    
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        // code here
        solve(arr, K);
        return ans;
    }
};