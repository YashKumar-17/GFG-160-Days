### **Approach and Intuition:**

1. **Detect the Loop:**
   - Use **Floyd's Cycle Detection Algorithm** (Tortoise and Hare):
     - Move `slow` pointer one step at a time.
     - Move `fast` pointer two steps at a time.
     - If `slow == fast`, a loop is detected.

2. **Find the Start of the Loop:**
   - Reset `slow` to `head` and keep `fast` at its current position.
   - Move both pointers one step at a time until `slow == fast`. This identifies the starting node of the loop.

3. **Break the Loop:**
   - Use a `prev` pointer to track the node before `fast` in the loop.
   - Move both `slow` and `fast` until they meet.
   - Update `prev->next = NULL` to break the loop.

---

### **Key Points:**
- The `prev` pointer ensures you can disconnect the last node in the loop.
- Resetting `slow` to `head` helps find the loop's starting point.

void removeLoop(Node* head) {
        // code here
        Node* prev;
        Node* fast=head;
        Node* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    prev=fast;
                    slow=slow->next;
                    fast=fast->next;
                }
                prev->next=NULL;
            }
        }
    }
