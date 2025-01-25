### **Approach and Intuition**
1. **Detecting the Cycle:**
   - Use two pointers, `slow` and `fast`, starting from the head.
   - Move `slow` one step at a time and `fast` two steps at a time.
   - If they meet, a cycle exists; otherwise, exit when `fast` or `fast->next` becomes `NULL`.

2. **Finding the Start of the Cycle:**
   - Once `slow` and `fast` meet inside the cycle, reset `slow` to `head`.
   - Move both `slow` and `fast` one step at a time. The node where they meet again is the start of the cycle.

### **Why It Works**
- The meeting point inside the cycle is a fixed distance from the cycle start, determined by the relative speeds of `slow` and `fast`.
- Resetting `slow` to `head` and moving both pointers at the same speed ensures they converge at the cycle's start due to the mathematical properties of their traversal.

This method works in **O(n)** time and uses **O(1)** space.

Node* findFirstNode(Node* head) {
        // your code here
        Node* fast=head;
        Node *slow=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
        }
        return NULL;
    }
