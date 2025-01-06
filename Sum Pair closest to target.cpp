Initialize and Sort the Array:

Sort the input array arr to enable a two-pointer approach.
Edge Case Handling:

If the array size is 1, return an empty result (ans) as there aren't two elements to form a pair.
Set Up Variables:

Use two pointers l (left) and r (right), initialized to the start and end of the array.
Track the closest pair (a and b) and the minimum difference (min_diff) initialized to a large value (INT_MAX).
Iterate with Two Pointers:

While l < r:
Calculate the current sum arr[l] + arr[r] and its difference from the target.
If the current difference is smaller than min_diff, update a, b, and min_diff.
Adjust Pointers: If the sum of the pair is greater than or equal to the target, move the right pointer (r) left.
If the sum is less than the target, move the left pointer (l) right.
Store the Result:Once the closest pair is found, push a and b into the result vector ans.
Return the Result:Return the vector ans containing the closest pair.

vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        vector<int>ans;
        sort(arr.begin(),arr.end());
        if(arr.size()==1){
            return ans;
        }
        int l=0;
        int r=arr.size()-1;
        int a;
        int b;
        int min_diff=INT_MAX;
        while(l<r){
            if(abs(arr[l]+arr[r]-target)<min_diff){
                a=arr[l];
                b=arr[r];
                min_diff=abs(arr[l]+arr[r]-target);
            }
            if(arr[l]+arr[r]>=target){
                r--;
            }
            else{
                l++;
            }
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
