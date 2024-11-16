class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int l=0;
        int r=1;
        int n=arr.size();
        while(r<n){
            if(arr[l]==0 && arr[r]!=0){
                swap(arr[l],arr[r]);
                l++;
                r++;
            }
            else if(arr[l]==0 && arr[r]==0){
                r++;
            }
            else if(arr[l]!=0){
                l++;
                r++;
            }
        }
        
        
    }
};
