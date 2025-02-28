### **Intuition and Approach:**

This function **finds the maximum of minimum values for every possible window size** in the given array. Here's how it works:

1. **Find the Previous and Next Smaller Elements:**  
   - For each element, determine the nearest smaller element on the left (`preSmall`) and the nearest smaller element on the right (`nextSmall`).
   - These help in identifying the largest possible window size where the element is the minimum.

2. **Determine Window Sizes:**  
   - Each element contributes as the **minimum** in a window of size `nextSmall[i] - preSmall[i] - 1`.

3. **Sort Elements by Value:**  
   - Store each element along with its valid window size in `maxEle` and **sort in descending order** based on element values.

4. **Fill the Answer Array:**  
   - Assign the **largest possible value** for each window size in the `ans` array by iterating through sorted `maxEle`.

### **End Result:**  
The `ans` array contains the maximum of minimum values for every possible window size **from 1 to n**.

vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        //finding pre and next smaller for each i
        int n = arr.size();
        vector<int>preSmall(n);
        vector<int>nextSmall(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                preSmall[i] = -1;
            }
            else{
                preSmall[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                nextSmall[i] = n;
            }
            else{
                nextSmall[i] = st.top();
            }
            st.push(i);
        }

        //grouping each i with maximum window size
        vector<pair<int,int>>maxEle;
        for(int i=0;i<n;i++){
            maxEle.push_back({arr[i],nextSmall[i]-preSmall[i]-1});
        }
        
        //sort to get maximum ele first
        sort(maxEle.begin(),maxEle.end(),greater<pair<int,int>>());

        //update ans
        vector<int>ans(n);
        int start = 0;
        for(int i=0;i<n;i++){
            if(maxEle[i].second<=start){
                continue;
            }
            for(int j=start;j<maxEle[i].second;j++){
                ans[j] = maxEle[i].first;
            }
            start = maxEle[i].second;
        }
        return ans;
    }
