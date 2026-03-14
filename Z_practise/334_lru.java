class Node{

        int key;
        int val;
        Node prev;
        Node next;

    Node(int d){
        this.val = d;
        this.prev = null;
        this.next = null;
    }

}

class LRUCache {

    Node head;
    Node tail;
    int cap = 0;
    int total = 0;
    Map<Integer, Node> mp;

    public LRUCache(int capacity) {

        // with sentenial nodes
        head = new Node(-1);
        tail = new Node(-1);
        
        head.next = tail;
        tail.prev = head;

        cap = capacity;

        mp = new HashMap<>();
        
    }
    
    public int get(int key) {
        if(mp.get(key) != null){
            Node temp = mp.get(key);
            // need to update next to head
            temp.prev.next = temp.next;
            temp.next.prev = temp.prev;
            
            Node newNode = new Node(temp.val);
            newNode.key = key;
            newNode.prev = head;
            newNode.next = head.next;
            head.next.prev = newNode;
            head.next = newNode;
            if(tail.prev == head){
                tail.prev = newNode;
            }
            mp.put(key, newNode);

            return temp.val;
        }
        return -1;
    }
    
       public void put(int key, int value) {

        // key already exists
        if(mp.get(key) != null){

            Node temp = mp.get(key);

            // remove from current position
            temp.prev.next = temp.next;
            temp.next.prev = temp.prev;

            // update value
            temp.val = value;

            // move to head
            temp.prev = head;
            temp.next = head.next;
            head.next.prev = temp;
            head.next = temp;

            return;
        }

        // remove LRU if capacity reached
        if(total == cap){

            Node del = tail.prev;

            del.prev.next = tail;
            tail.prev = del.prev;

            mp.remove(del.key);
            total--;
        }

        // insert new node
        Node newNode = new Node(value);
        newNode.key = key;

        newNode.prev = head;
        newNode.next = head.next;
        head.next.prev = newNode;
        head.next = newNode;

        mp.put(key,newNode);
        total++;
    }

}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */