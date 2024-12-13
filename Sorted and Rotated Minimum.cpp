1. Understanding the Problem:
A rotated sorted array is a sorted array that has been shifted some number of positions to the right or left. 
The task is to find the minimum element in this array efficiently. Using binary search helps achieve a time complexity of O(logn).

2. Variables Used:
low: Starting index of the current search range.
high: Ending index of the current search range.
ans: A variable to store the minimum value encountered during the search, initialized to INT_MAX.

3. Binary Search Logic:
The array is searched by repeatedly dividing it into halves:

Calculate Midpoint: mid=low+(high−low)/2

Check if Left Half is Sorted:

If arr[low] <= arr[mid], it means the left portion is sorted. The smallest element in this range is arr[low]. Compare arr[low] with ans and update ans if necessary.
Move to the right half by setting low = mid + 1.
Otherwise, Right Half is Sorted:

If arr[low] > arr[mid], the right portion is unsorted, and the smallest element must be in this range. Compare arr[mid] with ans and update ans if necessary.
Move to the left half by setting high = mid - 1.
Repeat Until Search Range is Exhausted:
The loop continues as long as low <= high.

4. Return the Result:
After exiting the loop, ans contains the minimum value in the rotated sorted array.



int findMin(vector<int>& arr) {
        // complete the function here
         int n=arr.size();
       int low=0;
       int high=n-1;
       int ans=INT_MAX;
       while(low<=high){
           int mid=low+(high-low)/2;
           if(arr[low]<=arr[mid]){
               ans=min(ans,arr[low]);
               low=mid+1;
           }
           else{
               ans=min(ans,arr[mid]);
               high=mid-1;
           }
       }
       return ans;
    }
