### **Intuition & Approach**  

This code solves the **staircase problem** using **recursion with memoization (top-down DP)**. The goal is to count the number of ways to reach step `n`, taking either **1 step or 2 steps at a time**.

---

### **Approach (Step-by-Step)**  

1. **Recursive Function (`stairways`)**:  
   - Base cases:  
     - If `i == n`, we have reached the top → return `1`.  
     - If `i > n`, we exceeded the target → return `0`.  
   - **Memoization Check**: If `dp[i]` is precomputed, return it.  
   - **Recursive Formula**:  
     \[
     dp[i] = \text{stairways}(n, i+1, dp) + \text{stairways}(n, i+2, dp)
     \]
     - Take **1 step** (`i+1`) and count ways.  
     - Take **2 steps** (`i+2`) and count ways.  
     - Store and return result to avoid redundant calculations.

2. **Initialization (`countWays`)**:  
   - Create `dp` array (`size n+2`, initialized to `-1`).  
   - Call `stairways(0, dp)` to start recursion from step `0`.

---

### **Complexity Analysis**  
- **Time Complexity:** \(O(n)\) → Each state `i` is computed once.  
- **Space Complexity:** \(O(n)\) → For `dp` array and recursion stack.  

This approach ensures we avoid **exponential** time complexity of naive recursion (`O(2^n)`) by using **memoization**. 🚀

int stairways(int &n, int i, vector<int>&dp){
        if(i==n){
            return dp[i]=1;
        }
        if(i>n){
            return dp[i]=0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=stairways(n,i+1,dp)+stairways(n,i+2,dp);
    }
    int countWays(int n) {
        // your code here
        vector<int>dp(n+2,-1);
        return stairways(n,0,dp);
    }
