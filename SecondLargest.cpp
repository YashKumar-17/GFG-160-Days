Approach Explanation
Initialization:

Declare three variables:
ans (stores the result), initialized to -1.
largest (stores the largest value encountered so far), initialized to -1.
second_largest (stores the second largest value encountered so far), initialized to -1.
Determine the size of the vector n using arr.size().
Iterate through the array:

Use a loop to traverse all elements in the vector.
Update the largest and second largest values:

Case 1: New largest element found:
If the current element (arr[i]) is greater than largest, update second_largest to the current largest value, and then update largest to the current element (arr[i]).
Case 2: Update second largest:
If the current element is greater than second_largest but smaller than largest, update second_largest to the current element.
Check the second largest value:

After the loop completes, check if second_largest is greater than -1. If so, assign second_largest to ans and return it.
If no valid second largest element exists, return -1 (default value of ans).
Key Points
The code ensures that the largest and second largest values are tracked efficiently in a single traversal of the array, making the time complexity O(n).
Edge cases like arrays with fewer than two elements or arrays with all elements the same are handled gracefully by returning -1 if no valid second largest element is found.






class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int ans=-1;
        int largest=-1;
        int second_largest=-1;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>largest){
                second_largest=largest;
                largest=arr[i];
            }
            if(arr[i]>second_largest && arr[i]<largest){
                second_largest=arr[i];
            }
        }
        if(second_largest>-1){
            ans=second_largest;
            return ans;
        }
        return ans;
    }
};
