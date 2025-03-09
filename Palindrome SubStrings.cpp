### **Intuition and Approach**  

The given code counts the number of **palindromic subsequences** in a string using an **expand-around-center approach**.  

#### **Steps**  

1. **Helper Function (`length`)**  
   - Expands around the center (left `l` and right `r`) to check for palindromic sequences.  
   - If characters match, it increases the count and expands further.  

2. **Odd-Length Palindromes**  
   - Iterates through each character, treating it as the center of a palindrome.  
   - Calls `length(i-1, i+1, s)` to count palindromes expanding around `i`.  

3. **Even-Length Palindromes**  
   - Iterates through each character pair as the center of an even-length palindrome.  
   - Calls `length(i-1, i, s)`.  

4. **Final Count**  
   - Adds both counts and returns the total number of palindromic subsequences.  

### **Time Complexity:**  
- **O(n²)** due to the expansion approach.

int length(int l, int r, string &s){
        int count=0;
        while(l>=0 && r<s.length()){
            if(s[l]==s[r]){
                count++;
                l--;
                r++;
            }
            else{
                break;
            }
            
        }
        return count;
    }
    int countPS(string &s) {
        // code here
        int n=s.length();
        int count1=0;
        int count2=0;
        //for odd
        for(int i=0;i<n;i++){
            count1+= length(i-1, i+1,s);
            
        }
        //for even
        for(int i=1;i<n;i++){
            count2+= length(i-1, i,s);
        }
        return count1+count2; 
    }
