 Approach: 

The problem of finding the maximum sum of a circular subarray can be solved by considering two scenarios:

Non-Circular Maximum Subarray: Use Kadane's algorithm to find the maximum subarray sum.
Circular Maximum Subarray: This involves the sum of elements that "wrap around" the end and start of the array. To compute this, subtract the minimum subarray sum from the total array sum.
Steps:

Compute Total Sum and Minimum Subarray Sum:

Traverse the array to calculate the total sum of all elements (total_sum) and the minimum subarray sum (min_sum).
Use a running sum (sum) that resets to 0 whenever it becomes positive to compute the minimum sum.
Compute Maximum Subarray Sum (Kadane's Algorithm):

Traverse the array to calculate the maximum subarray sum (max_sum).
Use a running sum (sum) that resets to 0 whenever it becomes negative to compute the maximum sum.
Handle the Two Cases:

Non-circular maximum sum is simply max_sum.
Circular maximum sum is total_sum - min_sum.
Return the Result:

Compare max_sum and total_sum - min_sum to get the final answer.
If all elements are negative, return max_sum directly (as total_sum - min_sum might overcount).
Final Formula:

result = max(max_sum, total_sum - min_sum)
This efficiently computes the maximum circular subarray sum in O(n) time with O(1) space.





int circularSubarraySum(vector<int> &arr) {

        // your code here
        int start=0;
        int min_sum=INT_MAX;
        int sum=0;
        int n=arr.size();
        int total_sum=0;
        for(int i=0;i<n;i++){
            total_sum+=arr[i];
            sum+=arr[i];
            if(sum<min_sum){
                min_sum=sum;
            }
            if(sum>0){
                sum=0;
            }
        }
        sum=0;
        int max_sum=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>max_sum){
                max_sum=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        int ans=max(max_sum,total_sum-min_sum);
        return ans;
       
    }
