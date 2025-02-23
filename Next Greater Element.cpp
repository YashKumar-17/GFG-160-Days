### **Intuition:**
The goal of this function is to find the **Next Greater Element (NGE)** for each element in the array. The **Next Greater Element** for an element is the first greater element to its **right** in the array. If no such element exists, we return **-1**.

### **Approach:**
1. **Use a Stack:**  
   - The stack helps efficiently find the NGE for each element in **O(n)** time.
   
2. **Traverse the Array in Reverse (Right to Left):**  
   - Start from the last element and move to the first.
   - This ensures we process future elements before current ones.

3. **Maintain a Monotonic Decreasing Stack:**  
   - While the **stack is not empty** and the **top element is smaller than or equal to the current element**, pop elements from the stack (since they can’t be the NGE for this element).
   - If the stack is empty after popping, there is no NGE, so store **-1**.
   - Otherwise, the **top of the stack** is the NGE, so store it.

4. **Push the Current Element into the Stack:**  
   - This ensures it can be the NGE for future elements.

### **Complexity:**  
- **Time Complexity:** **O(n)** (each element is pushed and popped at most once).  
- **Space Complexity:** **O(n)** (for the result array and stack).

vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
