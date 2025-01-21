### **Approach & Intuition for `reverseKGroup`**

1. **Handle Edge Case (`k == 1`)**:
   - If `k == 1`, no reversal is needed; return the original head.

2. **Reverse the Entire List**:
   - Reverse the entire linked list initially using `prev`, `temp`, and `front` pointers.
   - Calculate the total size of the list during this process.

3. **Determine Remaining Nodes**:
   - Calculate the remainder `r` based on whether the total size is divisible by `k`. This will determine the nodes left for the last incomplete group.

4. **Segregate Groups**:
   - Divide the reversed list into groups of size `k`.
   - For the last incomplete group, if it exists, separate it and reverse it back.

5. **Reattach Groups**:
   - Traverse the reversed list, reverse the nodes within each group of size `k`, and reconnect the groups in order.

6. **Return Final Head**:
   - The head of the fully processed list (`rh`) is returned.

---


Node *reverseKGroup(Node *head, int k) {
        // code here
       if(k==1){
            return head;
        }
        Node* temp=head;
        Node* prev=NULL;
        Node* front=head->next;
        int size=0;
        while(temp!=NULL){
            temp->next=prev;
            prev=temp;
            temp=front;
            if(front!=NULL){
            front=front->next;
            }
            size++;
        }
        if(size==k){
            return prev;
        }
        int r;
        if(size%k==0){
            r=k;
        }
        else{
            r=size%k;
        }
        Node* rh=prev;
        Node* prtemp=prev->next;
        r--;
        while(r--){
            prev=prtemp;
            prtemp=prtemp->next;
        }
        Node* tail=prev;
        tail->next=NULL;
        prev=prtemp;
        prtemp=prtemp->next;
        Node* ph=prev;
        r=0;
        while(prev!=NULL){
            prev=prtemp;
            if(prtemp!=NULL){
            prtemp=prtemp->next;
            }
            r++;
            if(r==k-1){
                prev->next=rh;
                rh=ph;
                prev=prtemp;
                if(prtemp!=NULL){
                prtemp=prtemp->next;
                }
                ph=prev;
                r=0;
            }
        }
        return rh;
    }
