### **Intuition & Approach for `mergeKLists`**  

#### **Intuition:**  
The goal is to merge **K sorted linked lists** into **one sorted linked list** efficiently. Since all lists are already sorted, the best way to merge them is by using a **min-heap (priority queue)** to always extract the smallest element.

---

#### **Approach:**  
1. **Use a Min-Heap (Priority Queue):**  
   - Push all elements from all K linked lists into a **min-heap** (which automatically keeps them sorted).  

2. **Extract & Build New List:**  
   - Pop elements one by one from the **min-heap** and create a new sorted linked list.  

3. **Return the Head of the Merged List.**  

---

#### **Step-by-Step Execution:**  
1. Initialize a **min-heap (`pq`)** to store node values.  
2. Traverse each linked list, pushing all node values into the heap.  
3. Create a new linked list by extracting the smallest values from the heap **one by one**.  
4. Link the extracted nodes together to form the final **merged sorted list**.  
5. Return the head of this new merged linked list.  

---

### **Time Complexity:**  
- **O(N log N)** where **N** is the total number of nodes across all lists (since we insert N elements into a heap and extract them).  

### **Space Complexity:**  
- **O(N)** for storing N elements in the heap.  

This approach ensures an efficient and sorted merge of multiple linked lists! 🚀

Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
         int n=arr.size();
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0;i<n;i++){
            Node* head=arr[i];
            while(head!=NULL){
                int val=head->data;
                pq.push(val);
                head=head->next;
            }
        }
        Node* nh=new Node(pq.top());
        pq.pop();
        Node* prev=nh;
        Node* temp;
        while(!pq.empty()){
            temp=new Node(pq.top());
            pq.pop();
            prev->next=temp;
            prev=temp;
        }
        prev->next=NULL;
        return nh;
    }
