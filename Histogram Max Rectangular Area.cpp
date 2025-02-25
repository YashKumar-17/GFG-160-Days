### **Intuition and Approach:**  
The goal is to find the largest rectangular area in a histogram, where the heights of bars are given in `arr`.  

1. **Using a Monotonic Stack:**  
   - The stack helps in efficiently finding the **next smaller element (NSE)** and **previous smaller element (PSE)** for each bar.  
   - The width of the rectangle for each bar is determined using `NSE - PSE - 1`.  

2. **First Pass (Left to Right Traversal):**  
   - Iterate through `arr` and maintain a **monotonic increasing stack**.  
   - If the current height is smaller than the top of the stack, process the top element (calculate area using NSE and PSE).  
   - Push the current index into the stack.  

3. **Second Pass (Processing Remaining Elements):**  
   - Any bars left in the stack mean they extend till the end of the histogram (`NSE = arr.size()`).  
   - Pop elements and calculate their area using `NSE - PSE - 1`.  

4. **Max Area Calculation:**  
   - Update `maxi` whenever a larger rectangle is found.  
   - Finally, return the maximum area found.  

This approach ensures **O(N) time complexity**, as each element is pushed and popped from the stack at most once. 🚀

int getMaxArea(vector<int> &arr) {
        // Your code here
        int maxi=0;
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int nse=i;
                int ele=st.top();
                st.pop();
                int pse=st.empty()?-1:st.top();
                maxi=max(maxi, arr[ele]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            if(st.size()>1){
                int ele=st.top();
                st.pop();
                int nse=arr.size();
                int pse=st.top();
                maxi=max(maxi, arr[ele]*(nse-pse-1));
            }
            else{
                int ele=st.top();
                st.pop();
                int nse=arr.size();
                int pse=-1;
                maxi=max(maxi, arr[ele]*(nse-pse-1));
            }
        }
        return maxi;
    }
