### Approach and Intuition

1. **Initialization**:
   - Use a variable `total_prod` to store the product of all non-zero elements.
   - Use a flag `flag` to count the number of zeros in the array.

2. **Calculate Total Product**:
   - Iterate through the array:
     - If the element is zero, increment `flag`.
     - Otherwise, multiply it with `total_prod`.

3. **Determine Results**:
   - If `flag > 1`, the result for all indices will be `0` because more than one zero makes the total product zero.
   - If `flag == 1`, only the index with the zero will have a non-zero product (`total_prod`), and all other indices will be `0`.
   - If there are no zeros (`flag == 0`), calculate the result for each index as `total_prod / arr[i]`.

4. **Return Results**:
   - Append the appropriate values to the result vector `ans` based on the above logic and return it. 

This approach efficiently handles cases with and without zeros in ( O(n) ) time complexity.

vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        long long total_prod=1;
        int n=arr.size();
        vector<int>ans;
        int flag=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                flag++;
            }
            else{
            total_prod*=arr[i];
            }
        }
        for(int i=0;i<n;i++){
            if(flag>1){
                ans.push_back(0);
            }
            else if(flag==1){
                if(arr[i]==0){
                    ans.push_back(total_prod);
                }
                else{
                    ans.push_back(0);
                }
            }
            else{
                ans.push_back(total_prod/arr[i]);
            }
        }
        return ans;
    }
