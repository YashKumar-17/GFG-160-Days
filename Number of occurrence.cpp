### **Approach to Count Frequency of a Target in a Sorted Array**

1. **Input and Setup:**
   - The function takes a sorted vector `arr` and an integer `target` as input.
   - Variables are initialized as follows:
     - `n` stores the size of the array.
     - `fst` is initialized to `n` (representing the first occurrence index of the target, set to an invalid index initially).
     - `lst` is initialized to `-1` (representing the last occurrence index of the target, also set to an invalid index initially).
     - `low` and `high` are used for binary search, initialized to `0` and `n-1`, respectively.

---

2. **Finding the First Occurrence of the Target:**
   - A **binary search** is performed to find the first occurrence of `target`:
     - Compute `mid` as the middle index: `mid = low + (high - low) / 2`.
     - If `arr[mid] == target`:
       - Update `fst` to the smaller of `mid` and the current `fst`.
       - Move `high` to `mid - 1` to continue searching in the left half for an earlier occurrence.
     - If `arr[mid] > target`:
       - Move `high` to `mid - 1` (since the target must be in the left half).
     - Otherwise (`arr[mid] < target`):
       - Move `low` to `mid + 1` (since the target must be in the right half).

---

3. **Finding the Last Occurrence of the Target:**
   - A second **binary search** is performed to find the last occurrence of `target`:
     - Compute `mid` as the middle index: `mid = low + (high - low) / 2`.
     - If `arr[mid] == target`:
       - Update `lst` to the larger of `mid` and the current `lst`.
       - Move `low` to `mid + 1` to continue searching in the right half for a later occurrence.
     - If `arr[mid] > target`:
       - Move `high` to `mid - 1`.
     - Otherwise (`arr[mid] < target`):
       - Move `low` to `mid + 1`.

---

4. **Checking if Target Exists:**
   - After both binary searches, if `fst` remains `n` and `lst` remains `-1`, it means the target is not found in the array. Return `0`.

---

5. **Returning the Frequency:**
   - If the target exists, the frequency is calculated as `(lst - fst + 1)`:
     - `lst` represents the index of the last occurrence of the target.
     - `fst` represents the index of the first occurrence of the target.
     - Subtracting these indices and adding `1` gives the count of occurrences.

---

### **Time Complexity:**
- Each binary search runs in (O(log n)), and since there are two binary searches, the overall time complexity is \(O(\log n)\).

### **Space Complexity:**
- The space complexity is (O(1)) as no extra space is used apart from variables.


int countFreq(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int fst=n;
        int lst=-1;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                fst=min(mid,fst);
                high=mid-1;
            }
            else if(arr[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
        low=0;
        high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                lst=max(mid,fst);
                low=mid+1;
            }
            else if(arr[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
        if(fst==n && lst==-1){
            return 0;
        }
        return (lst-fst+1);
    }
