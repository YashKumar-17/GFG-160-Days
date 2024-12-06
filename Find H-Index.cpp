Approach for Calculating H-Index
Understanding the Problem:

The H-Index is defined as the maximum value of h such that the researcher has at least h papers with h or more citations.
The goal is to find this value from the given citations array.
Sorting the Array:

Start by sorting the citations array in ascending order. Sorting helps in systematically evaluating the potential H-Index values.
Iterating Through the Sorted Array:

For each element in the sorted array, check if it satisfies the condition for the H-Index:
If 
citations[i]≤n−i (where n−i is the number of papers with at least citations[i] citations), update the potential answer (ans) and track the size (sz) of papers satisfying this condition.
Final Condition Check:

After looping through the array:
If the size of papers (sz) equals the value of citations (ans), return ans.
Otherwise, return sz - 1 as the maximum h-value satisfying the conditions.
Edge Case:

If the smallest value in the sorted array is greater than or equal to n (the total number of papers), the H-Index is n, as all papers satisfy the condition. Return n directly in this case.
This ensures that the algorithm correctly identifies the H-Index for any given citations array.

int hIndex(vector<int>& citations) {
        // code here
        int n=citations.size();
      sort(citations.begin(), citations.end());
      int ans=0;
      int sz=0;
      if(citations[0]>=n){
          return n;
      }
      for(int i=0;i<n;i++){
          
          if(citations[i]<=(n-i)){
              ans=citations[i];
              sz=n-i;
          }
          else{
              break;
          }
      }
      if(sz==ans){
          return ans;
      }
      else{
          return sz-1;
      }
    }
