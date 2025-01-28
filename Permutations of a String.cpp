### Intuition and Approach:

1. **Goal:** The code generates all unique permutations of the string `s`.

2. **Recursive Function (`recur`):**
   - At each recursion level, it fixes a character at the current `index` and recursively permutes the remaining substring.
   - Once the `index` reaches the end of the string, the current permutation is added to the set `ans`.

3. **Swap for Permutations:**
   - The `swap(s[index], s[i])` swaps the current character with another character in the substring to explore all possible arrangements.
   - After recursion, the characters are swapped back to restore the original order (backtracking).

4. **Unique Permutations:**
   - A `set` is used to automatically handle duplicate permutations by storing only unique results.

5. **Result Construction:**
   - Finally, the `set` is converted to a `vector` to return the permutations in sorted order.

void recur(int index, string &s, set<string> &ans){
        if(index==s.length()){
            ans.insert(s);
            return;
        }
        for(int i=index; i<s.length();i++){
            swap(s[index],s[i]);
            recur(index+1,s,ans);
            swap(s[index],s[i]);
        }
        
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        set<string>ans;
        recur(0,s,ans);
        vector<string>res;
        res.insert(res.end(),ans.begin(),ans.end());
        return res;
        
    }
