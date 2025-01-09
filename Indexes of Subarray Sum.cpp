Approach for subarraySum Function:
Initialize Variables:

Use two pointers l (left) and r (right) to traverse the array.
Maintain a sum variable to store the cumulative sum of the current subarray.
Set start and end to -1 to track the subarray indices.
Sliding Window Technique:

Start with l = 0, r = 0, and initialize sum = arr[0].
Check Conditions in a Loop:

If sum == target:
Update start and end to l+1 and r+1 (1-based indexing).
Break the loop as the target subarray is found.
If sum < target:
Expand the window by incrementing r and adding arr[r] to sum.
If sum > target:
Shrink the window by incrementing l and subtracting arr[l] from sum.
Special case: If l == r, increment r and include arr[r] in sum.
Handle Result:

If a valid subarray is found (start != -1 and end != -1), return the indices as a vector.
Otherwise, return [−1] indicating no subarray was found.
This approach uses the two-pointer/sliding window technique to efficiently find a continuous subarray with a sum equal to the target. The time complexity is O(n).

vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int start=-1;
        int n=arr.size();
        int end=-1;
        int l=0;
        int r=0;
        int sum=0;
        sum+=arr[r];
        while(r<n){
            if(sum==target){
                start=l+1;
                end=r+1;
                break;
            }
            
            else if(sum<target){
            r++;
            sum+=arr[r];
            }
            
            else{
                if(l==r){
                    r++;
                    sum+=arr[r];
                }
                else{
                   sum-=arr[l];
                l++; 
                }
                
            }
            
        }
        vector<int>ans;
        if(start!=-1 && end!=-1){
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }
        return {-1};
    }
