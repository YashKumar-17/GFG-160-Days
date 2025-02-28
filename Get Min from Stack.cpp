### **Intuition & Approach:**  

1. **Find Previous & Next Smaller Elements:**  
   - Use a stack to find the nearest smaller element on the left (`preSmall`) and right (`nextSmall`) for each index.  
   - This helps determine the maximum window size where an element is the minimum.  

2. **Store Elements with Their Window Size:**  
   - Each element contributes as the **minimum** in a window of size `nextSmall[i] - preSmall[i] - 1`.  

3. **Sort by Element Value (Descending):**  
   - Sorting ensures we process larger values first, maintaining correctness.  

4. **Fill the Answer Array:**  
   - Assign the highest possible value for each window size to get the **maximum of minimums** for all window sizes.  

**Result:** We obtain an array where each index `i` contains the **max of min values for window size (i+1)**. 🚀

stack<pair<int,int>>st;
    int ele=INT_MAX;
    Solution() {
        // code here
    }
    void push(int x) {
        // code here
        ele=min(ele,x);
        st.push({x,ele});
    }
    void pop() {
        // code here
        if(!st.empty())
        st.pop();
        if(!st.empty())
        {
            ele=st.top().second;
        }
        else
        {
            ele=INT_MAX;
        }
    }
    int peek() {
        if(!st.empty())
        return st.top().first;
        else
        return -1;
        // code here
    }
    int getMin() {
        // code here
        if(!st.empty())
        return st.top().second;
        else
        return -1;
    }
