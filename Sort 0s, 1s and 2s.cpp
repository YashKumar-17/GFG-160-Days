This code efficiently sorts an array containing only three types of elements: 0, 1, and 2. 
The problem is inspired by the Dutch National Flag Problem, which is solved using a three-pointer approach. 
The goal is to sort the array in a single traversal (O(n) time complexity) without using extra space.

Intuition
The idea is to divide the array into three regions:

Region for 0s: From index 0 to low-1.
Region for 1s: From index low to mid-1.
Region for 2s: From index high+1 to the end of the array.
Initially, all elements are unclassified. As we traverse the array:

Move 0s to the beginning (expand the "0s region").
Keep 1s in the middle (expand the "1s region").
Move 2s to the end (expand the "2s region").
This ensures a single-pass, in-place sort.

Approach
We use three pointers:

low: Tracks the boundary of the "0s region".
mid: Scans through the array to classify elements.
high: Tracks the boundary of the "2s region".
We iterate through the array using the following rules:

If arr[mid] == 0:
Swap arr[mid] with arr[low].
Increment both low and mid.
This moves the 0 to its correct region.
If arr[mid] == 1:
Increment mid.
1s naturally stay in the middle region without swapping.
If arr[mid] == 2:
Swap arr[mid] with arr[high].
Decrement high.
This moves the 2 to its correct region.
We stop when mid surpasses high, ensuring all elements are classified.

Why This Works
Each iteration ensures at least one pointer moves closer to termination.
Swaps only involve elements in wrong regions, minimizing operations.
The use of three pointers ensures the array is sorted in-place with O(n) time complexity and O(1) space complexity.


void sort012(vector<int>& arr) {
        // code here
        int low=0;
       int mid=0;
       int high=arr.size()-1;
       while(mid<=high){
           if(arr[mid]==0){
               swap(arr[low],arr[mid]);
               low++;
               mid++;
           }
           else if(arr[mid]==1){
              mid++;
           }
           else{
               swap(arr[mid],arr[high]);
               high--;
           }
       }
    }
