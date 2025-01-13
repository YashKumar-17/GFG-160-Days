1. Initialize Variables:
   - `maxi`: Stores the maximum water trapped so far, initialized to 0.
   - `l` and `r`: Pointers to the leftmost (`l`) and rightmost (`r`) buildings in the array.

2. Two-Pointer Approach:
   - While `l` is less than `r`:
     - Calculate the water trapped between the buildings at indices `l` and `r` using the formula:  
       `min(arr[l], arr[r]) * (r - l)`, which considers the smaller building height and the distance between the two pointers.
     - Update `maxi` to the maximum of the current `maxi` and the calculated trapped water.

3. Move Pointers:
   - Increment the left pointer (`l`) if the height of the building at `l` is smaller or equal to the height at `r`.
   - Otherwise, decrement the right pointer (`r`).

4. Return the Result:
   - After the loop ends, `maxi` holds the maximum water trapped.

3rd Point Explanation: 

Key Idea:
The amount of water trapped between two buildings is determined by:

The shorter building's height, because water cannot exceed the shorter building's height.
The distance between the two buildings.

Why Increment l When arr[l] <= arr[r]?
If arr[l] is smaller or equal to arr[r], the current trapped water is limited by arr[l].
Moving the left pointer (l) to the right might give a taller building at l+1, which could potentially trap more water with the building at r.
Keeping l where it is won't help, because the current arr[l] is already the limiting factor, so we "give up" on this l and try the next potential candidate. Same goes with r pointer.



This is an efficient O(n) solution leveraging the two-pointer technique.

int maxWater(vector<int> &arr) {
        // code here
        int maxi=0;
        int n=arr.size();
        int l=0;
        int r=n-1;
        while(l<r){
            maxi=max(maxi,min(arr[l],arr[r])*(r-l));
            if(arr[l]<=arr[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxi;
    }
