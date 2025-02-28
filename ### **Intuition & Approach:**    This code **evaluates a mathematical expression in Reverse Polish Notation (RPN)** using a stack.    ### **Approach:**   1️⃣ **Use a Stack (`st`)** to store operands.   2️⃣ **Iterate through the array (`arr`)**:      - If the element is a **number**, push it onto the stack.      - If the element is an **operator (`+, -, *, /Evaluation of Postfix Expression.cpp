### **Intuition & Approach:**  

This code **evaluates a mathematical expression in Reverse Polish Notation (RPN)** using a stack.  

### **Approach:**  
1️⃣ **Use a Stack (`st`)** to store operands.  
2️⃣ **Iterate through the array (`arr`)**:  
   - If the element is a **number**, push it onto the stack.  
   - If the element is an **operator (`+, -, *, /`)**:  
     - Pop the top two numbers from the stack.  
     - Perform the operation.  
     - Push the result back onto the stack.  
3️⃣ **Final Result**: The top of the stack contains the evaluated expression.  

### **Key Takeaway:**  
Stacks make it easy to evaluate **postfix expressions (RPN)** efficiently in **O(N) time**, without needing parentheses! 🚀

int evaluate(vector<string>& arr) {
        // code here
       stack<int> st;
        int n= arr.size();
        int i = 0;
        
        while(i<n){
            string x = arr[i];
            if(isdigit(x[0]) || (x[0] == '-' && x.size() > 1)){
                int num = stoi(x);
                st.push(num);
            }
            else{
                    int num2 = st.top();
                    st.pop();
                    int num1 = st.top();
                    st.pop();
                    int newNum ;
                    if(x == "*"){
                        newNum = num1*num2;
                    }
                    else if(x == "/"){
                        newNum = num1/num2;
                    }
                    else if(x == "-"){
                         newNum = num1-num2;
                    }
                    else if(x == "+"){
                         newNum = num1+num2;
                    }
                    st.push(newNum);
                }
            i++;
        }
        return st.top();
    }
