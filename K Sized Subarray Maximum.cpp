### **Intuition & Approach**  

The goal is to find the maximum of every **k-sized subarray** in the given array efficiently. Instead of checking every subarray separately (which would be slow), we use a **deque (double-ended queue)** to maintain indices of useful elements.  

### **Step-by-Step Explanation**  

1. **Use a Deque to Store Indices**  
   - The deque will store indices of elements in a way that the **largest element’s index is always at the front**.  

2. **Process Each Element**  
   - **Remove Out-of-Window Elements**: If the front of the deque is out of the current window (i.e., `dq.front() <= i - k`), remove it.  
   - **Maintain Decreasing Order**: Remove elements from the back of the deque if they are **smaller** than the current element, as they will never be useful in future subarrays.  
   - **Insert the Current Index**: Push the current index to the deque.  

3. **Start Recording Maximum Values**  
   - Once the index reaches `k-1`, start pushing `arr[dq.front()]` into the answer list, as `dq.front()` stores the maximum element’s index for the current window.  

### **Time Complexity**  
- **O(N)**: Each element is pushed and popped from the deque at most once.  

This approach efficiently finds the maximum for each window in **linear time** instead of the naive **O(N * K)** approach. 🚀

vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            while(!dq.empty() && arr[dq.back()]<=arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
        
        
    }
