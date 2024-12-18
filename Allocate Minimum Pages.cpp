
Approach for the Solution:
Understanding the Problem:
The problem is about allocating a set of books (represented as an array of integers) to k students such that the maximum number of pages allocated to a student is minimized. 
Each student gets a contiguous sequence of books.

Key Constraints:

If k (number of students) is greater than the size of the array (n), return -1 because allocation is impossible.
The range for the possible "maximum pages" is between the largest single book (low) and the sum of all pages (high).
Binary Search on Result:

Use binary search to find the minimal "maximum pages" (mid).
Check if it's possible to allocate books such that no student gets more than mid pages. This is done using the helper function check.
Helper Function (check):

Iterate through the array and sum pages for each student.
If the sum exceeds mid, allocate books to the next student and increment the count.
Return the count of students needed for the given mid.
Adjust Binary Search:

If more students are required than k (check > k), increase low (i.e., we need a larger mid).
Otherwise, reduce high to explore smaller possible values of mid.
Final Result:

The value of low at the end of the binary search gives the minimal "maximum pages".


int check(vector<int> & arr, int mid){
        int count=1;
        int sum1=0;
        for(int i=0;i<arr.size();i++){
            if(sum1+arr[i]<=mid){
                sum1+=arr[i];
            }
            else{
                count++;
                sum1=arr[i];
            }
        }
        return count;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(k>n){
            return -1;
        }
        int sum=0;
        int low=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(arr[i]>low){
                low=arr[i];
            }
        }
        int high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            int ans=check(arr,mid);
           if(ans>k){
               low=mid+1;
           }
           else{
               high=mid-1;
           }
            
        }
        return low;
    }
