 Key Idea
We need to determine the largest minimum distance that can be maintained between any two cows while placing them in the stalls. To do this:

Sorting the Stalls:

Since the stalls' positions can be unordered, sorting them makes it easy to calculate distances between consecutive stalls.
Binary Search on Minimum Distance:

The minimum distance (mid) between cows lies in the range [0, max_distance], where:
max_distance = stalls[n-1] - stalls[0] (the distance between the first and last stall after sorting).
Use binary search to determine the largest possible value of mid such that k cows can still be placed in the stalls with at least mid distance between them.
Check Feasibility Function (check):

The function check() verifies whether it is possible to place all k cows in the stalls such that the minimum distance between any two cows is at least mid.
Start by placing the first cow in the first stall (last = stalls[0]).
Traverse through the stalls and place a cow in a stall only if the distance from the last placed cow is >= mid.
Keep counting the cows placed (count). If count == k, return true (placement is successful). Otherwise, return false.
Binary Search Logic:

Initialize the search space:
low = 0 (minimum possible distance).
high = stalls[n-1] - stalls[0] (maximum possible distance).
Calculate mid = (low + high) / 2 (potential minimum distance to test).
Use the check() function to verify:
If check(mid) is true (i.e., it’s possible to place the cows with at least mid distance), move the search to the right half: low = mid + 1.
If check(mid) is false, reduce the search space to the left half: high = mid - 1.
The largest valid mid is stored in high at the end of the loop.

Time Complexity
Sorting the stalls: O(nlogn)
Binary search on the distance: O(log(max_distance)), where max_distance=stalls[n−1]−stalls[0].
For each mid, the check() function takes O(n) time to verify.
Total Time Complexity: O(nlogn+nlog(max_distance))


bool check(vector<int> &stalls, int mid, int k){
        int count=1;
        int last=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-last>=mid){
                count++;
                last=stalls[i];
            }
            if(count==k){
                return true;
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int low=0;
        int high=stalls[n-1]-stalls[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(stalls,mid,k)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            
        }
        return high;
    }
