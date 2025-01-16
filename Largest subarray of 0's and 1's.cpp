### Approach and Intuition:

1. **Convert Problem into a Prefix Sum Problem**:
   - Treat the array as consisting of `-1` for `0` and `+1` for `1`. This allows the problem to be framed in terms of prefix sums. A subarray with an equal number of `0`s and `1`s will have a net sum of `0`.

2. **Use a Hash Map to Track Prefix Sums**:
   - Maintain a hash map (`ump`) where the key is the prefix sum and the value is the first index where this sum was encountered. This helps in determining the length of subarrays with the same sum efficiently.

3. **Iterate Through the Array**:
   - Traverse the array while calculating the cumulative `sum` at each step:
     - Increment the sum by `1` for `1`s and decrement it by `1` for `0`s.
   - Check if the `sum` has been seen before:
     - If yes, the subarray between the first occurrence of this sum (from `ump`) and the current index has a net sum of `0`. Update the maximum length (`ans`) accordingly.
     - If no, store the current index for this sum in the map.

4. **Return the Maximum Length**:
   - After processing the array, `ans` contains the length of the longest subarray with equal numbers of `0`s and `1`s.

### Complexity:
- **Time**: (O(n)), where (n) is the size of the array (due to single traversal).
- **Space**: (O(n)), for storing prefix sums in the hash map.

int maxLen(vector<int> &arr) {
        // Your code here
        unordered_map<int,int>ump;
        int n=arr.size();
        int sum=0;
        ump[sum]=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                sum-=1;
            }
            else{
                sum+=1;
            }
            if(ump.find(sum)!=ump.end()){
                ans=max(ans,i-ump[sum]);
            }
            else{
                ump[sum]=i;
            }
            
        }
        return ans;
    }
