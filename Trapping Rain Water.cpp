Two Pointer Approach:
Use two pointers l (left) and r (right) to traverse the array from both ends.

Track Maximum Heights:
Maintain lmax (maximum height seen so far from the left) and rmax (maximum height seen so far from the right).

Water Trapping Logic:

At any position, the water trapped is determined by the smaller of lmax or rmax minus the height at that position.
If arr[l] <= arr[r], process the left pointer (l) because the water level depends on lmax.
Otherwise, process the right pointer (r) because the water level depends on rmax.
Accumulate Water:

Add water trapped at the current position (l or r) to the total if the current height is less than lmax or rmax.
Update lmax or rmax as necessary.
Stop When Pointers Meet:
Continue until l and r meet, ensuring all positions are processed.

This approach works efficiently in O(n) time because each element is processed only once, and the two-pointer strategy avoids unnecessary comparisons.


Water Trapping Logic - Detailed:
Key Idea: The amount of water trapped above a particular bar is determined by the minimum of the tallest bars to its left (lmax) and to its right (rmax), minus the height of the current bar itself.

Why Compare arr[l] and arr[r]?

If arr[l] <= arr[r], it means the limiting height for the water trapped at l (and positions closer to l) can only be lmax. This is because any bar on the right (arr[r]) is taller than or equal to the current arr[l], so it won't constrain the water level for l.
Similarly, if arr[l] > arr[r], the limiting height for water trapped at r (and positions closer to r) can only be rmax.
How the Trapping Works:

For the left pointer (l):
If arr[l] < lmax, water can be trapped above the bar at l. The amount of water is lmax - arr[l].
If arr[l] >= lmax, no water is trapped, and lmax is updated to arr[l] (a taller bar is encountered).
Move the l pointer to the right (l++) to process the next bar.
For the right pointer (r):
If arr[r] < rmax, water can be trapped above the bar at r. The amount of water is rmax - arr[r].
If arr[r] >= rmax, no water is trapped, and rmax is updated to arr[r].
Move the r pointer to the left (r--) to process the next bar.

int maxWater(vector<int> &arr) {
        // code here
       int l,r,lmax,rmax,n,total;
       n=arr.size();
       l=0;
       r=n-1;
       lmax=0;
       rmax=0;
       total=0;
       while(l<r){
           if(arr[l]<=arr[r]){
               if(lmax>arr[l]){
                   total+=lmax-arr[l];
               }
               else{
                   lmax=arr[l];
               }
               l++;
           }
           else{
               if(rmax>arr[r]){
                   total+=rmax-arr[r];
               }
               else{
                   rmax=arr[r];
               }
               r--;
           }
       }
       return total;
       
        
        
    }
