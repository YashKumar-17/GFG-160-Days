 Approach for Finding the Kth Missing Element:
Understanding the Problem:

You are given a sorted array of unique positive integers, starting from 1.
Some numbers in the sequence are missing, and the goal is to find the kth missing number.

Key Idea:

For an element arr[i], the number of missing elements before it is given by:
missing = arr[i] - (i + 1).
This formula works because:
arr[i] gives the actual number at index i.
i + 1 gives the expected number at index i if no elements were missing.

Binary Search:

Use binary search to find the position where the count of missing numbers becomes greater than or equal to k.

Adjust low and high based on the number of missing elements up to mid:
If missing < k, move low to mid + 1.
Otherwise, move high to mid - 1.
Post-Search Calculation:

After the binary search ends, high will point to the last element where the count of missing numbers is less than k.

If high < 0, it means all missing numbers are before the smallest element of the array, and the result is simply k.
Otherwise, compute the result as:
arr[high] + (k - missing_at_high),
where missing_at_high = arr[high] - (high + 1).

Edge Cases:

If k is less than the first missing number, return k.
If k is greater than all possible missing numbers in the array, return the appropriate value based on the last element.


int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low);
            if(arr[mid]-(mid+1)<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(high<0){
            return 0+k;
        }
        return arr[high]+(k-(arr[high]-(high+1)));
        
    }
