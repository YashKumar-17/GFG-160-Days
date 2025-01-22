### **Approach and Intuition:**

This code adds two numbers represented as linked lists, where each node contains a single digit. The most significant digit is at the head of the list. Here’s a concise breakdown of the approach:

---

1. **Calculate Sizes of Both Lists**:
   - Traverse the two lists to find their sizes (`size1` and `size2`).

2. **Align Lists by Padding Zeros**:
   - If one list is shorter, append the elements of the longer list directly to the result until the sizes are equal.
   - Add corresponding digits from both lists after aligning.

3. **Handle Carry for Each Digit**:
   - Traverse the resulting list of sums from the least significant digit to the most significant digit.
   - Adjust for carry:
     - If the sum exceeds 9, update the current digit and propagate the carry to the next.

4. **Handle Leftover Carry**:
   - If there's a carry after processing all digits, create a new node for it at the head of the result.

5. **Build the Result List**:
   - Construct the final linked list using the adjusted digit values.

6. **Edge Case (Leading Zeros)**:
   - Skip leading zeros when constructing the result to avoid unnecessary nodes.

---

### **Steps Summary**:
- Align the two lists by their sizes.
- Sum the corresponding digits, handling carry.
- Add leftover carry if present.
- Construct and return the final result linked list.

This method ensures accurate addition with minimal extra memory usage, apart from a temporary vector for storing intermediate sums.


Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        int size1=0;
        int size2=0;
        Node* temp1=num1;
        Node* temp2=num2;
        while(temp1!=NULL){
            temp1=temp1->next;
            size1++;
        }
        while(temp2!=NULL){
            temp2=temp2->next;
            size2++;
        }
        vector<int>ans;
        if(size1>=size2){
            temp1=num1;
            temp2=num2;
            int count=size1-size2;
            while(count!=0){
                ans.push_back(temp1->data);
                temp1=temp1->next;
                count--;
            }
            while(temp1!=NULL){
                ans.push_back(temp1->data+temp2->data);
                temp1=temp1->next;
                temp2=temp2->next;
            }
            
        }
        else{
            temp1=num1;
            temp2=num2;
            int count=size2-size1;
            while(count!=0){
                ans.push_back(temp2->data);
                temp2=temp2->next;
                count--;
            }
            while(temp2!=NULL){
                ans.push_back(temp1->data+temp2->data);
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        int carry=0;
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i]+carry > 9){
                ans[i]=ans[i]+carry-10;
                carry=1;
            }
            else{
                ans[i]=ans[i]+carry;
                carry=0;
            }
        }
        Node* add;
        Node* temp3;
        int start=0;
        if(carry>0){
        add=new Node(carry);
        temp3=add;
        }
        else{
            for(int i=0;i<ans.size();i++){
                if(ans[i]!=0){
                    add=new Node(ans[i]);
                    temp3=add;
                    start=i+1;
                    break;
                }
            }
        }
        for(int i=start;i<ans.size();i++){
            int val=ans[i];
            temp3->next=new Node(val);
            temp3=temp3->next;
        }
        return add;
    }
