### **Intuition and Approach**  

The given code calculates the **Edit Distance** (Levenshtein Distance) between two strings **s1** and **s2**, which represents the minimum number of operations required to convert one string into another. The allowed operations are **insertion, deletion, and substitution** of characters.  

#### **Approach**  
1. **Recursive Function with Memoization (`minop`)**  
   - Base Cases:  
     - If `i < 0`, all remaining characters of `s2` need to be inserted → **return `j+1`**.  
     - If `j < 0`, all remaining characters of `s1` need to be deleted → **return `i+1`**.  
   - If already computed (`dp[i][j] != -1`), return stored value.  
   - If `s1[i] == s2[j]`, no operation is needed → recurse on `(i-1, j-1)`.  
   - Else, consider three operations:  
     - **Delete (`i-1, j`)**  
     - **Insert (`i, j-1`)**  
     - **Replace (`i-1, j-1`)**  
   - Take the minimum of these three and add 1.  

2. **Edit Distance Function (`editDistance`)**  
   - Initializes a **DP table** of size `n x m` with `-1`.  
   - Calls `minop(n-1, m-1, s1, s2, dp)` to compute the result.  

This ensures an **optimal, memoized solution** with **O(n × m) time complexity**, significantly improving over the naive recursive approach.

int minop(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j]=minop(i-1,j-1,s1,s2,dp);
        }
        return dp[i][j]=1+min(minop(i-1,j,s1,s2,dp), min(minop(i,j-1,s1,s2,dp),minop(i-1,j-1,s1,s2,dp)));
    }
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n = s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return minop(n-1,m-1,s1,s2,dp);
    }
