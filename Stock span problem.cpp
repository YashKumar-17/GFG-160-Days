### **Intuition:**
The problem is to find the stock span for each day, which means determining how many consecutive days (including the current day) the stock price has been less than or equal to the current day's price. This is similar to the **"Next Greater Element"** problem but in a backward direction.

### **Approach:**
1. **Use a stack** to keep track of elements in a **monotonically decreasing order** (i.e., the highest element is at the bottom).
2. **Iterate through the array**:
   - Pop elements from the stack while they are **smaller or equal** to the current price.
   - If the stack is empty, it means no greater element exists on the left, so the span is **(i + 1)**.
   - Otherwise, the top of the stack gives the last highest element's index, so the span is **(i - top's index)**.
3. **Push the current price with its index** onto the stack.

### **Time Complexity:**  
- Each element is pushed and popped **at most once** → **O(N)**  
- Efficient compared to a brute-force **O(N²)** approach.

vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        int n=arr.size();
        vector<int>ans(n);
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first<=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=i+1;
            }
            else{
                ans[i]=i-st.top().second;
            }
            pair<int,int>pr(arr[i],i);
            st.push(pr);
        }
        return ans;
    }
