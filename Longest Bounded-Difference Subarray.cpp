### **Intuition & Approach**  

This code finds the **longest subarray** where the difference between the maximum and minimum elements is at most `x`. It uses the **sliding window technique** along with **monotonic deques** for efficient min/max tracking.

#### **Approach:**
1. **Use two deques (`mn` and `mx`)**  
   - `mn` keeps track of the **minimum values** in the current window.  
   - `mx` keeps track of the **maximum values** in the current window.  
   
2. **Expand the window (`j` moves forward)**  
   - Insert `arr[j]` in `mn` and `mx` while maintaining their order.  
   - If the condition `max - min ≤ x` holds, update the result if this is the longest subarray so far.  

3. **Shrink the window (`i` moves forward) if needed**  
   - If the condition `max - min > x` is violated, remove `arr[i]` from `mn` and `mx` if it was at the front, then increment `i`.  

4. **Store the longest valid subarray**  
   - The indices `(st, en)` track the longest valid window.  
   - Extract and return the subarray from `arr[st]` to `arr[en]`.  

#### **Efficiency:**  
- **Deque operations are O(1)** → Efficient min/max updates.  
- **Sliding window ensures O(N) complexity**, making the solution optimal.

vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        int i=0,j=0;
        deque<int> mn,mx;
        int st=0,en=0;
        while(j<n){
            while(!mn.empty() && mn.back()>arr[j]) mn.pop_back();
            while(!mx.empty() && mx.back()<arr[j]) mx.pop_back();
            mx.push_back(arr[j]);
            mn.push_back(arr[j]);
            if(!mx.empty() && !mn.empty() && (mx.front()-mn.front() <= x)){
                if((en-st)<(j-i)) { en=j; st=i; };
                j++;
            }else if(i<j && !mx.empty() && !mn.empty() && (mx.front()-mn.front() > x)){
                if(arr[i]==mn.front()) mn.pop_front();
                if(arr[i]==mx.front()) mx.pop_front();
                i++;j++;
            }
        }
        if(st==en) return {arr[0]};
        vector<int> res;
        for(int i=st;i<=en;i++) res.push_back(arr[i]);
        return res;
        
    }
