### **Intuition:**  
We need to find the `k` largest elements from an unsorted array efficiently. A **min-heap (priority queue)** helps maintain the top `k` largest elements while iterating through the array.

### **Approach:**  
1. **Use a Min-Heap:** Maintain a min-heap (`pq`) of size `k`.  
2. **Insert First k Elements:** Push the first `k` elements into `pq`.  
3. **Process Remaining Elements:** For each remaining element,  
   - If it's larger than `pq.top()`, remove the smallest element (`pq.pop()`) and insert the new element.  
4. **Extract Elements:** Store elements from `pq` into `ans` in descending order.  

**Time Complexity:** (O(n log k)), where (n) is the size of `arr`.

vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        priority_queue<int, vector<int>, greater<int>>pq;
        vector<int>ans(k);
        for(int i=0;i<arr.size();i++){
            if(i>=k){
              if(arr[i]>pq.top()){
                  pq.pop();
                  pq.push(arr[i]);
              }
            }
            else{
                pq.push(arr[i]);
            }
        }
        int i=k-1;
        while(!pq.empty()){
            ans[i]=pq.top();
            i--;
            pq.pop();
        }
        return ans;
    }
