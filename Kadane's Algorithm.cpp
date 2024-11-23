Approach to Solve Maximum Subarray Sum Using Kadane’s Algorithm
The goal of this algorithm is to find the maximum sum of any contiguous subarray in a given array. Here’s a step-by-step breakdown of the approach:

1. Initialize Key Variables
max_sum: This keeps track of the maximum sum encountered so far. Start with the smallest possible value (INT_MIN) to ensure any subarray sum will be larger.
current_sum: This is used to calculate the sum of the current subarray as we iterate through the array.
2. Traverse the Array
For every element in the array:

Update the Current Sum:
Add the current element to current_sum. This extends the current subarray.

Update Maximum Sum:
Compare current_sum with max_sum and update max_sum if current_sum is larger.

Reset Current Sum if Negative:
If current_sum becomes negative, reset it to 0. Why? A negative sum would only decrease the total sum of any future subarray, so it’s better to start fresh from the next element.

3. Return the Maximum Sum
After iterating through the array, max_sum will hold the largest sum of any contiguous subarray.

Algorithm Efficiency
Time Complexity: O(n) — We iterate through the array once.
Space Complexity: O(1) — Only a few variables are used, no additional data structures.

 int maxSubarraySum(vector<int> &arr) {
        // code here...
        int max_sum=INT_MIN;
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
            max_sum=max(max_sum,sum);
            if(sum<0){
                sum=0;
            }
        }
        return max_sum;
        
    }
