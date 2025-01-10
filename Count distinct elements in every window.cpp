Initialize Variables:

ump (unordered_map) to track frequency of elements in the current window.
ans to store the result.
dis_count to count distinct elements, l and r as pointers, n as array size.
Sliding Window:

Expand the window by incrementing r and add elements to ump.
If the frequency of the added element becomes 1, increment dis_count.
Window Size Check:

When the window size equals k, append dis_count to ans.
Shrink Window:

Decrement the frequency of the element at l in ump.
If frequency becomes 0, decrement dis_count.
Increment l.
Repeat Until r < n:

Continue expanding and shrinking the window until r reaches the end.
Return Result:

Return the ans vector containing distinct element counts for each window.

vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        unordered_map<int,int>ump;
        vector<int>ans;
        int dis_count=0;
        int szc=0;
        int l=0;
        int r=0;
        int n=arr.size();
        while(r<n){
            if(r-l<k){
            ump[arr[r]]++;
            if(ump[arr[r]]==1){
                dis_count++;
            }
            r++;
            
            }
            if(r-l==k){
                ans.push_back(dis_count);
                ump[arr[l]]--;
                if(ump[arr[l]]==0){
                    dis_count--;
                }
                l++;
            }
        }
        return ans;
    }
