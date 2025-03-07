### **Intuition and Approach:**  
1. **Understanding the Problem:**  
   - We need to find the longest palindromic subsequence (LPS) in a given string.  
   - A subsequence is a sequence that appears in the same order but not necessarily contiguous.  

2. **Key Idea:**  
   - The longest palindromic subsequence in a string is the **longest common subsequence (LCS)** between the string and its **reversed version**.  

3. **Steps in the Code:**  
   - **Create two strings:**  
     - `s1 = s` (original string)  
     - `s2 = reverse(s)` (reversed string)  
   - **Apply LCS approach using Dynamic Programming:**  
     - Create a 2D `dp` table of size `(n+1) x (m+1)` initialized with `-1`.  
     - Fill base cases (`dp[i][0] = 0`, `dp[0][j] = 0`) since an empty string has LCS of 0.  
     - Iterate through `s1` and `s2`, filling `dp[i][j]`:  
       - If characters match: `dp[i][j] = 1 + dp[i-1][j-1]`  
       - Else: `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`  
   - **Final answer:** `dp[n][m]` gives the longest palindromic subsequence length.  

### **Why This Works?**  
Since LPS is a subsequence that remains the same when reversed, finding the **LCS between the original and its reverse** gives the LPS length.

int longestPalinSubseq(string &s) {
        // code here
        string s1=s;
        string s2=s;
        reverse(s2.begin(),s2.end());
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
