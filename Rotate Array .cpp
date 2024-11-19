Approach Explanation
Adjust the Rotation Index:

Compute d=d%arr.size() to handle cases where d is greater than the size of the array. This ensures only the necessary rotations are performed.
Reverse Subarrays in Three Steps:

Step 1: Reverse the first d elements:

Use two pointers:
l (left pointer) starting at 0.
r (right pointer) ending at d - 1.
Swap elements at l and r while incrementing l and decrementing r until they meet or cross.

Step 2: Reverse the remaining n−d elements:

Update l to d and r to n - 1 (last index of the array).
Perform the same swap process for the subarray from index d to the end.

Step 3: Reverse the entire array:

Reset l to 0 and r to n - 1.
Reverse the entire array to achieve the desired rotated order.
Completion:

After the three steps, the array is effectively rotated to the left by d positions.

Key Points
In-place rotation: The array is rotated without using extra memory, resulting in a space complexity of O(1).
Time complexity: The array is reversed three times, each requiring O(n) operations, so the total time complexity is O(n).
Steps Explained:
The first two reversals break the array into two rotated parts.
The final reversal combines them in the correct order for the rotated array.


class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        d=d%(arr.size());
       int l=0;
       int r=0+d-1;
       int n=arr.size();
       while(l<r){
           swap(arr[l],arr[r]);
           l++;
           r--;
       }
       l=0+d;
       r=n-1;
       while(l<r){
           swap(arr[l],arr[r]);
           l++;
           r--;
       }
       l=0;
       r=n-1;
       while(l<r){
           swap(arr[l],arr[r]);
           l++;
           r--;
       }
    }
};
