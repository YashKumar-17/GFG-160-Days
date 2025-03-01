### **Intuition:**  
The function **`decodedString`** decodes an encoded string that follows the pattern **`k[encoded_string]`**, 
where `k` is a number representing how many times the enclosed string should be repeated. The function reconstructs the decoded string using a **stack-based approach**.

### **Approach (Step-by-Step):**  

1. **Use a stack** to process characters one by one.  
2. **Push characters** onto the stack until a closing bracket `']'` is found.  
3. **When `']'` is encountered**:  
   - Extract the substring inside brackets by popping characters until `'['`.  
   - Extract the number (`k`) before `'['`, which represents how many times the substring should be repeated.  
4. **Repeat the substring `k` times** and push it back onto the stack.  
5. **Rebuild the final decoded string** by popping all elements from the stack in reverse order.  
6. **Return the decoded result.**  

---

### **Example Walkthrough:**  

**Input:** `"3[a2[bc]]"`  
**Stack Operations:**  
1. `3[a2[bc]]` → Push `"3[a2[bc]"` into the stack.  
2. Encounter `']'` → Extract `"bc"`, find `2`, repeat `"bc"` → **"bcbc"`.  
3. Encounter next `']'` → Extract `"a"`, find `3`, repeat `"a" + "bcbc"` → **"abcbcabcbcabcbc"`.  
4. Stack contains the decoded string, return **"abcbcabcbcabcbc"**.  

### **Time Complexity:**  
- **O(N)** → Each character is processed at most twice (once pushed, once popped).

string decodedString(string &s) {
        // code here
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]!=']') st.push(s[i]);
            else{
                string word;
                while(!st.empty() && st.top()!='['){
                    word.push_back(st.top());
                    st.pop();
                }
                reverse(word.begin(),word.end());
                st.pop();
                string k;
                while(!st.empty() && isdigit(st.top())){
                    k.push_back(st.top());
                    st.pop();
                }
                reverse(k.begin(),k.end());
                int num=stoi(k);
                string repeated;
                for(int j=0;j<num;j++){
                    repeated.append(word);
                }
                for(char c: repeated) st.push(c);
            }
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
