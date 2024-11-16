class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int ans=-1;
        int largest=-1;
        int second_largest=-1;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>largest){
                second_largest=largest;
                largest=arr[i];
            }
            if(arr[i]>second_largest && arr[i]<largest){
                second_largest=arr[i];
            }
        }
        if(second_largest>-1){
            ans=second_largest;
            return ans;
        }
        return ans;
    }
};
