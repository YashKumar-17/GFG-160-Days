Initialization:
Create a map mpp to store prefix sums and their counts. Initialize it with mpp[0] = 1 to handle cases where the subarray itself equals k.
Initialize two variables: prs (prefix sum) to 0 and count (to count subarrays) to 0.
Iterate through the array:
For each element in the array, add it to prs to calculate the cumulative sum (prefix sum) up to the current index.
Check for subarrays with sum k:
Calculate rmv = prs - k, which represents the prefix sum that would need to exist in order for a subarray ending at the current index to have a sum of k.
If rmv is found in mpp, it means there are mpp[rmv] subarrays that satisfy the condition. Add mpp[rmv] to count.
Update the prefix sum map:
Increment the count of the current prefix sum prs in the map mpp.
Return the result:
Once the iteration is complete, return the value of count, which holds the total number of subarrays with sum k.
Complexity Analysis:
Time Complexity:

The loop iterates through the array exactly once, and each map operation (insert or lookup) takes O(1) on average.
Thus, the overall time complexity is O(n), where n is the size of the array.
Space Complexity:

The map mpp stores at most n+1 unique prefix sums in the worst case (one for each subarray sum and the initial 0).
Therefore, the space complexity is O(n).

int countSubarrays(vector<int> &arr, int k) {
        // code here
        map<int,int>mpp;
        mpp[0]=1;
        int prs=0;
        int count=0;
        for(int i=0;i<arr.size();i++){
            prs+=arr[i];
            int rmv=prs-k;
            count+=mpp[rmv];
            mpp[prs]++;
        }
        return count;
    }
