### **Intuition & Approach for LCS (Longest Common Subsequence) Algorithm**  

1. **Understanding LCS:**  
   - The problem is to find the length of the longest subsequence that appears in both given strings in the same order (but not necessarily contiguous).  

2. **Dynamic Programming Approach:**  
   - We use a **2D DP table (dp[n+1][m+1])** where `dp[i][j]` stores the LCS length for `s1[0...i-1]` and `s2[0...j-1]`.  

3. **Base Case Initialization:**  
   - If either string is empty (`i == 0` or `j == 0`), LCS is **0**, so `dp[i][0] = 0` and `dp[0][j] = 0`.  

4. **Filling DP Table:**  
   - If **characters match** (`s1[i-1] == s2[j-1]`):  
     → **Include it**: `dp[i][j] = 1 + dp[i-1][j-1]`.  
   - If **characters don’t match**:  
     → Take the **max** of excluding either character: `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`.  

5. **Final Answer:**  
   - `dp[n][m]` contains the length of the LCS of `s1` and `s2`.  

This approach ensures an **O(n × m) time complexity**, which is optimal for LCS using DP.

int lcs(string &s1, string &s2) {
        // code here
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
               if(s1[i-1]==s2[j-1]){
                   dp[i][j]=1+dp[i-1][j-1];
               }
               else{
               dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
               }
           }
            
        }
        return dp[n][m];
    }

