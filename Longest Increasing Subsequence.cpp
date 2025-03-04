### **Intuition & Approach**  

This code finds the **length of the Longest Increasing Subsequence (LIS)** in an efficient way using **binary search** and a **greedy approach**.  

#### **Approach:**
1. **Maintain a list (`ans`)** to store the smallest possible increasing subsequence.
2. Start by **inserting the first element** into `ans`.
3. Iterate through the array:
   - If `arr[i]` is **greater** than the last element in `ans`, **append** it to `ans` (extend LIS).
   - Otherwise, **find the position** (using **binary search**) where `arr[i]` should replace an element in `ans` to **keep it optimal**.
4. The **size of `ans`** at the end gives the **length of LIS**.

#### **Why does this work?**
- The `ans` vector **does not store the actual LIS**, but rather an **optimized version** that helps maintain the longest subsequence **efficiently**.
- **Binary search** helps replace elements in `O(log N)`, making the total time complexity **O(N log N)**.

int lis(vector<int>& arr) {
        // code here
         vector<int>ans;
         ans.push_back(arr[0]);
         int len=1;
         for(int i=1;i<arr.size();i++){
            if(arr[i]>ans[ans.size()-1]){
                ans.push_back(arr[i]);
                len++;
            }
            else{
                int key=arr[i];
                int low=0;
                int high=ans.size()-1;
                while(low<=high){
                    int mid=low+(high-low)/2;
                    if(ans[mid]==key){
                        high=mid-1;
                        low=mid;
                    }
                    else if(ans[mid]>key){
                        high=mid-1;
                    }
                    else{
                        low=mid+1;
                    }
                }
                ans[low]=arr[i];
                }
            }
         return len;
    }
