### **Approach and Intuition**

This code reverses a singly linked list. Here's a step-by-step explanation:

1. **Initialization**:
   - `front` is used to store the next node in the original list (to keep track of the remaining list).
   - `temp` is used to traverse the list.
   - `prev` is initialized to `nullptr` to represent the new tail of the reversed list (initially empty).

2. **Iterative Reversal**:
   - A `while` loop runs until `temp` becomes `NULL` (indicating the end of the original list).
   - Within the loop:
     - `front = front->next`: Save the next node of `temp` in `front`.
     - `temp->next = prev`: Reverse the current node’s pointer to point to the previous node (`prev`).
     - `prev = temp`: Move the `prev` pointer to the current node (`temp`).
     - `temp = front`: Advance `temp` to the next node in the original list (`front`).

3. **Return the New Head**:
   - When the loop ends, `prev` will point to the new head of the reversed list. It is returned as the result.

Node* reverseList(struct Node* head) {
        // code here
        Node* front=head;
        Node* temp=head;
        Node* prev=nullptr;
        while(temp!=NULL){
             front=front->next;
            temp->next=prev;
            prev=temp;
            temp=front;
           
        }
        return prev;
    }
