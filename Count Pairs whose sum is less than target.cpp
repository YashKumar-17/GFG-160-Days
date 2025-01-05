Purpose: Counts pairs of numbers in the array arr whose sum is less than target.

Sorting: The array is sorted in ascending order (sort(arr.begin(), arr.end());).

Two Pointers:

l starts from the left (0).
r starts from the right (arr.size() - 1).
Logic:

If arr[l] + arr[r] < target, all pairs between l and r (inclusive of l, exclusive of r) will satisfy the condition. Count these pairs (count += r - l) and move l to the right.
If not, move r to the left.
Return: The total count of valid pairs.

int countPairs(vector<int> &arr, int target) {
        // Your code here
        int l=0;
        int r=arr.size()-1;
        int count=0;
        sort(arr.begin(),arr.end());
        while(l<r){
           if(arr[l]+arr[r]<target){
               count+=r-l;
               l++;
           }
           else{
               r--;
           }
        }
        return count;
    }
