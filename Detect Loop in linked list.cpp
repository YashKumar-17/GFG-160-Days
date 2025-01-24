### Approach and Intuition:
1. **Using Two Pointers (Slow and Fast)**:
   - A slow pointer (`slow`) moves one step at a time.
   - A fast pointer (`fast`) moves two steps at a time.

2. **Detecting a Loop**:
   - If there is no loop, the `fast` pointer will eventually reach `NULL`.
   - If there is a loop, the `fast` pointer will eventually "lap" the `slow` pointer, meaning `slow == fast`.

3. **Logic**:
   - Traverse the linked list with both pointers.
   - Check if `slow` and `fast` meet during traversal.
   - If they meet, return `true` (loop detected).
   - If `fast` or `fast->next` becomes `NULL`, return `false` (no loop).

This is based on Floyd’s Cycle Detection Algorithm, which efficiently detects cycles in a linked list.

bool detectLoop(Node* head) {
        // your code here
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
