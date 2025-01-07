Approach to Count Pairs with Given Sum in Sorted Array:
Initialization:

Determine the size of the array n.
Initialize two pointers: i (starting at 0) and j (starting at n-1).
Set a variable ans to 0 to store the count of pairs.
Two-Pointer Technique:

Use a while loop to iterate as long as i < j.
For each pair (arr[i], arr[j]):
Calculate the sum arr[i] + arr[j].
Handle Sum Conditions:

If the sum is greater than target, move the right pointer (j) to the left (decrease j) to reduce the sum.
If the sum is less than target, move the left pointer (i) to the right (increase i) to increase the sum.
Handle Matching Pairs:

If the sum equals the target:
Check if arr[i] equals arr[j]:
Calculate the number of elements between i and j (inclusive).
Use the combination formula C(x,2)= x*(x−1)/2 to count all pairs and break out of the loop.
Otherwise:
Count the frequency of the current value at i (cntL) by moving i to the right until the value changes.
Similarly, count the frequency of the current value at j (cntR) by moving j to the left until the value changes.
Add cntL * cntR to ans to account for all pairs formed between the current values.
Update Pointers:

Increment i and decrement j to move towards the center of the array.
Return Result:

After exiting the loop, return ans, which contains the total number of pairs that sum up to the target.

int countPairs(vector<int> &arr, int target) {
        // Complete the function
         int n=arr.size();
          int i=0;
          int j=n-1;
          
       
          int ans=0;
          while(i<j)
          {
          int cntL=1;
          int cntR=1;
              if(arr[i]+arr[j]>target){
                 j--;continue;
              }
              else if(arr[i]+arr[j]<target){
                 i++;continue;
              }
              if(arr[i]==arr[j] && arr[i]+arr[j]==target){
                  
                  int x=j-i+1;
                   ans+=(x*(x-1))/2;
                   break;
              }
              while(arr[i]==arr[i+1])
                 {
                        cntL++;
                        i++;
                 }
             while(arr[j]==arr[j-1])
              {
                        cntR++;
                        j--;
              }
              ans+=(cntL*cntR);
              
              i++;j--;
                 
          }
          return ans;
    }
