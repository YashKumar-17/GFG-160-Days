### **Intuition & Approach:**
The given code finds the **longest palindromic substring** in a given string `s` using the **expand-around-center** technique.  

### **Approach:**
1. **Iterate through each character** in the string as a potential center of a palindrome.
2. **Expand around the center** to check for palindromes:
   - **Odd-length palindromes**: Expand with the current character as the center.
   - **Even-length palindromes**: Expand with the gap between current and next character as the center.
3. **Keep track of the longest palindrome** by updating `start` and `end` whenever a longer palindrome is found.
4. **Extract and return the longest palindromic substring** using `substr(start, end)`.  

### **Mistake in Code:**
The final return should be `S.substr(start, end - start + 1)` instead of `S.substr(start, end)`, as `substr(start, length)` takes length as the second argument.

string longestPalindrome(string &s) {
        // code here
    int start = 0, end = 0;
    int low,high;
    string S=s;
    for(int i = 0; i < S.length(); i++){
        // odd part
         low = i - 1;
         high = i;
        while(low>=0 && high<S.length() && S[low] == S[high]){
            
            if(high - low + 1 > end){
                end = high - low + 1;
                start = low;
            }
            low--;
            high++;
        }
        // Even part
         low = i - 1;
         high = i + 1;
        while(low>=0 && high<S.length() && S[low] == S[high]){
            
            if(high - low + 1 > end){
                end = high - low + 1;
                start = low;
            }
            low--;
            high++;
        }
        
    }
    if(end == 0)return S.substr(start,1); 
    return S.substr(start,end);
}
