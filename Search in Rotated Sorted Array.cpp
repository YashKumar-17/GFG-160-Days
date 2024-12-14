Approach Explanation for the Code:
This code implements a binary search algorithm to find a key in a sorted and rotated array. The steps and logic used in the code are as follows:

1. Initial Setup
The array is assumed to be sorted but rotated at some pivot point.
Two pointers, low and high, are initialized to represent the range of the search:
low starts at the beginning of the array (index 0).
high starts at the end of the array (index n-1).

2. Iterative Binary Search
The algorithm repeatedly calculates the middle index (mid) of the current range.

3. Key Found
If the key is found at arr[mid], the index mid is returned immediately.

4. Determining Which Side of the Array to Search
Since the array is rotated, at least one of the two halves of the current range will always be sorted. The code checks which half is sorted and decides the direction to continue searching:

Left Half is Sorted (arr[low] < arr[mid]):

If the key lies within the sorted left half (key >= arr[low] && key < arr[mid]), move high to mid - 1.
Otherwise, search in the right half by setting low = mid + 1.
Right Half is Sorted (arr[low] > arr[mid]):

If the key lies within the sorted right half (key >= arr[low] or key < arr[mid]), move high to mid - 1.
Otherwise, search in the left half by setting low = mid + 1.

5. Key Not Found
If the loop ends without finding the key, -1 is returned, indicating the key is not present in the array.

Time Complexity:
O(log N): The search space is halved in each iteration.
Space Complexity:
O(1): No extra space is used, as the algorithm operates directly on the input array.


int search(vector<int>& arr, int key) {
        // complete the function here
        int n=arr.size();
        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==key){
                ans=mid;
                return ans;
            }
            else if((arr[low]<arr[mid] )&& (key>=arr[low] && key<arr[mid])){
                high=mid-1;
            }
            else if((arr[low]>arr[mid]) && ((key>=arr[low]) || (key<arr[mid])) ){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
        return ans;
    }
