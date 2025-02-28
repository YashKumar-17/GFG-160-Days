### **Intuition & Approach:**  

This code implements a **Min Stack**, which supports `push()`, `pop()`, `peek()`, and `getMin()` operations in **O(1) time** while keeping track of the minimum element.  

### **Approach:**  
1️⃣ **Use a Stack of Pairs (`st`)**  
   - Each entry stores `{value, current minimum}`.  

2️⃣ **Push Operation (`push(x)`)**  
   - Update `ele` to track the **minimum so far**.  
   - Push `{x, ele}` into the stack.  

3️⃣ **Pop Operation (`pop()`)**  
   - Remove the top element.  
   - Update `ele` to the new **minimum** if the stack is not empty.  

4️⃣ **Peek Operation (`peek()`)**  
   - Return the **top element** of the stack.  

5️⃣ **Get Min (`getMin()`)**  
   - Return the **minimum element** in constant time.  

### **Key Takeaway:**  
By storing the minimum alongside each value, we efficiently retrieve the smallest element at any time without extra traversal! 🚀

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
