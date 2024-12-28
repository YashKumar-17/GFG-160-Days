Step-by-Step Explanation of the Approach:
Initialization:

The function first determines the size of the array arr by storing it in n.
A 2D vector ans is used to store the final result of the triplets found.
Outer Loop (i Loop):

The outer loop iterates over each element of the array, except the last one (i goes from 0 to n-2).
The variable semi_tar is initialized as the negative value of the current element, i.e., semi_tar = 0 - arr[i]. This is done because, to find a triplet summing to zero, we need to find two other elements that sum to -arr[i].
Inner Loop (j Loop):

For each i, a second loop iterates over all elements that come after arr[i] (i.e., j goes from i + 1 to n-1).
For each pair of elements arr[i] and arr[j], we calculate the required value x = semi_tar - arr[j]. This value represents the third number in the triplet that, when added to arr[i] and arr[j], will sum to zero.
Hash Map (mp) for Storing Elements:

The algorithm uses a hash map (unordered_map<int, vector<int>> mp) to store previously encountered values of arr[j] as keys and their indices as the corresponding values.
This is done to quickly check if there exists an element that, when added to the current element arr[j], would complete a triplet summing to zero.
Finding Complements in the Hash Map:

The key part of the algorithm is the check if (mp.find(x) != mp.end()). If x exists in the map, it means we have already encountered an element arr[k] such that arr[k] + arr[j] = -arr[i] (or equivalently, arr[i] + arr[j] + arr[k] = 0).
If x exists in the map, we loop over all the indices of x stored in the map (mp[x]), and for each index, we create a potential triplet by combining i, j, and the stored index.
Storing the Result:

Each found triplet is stored in the vector res. To avoid duplicate triplets (because the triplet can appear in different orders), the triplet is sorted before being added to the result vector ans.
Update the Hash Map:

After processing the current element arr[j], it is added to the map mp[arr[j]] with its index j. This ensures that future iterations of the inner loop can check if a complement that completes the triplet has already been encountered.
Return the Result:

Finally, the function returns the vector ans which contains all unique triplets found that sum to zero.
Time Complexity:
The time complexity of this approach is O(n^2). This is because the outer loop runs n-1 times and for each iteration, the inner loop iterates over the remaining elements. The map operations (insertion and search) are O(1) on average.
Space Complexity:
The space complexity is O(n) due to the use of the hash map, which stores indices for each element in the array.


vector<vector<int>> findTriplets(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>>ans;
        for(int i=0;i<n-1;i++)
      {
          unordered_map<int,vector<int>>mp;
          int semi_tar=(0-arr[i]);
          for(int j=i+1;j<n;j++)
          {
                  int x=semi_tar-arr[j];
                  if(mp.find(x)!=mp.end())
                  {
                      for(auto a:mp[x])
                      {
                          vector<int>res;
                          res.push_back(i);
                          res.push_back(j);
                          res.push_back(a);
                          sort(res.begin(),res.end());
                          ans.push_back(res);
                      }
                  }
                  mp[arr[j]].push_back(j);
          }
      }
       return ans;
        
    }
