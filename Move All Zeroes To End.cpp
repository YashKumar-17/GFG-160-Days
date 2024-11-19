Approach Explanation
Initialization:

Declare two pointers:
l (left pointer), initialized to 0. It tracks the current position where a non-zero element should be placed.
r (right pointer), initialized to 1. It traverses the array to find non-zero elements.
Determine the size of the vector n using arr.size().
Iterate through the array:

Use a while loop to iterate as long as r is within the bounds of the array.
Handle three cases during traversal:

Case 1: Current l is zero, and r is non-zero:
Swap arr[l] and arr[r] to move the non-zero element to the left and the zero to the right.
Increment both l and r to check the next elements.
Case 2: Both l and r are zeros:
Increment r to continue searching for the next non-zero element.
Case 3: l points to a non-zero element:
Simply move both pointers (l and r) forward.
Completion:

At the end of the loop, all zeros are pushed to the end of the vector, and the relative order of non-zero elements is preserved.
Key Points
The algorithm efficiently rearranges elements in a single traversal using the two-pointer technique, making its time complexity O(n).
Edge cases, such as arrays with no zeros, all zeros, or arrays of size 1, are handled seamlessly since the logic dynamically adjusts based on the values of l and r.



class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int l=0;
        int r=1;
        int n=arr.size();
        while(r<n){
            if(arr[l]==0 && arr[r]!=0){
                swap(arr[l],arr[r]);
                l++;
                r++;
            }
            else if(arr[l]==0 && arr[r]==0){
                r++;
            }
            else if(arr[l]!=0){
                l++;
                r++;
            }
        }
        
        
    }
};
