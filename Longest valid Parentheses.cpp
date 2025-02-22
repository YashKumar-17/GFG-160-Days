### **Intuition:**  
The code finds the **length of the longest valid parentheses substring** in a given string `s` consisting of `(` and `)`. It uses a **stack-based approach** to track the indices of unmatched parentheses and determine the longest valid segment.  

### **Approach:**  
1. **Initialize a stack** `st` and push `-1` (serves as a base index for valid substrings).  
2. **Iterate through the string `s`**:
   - If `s[i]` is `')'` and the top of the stack holds `'('`, pop the stack (this means we found a valid pair).  
   - Otherwise, push the index `i` to the stack (to track unmatched parentheses).  
3. **Calculate the longest valid substring**:
   - The remaining indices in the stack represent **invalid positions**.
   - By popping elements and computing gaps between indices, we determine the longest valid substring.  
4. **Return the maximum valid length found.**  

int maxLength(string& s) {
        // code here
       stack<int>st;
       st.push(-1);
       for(int i=0;i<s.length();i++){
           if(s[i]==')' && !st.empty() && s[st.top()]=='('){
               st.pop();
           }
           else{
               st.push(i);
           }
       }
       int maxi=s.length();
       int ans=0;
       while(!st.empty()){
           int com=st.top();
           st.pop();
           ans=max(ans,maxi-com-1);
           maxi=com;
       }
       return ans;
    }
