

### Intuition Behind the Code

1. **Goal**:
   - The task is to find the smallest positive integer missing from the array.

2. **Key Observations**:
   - If the array contains an element `x` such that `1 ≤ x ≤ N` (where `N` is the size of the array), then `x` should ideally be placed at index `x-1`. For example, if `x = 3`, it should be at `arr[2]`.
   - Any number outside the range `1 ≤ x ≤ N` (like negative numbers or numbers greater than `N`) is irrelevant because the smallest missing positive integer must be within `1` to `N+1`.

3. **Approach**:
   - Rearrange the elements in the array such that for every valid `x`, `arr[x-1] = x`. This ensures that each positive integer is at its "correct" position.
   - After this rearrangement, the first index `i` where `arr[i] != i+1` will indicate the missing number `i+1`.

4. **Steps**:
   - **Iterate through the array**:
     - If the current element `arr[i]` is within the range `1 ≤ arr[i] ≤ N` and not already in its correct position (`arr[i] != arr[arr[i] - 1]`), **swap** it with the element at its correct position (`arr[arr[i] - 1]`).
     - Repeat the check for the new element now at `arr[i]` (by decrementing `i` after the swap). This ensures all valid numbers are placed correctly.
   - **Second Pass**:
     - After the rearrangement, iterate through the array again to find the first index `i` where `arr[i] != i+1`. Return `i+1` as the missing number.
   - **Edge Case**:
     - If no such index is found, it means the array contains all integers from `1` to `N`. The missing number in this case is `N+1`.

5. **Example Walkthrough**:
   - Input: `arr = [3, 4, -1, 1]`
   - After swaps:
     - Swap `arr[0]` and `arr[2]` → `[ -1, 4, 3, 1 ]`
     - Swap `arr[3]` and `arr[0]` → `[ 1, 4, 3, -1 ]`
   - Second pass:
     - Index `1` has `arr[1] != 2`, so return `2`.

---

This method ensures an **O(N)** time complexity with **O(1)** extra space, as it rearranges the array in-place and only makes one additional pass to find the result.



int missingNumber(vector<int> &arr) {
        // Your code here
        for(int i=0;i<arr.size();i++){
           
            if(arr[i]!=i+1 && arr[i]>0 && arr[i]<=arr.size()){
                int a=arr[i]-1;
                if(arr[a]!=arr[i]){
                swap(arr[i],arr[a]);
                i--;
                }
            }
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=i+1){
                return i+1;
            }
        }
        return arr.size()+1;
    }
