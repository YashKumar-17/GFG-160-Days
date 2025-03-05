### **Intuition & Approach:**
This solution uses **Recursion with Memoization (Top-Down DP)** to find the **Longest String Chain**.

---

### **1️⃣ Sorting by Length**  
- First, **sort the words by length** (ascending).  
- This ensures that shorter words are processed before longer words.

---

### **2️⃣ Mapping Word Indices**  
- A **map `mp`** stores the index of each word for quick lookup.  
- This helps in checking if a **potential predecessor** exists in `O(1)` time.

---

### **3️⃣ Recursive Function `solve(i, words, mp, dp)`**
- The function **computes the longest chain starting from `words[i]`**.
- If `dp[i]` is already computed, return it (**memoization**).

---

### **4️⃣ Removing Each Character (Predecessor Check)**
- Try removing **one character at a time** from `words[i]` to generate a **possible predecessor `sn`**.
- If `sn` exists in `mp`, recursively call `solve()` on `sn` to extend the chain.

---

### **5️⃣ Updating DP and Finding Maximum**
- Store the result in `dp[i]` to avoid recomputation.
- Iterate over all words and compute the **maximum chain length**.

---

### **🔹 Time Complexity:**
- **Sorting:** `O(N log N)`
- **Recursive calls with Memoization:** `O(N * L)`, where `L` is the average word length.
- **Overall:** `O(N log N + N * L)`, which is **efficient**.

✅ **This approach ensures we efficiently find the longest string chain!** 🚀

int solve(int i,vector<string>& words, map<string,int> &mp,vector<int> &dp){
        string s = words[i];
        if(dp[i]!=-1) return dp[i];
        
        int res=1;
        for(int j=0;j<s.length();j++){
           string sn = s.substr(0, j) + s.substr(j + 1);
           if(mp.find(sn)!=mp.end()){
               int ind = mp[sn];
               res = max(res,1 + solve(ind,words,mp,dp));
           }
        }
        
        return dp[i] = res;
    }
    int longestStringChain(vector<string>& words) {
        int n=words.size();
        map<string,int> mp;
         vector<int> dp(n,-1);
        
         sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });
    
        for(int i=0;i<words.size();i++){
            mp[words[i]]=i;
        }
        
        int res=1;
        
    
         for(int i=0;i<words.size();i++){
            res=max(res,solve(i,words,mp,dp));
        }
        
        return res;
    }
