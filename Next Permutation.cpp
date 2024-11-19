Approach
The task is to rearrange the given sequence into the lexicographically next greater permutation. If no such permutation exists (i.e., the sequence is sorted in descending order), 
we rearrange it into the smallest permutation (i.e., sorted in ascending order).

The algorithm can be broken down into the following steps:

Step 1: Identify the Break Point
Definition: A break point is the first index i from the right (end of the array) such that arr[i] > arr[i-1].
Why this is important: This indicates that the subarray from i to the end is in descending order, and we need to modify the array starting from index i-1 to get the next permutation.
Procedure:
Start iterating from the rightmost end of the array.
Find the first index i-1 where arr[i-1] < arr[i]. Store this index as bp.
If no such bp is found, the entire array is in descending order, and we directly proceed to Step 3 to reverse the array.
Step 2: Swap the Break Point
Goal: To find the next larger number to replace arr[bp] (element at the break point) while maintaining lexicographic order.
Procedure:
From the rightmost end of the array, find the smallest element greater than arr[bp].
Swap arr[bp] with this element.
This ensures that the new number is just slightly larger than the original at bp.
Step 3: Reverse the Right Subarray
Goal: After swapping, the subarray to the right of bp is still in descending order. Reversing it makes it the smallest lexicographic arrangement for that subarray.
Procedure:
Reverse the subarray starting from index bp+1 to the end of the array.
Step 4: Handle Edge Case
If there is no break point (i.e., bp == -1), it means the array is sorted in descending order, which is the last permutation.
Directly reverse the entire array to transform it into the smallest permutation.

Complexity Analysis
Time Complexity:

Finding the break point: O(n)
Finding the next greater element: O(n)
Reversing the subarray: O(n)
Total: O(n).
Space Complexity: O(1) since we modify the array in place.



class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int bp=-1;
        int n=arr.size();
        for(int i=n-1;i>0;i--){
            if(arr[i]>arr[i-1]){
                bp=i-1;
                break;
            }
            
        }
        if(bp!=-1){
        for(int i=n-1;i>bp;i--){
            if(arr[i]>arr[bp]){
                swap(arr[i],arr[bp]);
                break;
            }
        }
        reverse(arr.begin()+bp+1,arr.end());
        }
        else{
            reverse(arr.begin(),arr.end());
        }
    }
};
