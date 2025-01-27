### Intuition:
The code implements an **LRU (Least Recently Used) Cache**, which keeps track of the most recently accessed items while adhering to a fixed capacity. When the cache is full, the least recently used item is removed to make space for new ones. It achieves this using a combination of a **doubly linked list** and an **unordered map** for efficient lookups, insertions, and deletions.

---

### Approach (Step-by-Step):
1. **Class Initialization:**
   - A doubly linked list is used to maintain the order of items based on usage (most recently used at the head and least recently used at the tail).
   - An unordered map (`ump`) maps keys to their corresponding nodes in the linked list for **O(1)** access.

2. **Helper Functions:**
   - **`addnode(Node* newnode)`**: Inserts a new node just after the head of the list (marks it as most recently used).
   - **`deletenode(Node* delnode)`**: Removes a node from the list by updating the previous and next pointers of its neighbors.

3. **Get Function (`get`):**
   - If the key exists in the map:
     - Fetch the node.
     - Remove it from its current position in the list (as it is now "used").
     - Re-insert it just after the head (most recently used).
     - Return the value of the node.
   - If the key does not exist, return `-1`.

4. **Put Function (`put`):**
   - If the key already exists:
     - Remove the existing node from the list and the map.
   - If the cache has reached its capacity:
     - Remove the least recently used node (node just before the tail) from the list and delete its entry from the map.
   - Add the new key-value pair to the list (just after the head) and update the map.

5. **Maintaining Order:**
   - The doubly linked list ensures the cache always has the most recently used item near the head and the least recently used item near the tail.
   - This allows easy eviction of the least recently used item when the cache exceeds capacity.

---

### Key Operations:
- **Insertion/Deletion in Doubly Linked List**: Constant time operations due to pointer manipulation.
- **Lookup in Map**: Constant time due to the unordered map.
- **Overall Time Complexity**:
  - **Get/Put**: O(1) because both the map and doubly linked list operations are efficient.
  
This makes the implementation highly efficient for LRU cache requirements.

class LRUCache {
  private:
  public:
    class Node{
        public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key, int val){
            this->key=key;
            this->val=val;
        }
        
    };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int capi;
    unordered_map<int, Node*>ump;
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        // code here
        capi=cap;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(Node* newnode){
        Node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    void deletenode(Node* delnode){
        Node* delprev=delnode->prev;
        Node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        if(ump.find(key)!=ump.end()){
            Node* resnode=ump[key];
            int res=resnode->val;
            ump.erase(key);
            deletenode(resnode);
            addnode(resnode);
            ump[key]=head->next;
            return res;
        }
        return -1;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        if(ump.find(key)!=ump.end()){
            Node* existingnode=ump[key];
            ump.erase(key);
            deletenode(existingnode);
        }
        if(ump.size()==capi){
            ump.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new Node(key,value));
        ump[key]=head->next;
    }
};
