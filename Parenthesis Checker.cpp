### **Intuition**  
The function checks if the given string `s` has balanced parentheses (`()`, `{}`, `[]`). A string is balanced if every opening bracket has a corresponding and correctly placed closing bracket.  

### **Approach**  
1. Use a **stack** to keep track of open brackets.  
2. Traverse the string character by character:  
   - If the stack is **empty**, push the current bracket.  
   - If the **top of the stack** is an **opening bracket** and the current character is its matching **closing bracket**, pop the stack.  
   - Otherwise, push the current character onto the stack.  
3. After iterating through the string:  
   - If the stack is empty, the brackets are balanced → **return true**.  
   - If the stack is **not empty**, there are unmatched brackets → **return false**.  

### **Time Complexity**  
- **O(n)**: Each character is pushed/popped at most once.  
### **Space Complexity**  
- **O(n)**: In the worst case (e.g., all opening brackets), the stack holds all characters.

bool isBalanced(string& s) {
        // code here
        stack<char>stack;
        for(int i=0;i<s.length();i++){
            if(stack.empty()){
                stack.push(s[i]);
                continue;
            }
            if(stack.top()=='(' && s[i]==')'){
                stack.pop();
            }
            else if(stack.top()=='{' && s[i]=='}'){
                stack.pop();
            }
            else if(stack.top()=='[' && s[i]==']'){
                stack.pop();
            }
            else{
                stack.push(s[i]);
            }
        }
        if(!stack.empty()){
            return false;
        }
        return true;
    }
