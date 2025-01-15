### Approach and Intuition:

1. **Problem Breakdown**:  
   - We aim to find the longest subarray whose sum equals `k`.  
   - This involves using prefix sums and a hashmap to efficiently calculate the required subarray length.

2. **Key Observations**:  
   - The prefix sum (`pre_sum`) is the cumulative sum of elements from the start to the current index.  
   - If the difference between the current prefix sum (`pre_sum`) and `k` exists in the hashmap, it means there’s a subarray with a sum equal to `k`.

3. **Steps in Code**:  
   - **Initialize Variables**:  
     - `len` to store the maximum length of the subarray.  
     - `pre_sum` for the prefix sum.  
     - `ump` (unordered_map) to store `pre_sum` values and their earliest indices.  
   - **Iterate Through Array**:  
     - Add the current element to `pre_sum`.  
     - If `pre_sum == k`, update `len` to `i + 1` as the entire array up to `i` has sum `k`.  
     - Check if `pre_sum - k` exists in `ump`. If yes, update `len` with the maximum of its current value and the length of the subarray from the index stored in `ump` to the current index.  
     - If `pre_sum` is not already in `ump`, store it with its index to ensure only the earliest occurrence is recorded.  
   - **Return `len`**:  
     - This gives the length of the longest subarray with sum `k`.  

This approach ensures an optimal O(n) solution using a sliding window-like technique with prefix sums and hashing.

int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int>ump;
        int len=0;
        int pre_sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            pre_sum+=arr[i];
            if(pre_sum==k){
                len=max(len,i+1);
            }
            int req=pre_sum-k;
            if(ump.find(req)!=ump.end()){
                len=max(len,i-ump[req]);
            }
            if(ump.find(pre_sum)==ump.end()){
                ump[pre_sum]=i;
            }
        }
        return len;
    }
