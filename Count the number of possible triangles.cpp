Sort the Array:
Sort the input array arr in ascending order. Sorting helps efficiently find valid triangles.

Initialize Counter:
Initialize a variable count to 0. This will store the number of valid triangles.

Iterate Over the Array (Backwards):
Start iterating from the last element of the array (index i from arr.size() - 1 to 2).

Two-Pointer Technique:
For each i, initialize two pointers:

l (left pointer) starting at the beginning (0).
r (right pointer) starting at i-1.
Check Triangle Condition:

While l < r, check if arr[l] + arr[r] > arr[i].
If true: All combinations between l and r form a valid triangle. Add (r - l) to count and decrement r.
If false: Increment l.
Repeat for All i:
Repeat steps 4 and 5 for each i until all valid triangles are counted.

Return Result:
Return the value of count as the total number of valid triangles.

int countTriangles(vector<int>& arr) {
        // code here
        int count=0;
        sort(arr.begin(),arr.end());
        for(int i=arr.size()-1;i>=2;i--){
            int l=0;
            int r=i-1;
            while(l<r){
                if(arr[l]+arr[r]>arr[i]){
                    count+=r-l;
                    r--;
                }
                else{
                    l++;
                }
                
            }
        }
        return count;
    }
