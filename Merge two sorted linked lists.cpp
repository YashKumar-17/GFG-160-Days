### **Approach & Intuition**

1. **Initialize the head of the merged list**:
   - Compare the first nodes of the two lists (`head1` and `head2`).
   - Set `mainhead` to the smaller of the two nodes to serve as the head of the merged list.
   - Advance the pointer (`head1` or `head2`) of the list from which the node was chosen.

2. **Use a traversal pointer (`traverse`)**:
   - Maintain a pointer `traverse` to keep track of the current end of the merged list.
   - Initially, `traverse` points to `mainhead`.

3. **Iteratively merge the two lists**:
   - While at least one of the lists (`head1` or `head2`) is not empty:
     - If one list is empty, attach the remaining nodes of the other list to the merged list.
     - If both lists have nodes, compare the current nodes of `head1` and `head2`:
       - Attach the smaller node to `traverse->next` and advance the respective list pointer (`head1` or `head2`).
     - Move `traverse` forward to the newly added node.

4. **Return the merged list**:
   - Once the merging is complete, return `mainhead` as the head of the new merged sorted list.

### **Key Observations**

- **Initialization**:
  The initial comparison determines the head of the merged list (`mainhead`), ensuring the list remains sorted from the start.

- **While Loop**:
  Handles the merging process, including cases where one of the lists becomes empty before the other.

- **Efficient Traversal**:
  By advancing the `head1`/`head2` pointers and updating `traverse` at each step, you maintain a linear time complexity of (O(n + m)).
### **Why This Works**
The approach is based on the fact that both input lists are sorted. By always selecting the smaller current node (or appending the remaining nodes), the merged list is guaranteed to remain sorted.

Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node* mainhead;
        if(head1->data<=head2->data){
            mainhead=head1;
            head1=head1->next;
        }
        else{
            mainhead=head2;
            head2=head2->next;
        }
        Node* traverse=mainhead;
        while(head1!=NULL || head2!=NULL){
            if(head1==NULL){
                traverse->next=head2;
                traverse=head2;
                head2=head2->next;
            }
            else if(head2==NULL){
                traverse->next=head1;
                traverse=head1;
                head1=head1->next;
            }
            else if(head1->data<=head2->data){
                traverse->next=head1;
                traverse=head1;
                head1=head1->next;
            }
            else{
                traverse->next=head2;
                traverse=head2;
                head2=head2->next;
            }
        }
        return mainhead;
    }
