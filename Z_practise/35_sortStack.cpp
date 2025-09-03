/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/
void addEleAtSortedPlace(stack<int>& s, int ele){  
    if(s.empty() || ele<= s.top()){
        s.push(ele);
        return;
    }    
    int top = s.top();
    s.pop();
    addEleAtSortedPlace(s,ele);
    s.push(top);
    
}

/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack ::sort() {
    // Your code here
    
    if(s.empty()){
        return;
    }
    
    int top = s.top();
    s.pop();
    addEleAtSortedPlace(s,top);
    s.push(top);
    
}