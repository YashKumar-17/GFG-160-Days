Approach Explanation
Initialization:

Determine the size of the vector n using arr.size().
Declare two pointers:
l (left pointer), initialized to 0. It starts from the beginning of the array.
r (right pointer), initialized to n-1. It starts from the end of the array.
Iterate and Swap:

Use a while loop that runs as long as l <= r:
Swap elements at l and r:
Exchange the values at the positions l and r using the swap function.
Increment l to move towards the middle from the left.
Decrement r to move towards the middle from the right.
Completion: The loop stops when l and r meet or cross, indicating that the array is fully reversed.

Key Points
The algorithm reverses the vector in-place without requiring additional memory, making its space complexity O(1).
The time complexity is O(n), as the algorithm swaps elements in a single pass through the vector.
The approach handles edge cases, such as empty vectors or vectors with a single element, naturally.


class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int n=arr.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            swap(arr[l],arr[r]);
            l++;
            r--;
        }
    }
};
