### Approach to Find Equilibrium Index:

1. **Calculate Total Sum**:
   - Compute the sum of all elements in the array (`total_sum`).

2. **Iterate through the Array**:
   - Use a loop starting from the second element (index `1`) to the second-to-last element (index `n-2`).

3. **Check for Equilibrium**:
   - For each element at index `i`, calculate the required sum on the right (`req = total_sum - arr[i]`).
   - Check if the left sum (`pre_sum`) equals half of `req` and `req` is even:
     - If yes, return the index `i` as the equilibrium index.

4. **Update Left Sum**:
   - Add the current element to the left sum (`pre_sum`).

5. **Return -1 if No Equilibrium Found**:
   - If no index satisfies the condition, return `-1`.

 int findEquilibrium(vector<int> &arr) {
        // code here
        long long total_sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            total_sum+=arr[i];
        }
        long long pre_sum=arr[0];
        for(int i=1;i<n-1;i++){
            long long req=total_sum-arr[i];
            if(pre_sum==(req/2) && req%2==0){
                return i;
            }
            pre_sum+=arr[i];
        }
        return -1;
        
    }
