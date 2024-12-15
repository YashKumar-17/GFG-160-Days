 ### Approach for the Peak Element Function

#### 1. **Handle Base Cases**
   - If the array has only one element, it is trivially the peak element. Hence, return `0` as its index.
   - If the first element (`arr[0]`) is greater than the second element (`arr[1]`), it is a peak. Return `0`.
   - If the last element (`arr[n-1]`) is greater than the second last element (`arr[n-2]`), it is a peak. Return `n-1`.

---

#### 2. **Binary Search on the Remaining Elements**
   - The idea is to use binary search to efficiently find a peak element in `O(log n)` time.
   - Define the search range as `low = 1` and `high = n-2`, excluding the first and last elements (since they were handled in the base cases).

---

#### 3. **Binary Search Logic**
   - Calculate the middle index:  
     mid = low + (high - low) /2;
   - Check the following conditions:
     1. **Peak Condition**: If `arr[mid] > arr[mid-1]` and `arr[mid] > arr[mid+1]`, `arr[mid]` is a peak. Return `mid`.
     2. **Move Right**: If `arr[mid] < arr[mid+1]`, the peak must lie to the right (since the array is "increasing" at `mid`). Update `low = mid + 1`.
     3. **Move Left**: If `arr[mid] < arr[mid-1]`, the peak must lie to the left (since the array is "increasing" towards the left). Update `high = mid - 1`.
     4. **Move either left or right: If you found a base element which is less than left as well as right element.

---

#### 4. **Edge Case**
   - If no peak is found, return `-1`. However, this situation is theoretically impossible since the problem guarantees the presence of a peak.

---

### Complexity Analysis
- **Time Complexity**:  
  Binary search is used, reducing the search range by half at each step. Thus, the time complexity is (O(log n)).
  
- **Space Complexity**:  
  The algorithm uses constant space, (O(1)), as it operates directly on the input array without additional data structures.

int peakElement(vector<int> &arr) {
        // Your code here
         int n=arr.size();
         if(n==1){
             return 0;
         }
         if(arr[0]>arr[1]){
             return 0;
         }
         else if(arr[n-1]>arr[n-2]){
             return n-1;
         }
         int low=1;
         int high=n-2;
         while(low<=high){
             int mid=low+(high-low)/2;
             if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                 return mid;
             }
             else if(arr[mid]<arr[mid+1]){
                 low=mid+1;
             }
             else if(arr[mid]<arr[mid-1]){
                 high=mid-1;
             }
             else{
                 low=mid+1;
             }
         }
         return -1;
         
    }
