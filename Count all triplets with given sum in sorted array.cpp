Approach to Count Triplets with a Given Target
Initialization:

Initialize count to 0 to store the number of triplets.
Use n as the size of the input array arr.
Outer Loop (First Element):

Iterate through the array with index i from 0 to n-2.
Two-Pointer Technique:

Set two pointers:
l = i + 1 (left pointer, starts after i).
r = n - 1 (right pointer, starts at the end of the array).
While Loop to Find Valid Triplets:

Calculate the sum of the triplet arr[i] + arr[l] + arr[r].
If the sum equals target:
Increment count.
Handle duplicates by iterating through elements with the same value as arr[l] and incrementing count for each.
Move r left (r--) to check for other possible triplets.
If the sum is less than target:
Increment l to consider larger values (l++).
If the sum is greater than target:
Decrement r to consider smaller values (r--).
Return the Count:

After the loops, return the total count.

int countTriplets(vector<int> &arr, int target) {
        // Code Here
       int count=0;
       int n=arr.size();
       for(int i=0;i<n-2;i++){
           int l=i+1;
           int r=n-1;
           while(l<r){
               if(arr[i]+arr[l]+arr[r]==target){
                   count++;
                   int temp=l+1;
                   while(arr[l]==arr[temp] && temp<r){
                       count++;
                       temp++;
                   }
                   r--;
               }
               else if(arr[i]+arr[l]+arr[r]<target){
                   l++;
               }
               else{
                   r--;
               }
           }
       }
           
       
       return count;
        
    }
