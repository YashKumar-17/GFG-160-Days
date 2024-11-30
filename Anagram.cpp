Approach for areAnagrams
The function areAnagrams determines whether two strings (s1 and s2) are anagrams of each other. Two strings are considered anagrams if they contain the same characters with the exact same frequencies.

Steps of the Approach
1. Frequency Count
Intuition: To check if two strings are anagrams, their characters must have identical frequencies. A frequency array can help count occurrences of each character.
Implementation:
Create two frequency arrays f1 and f2 of size 26 (to represent the 26 lowercase English letters) and initialize all elements to 0.
Traverse the first string s1:
For each character s1[i], increment the corresponding index in f1 using the formula s1[i] - 'a'.
Similarly, traverse the second string s2:
Increment the corresponding index in f2.
2. Compare Frequency Arrays
Intuition: If the strings are anagrams, their frequency arrays (f1 and f2) will be identical. If even one frequency differs, the strings are not anagrams.
Implementation:
Iterate through the frequency arrays f1 and f2.
Compare the values at each index:
If any value in f1 does not match the corresponding value in f2, return false.
If all values match, return true.
3. Early Termination (Optional Optimization)
Before proceeding with the frequency comparison:
Check if the lengths of s1 and s2 are equal. If they are not, return false immediately, as strings of unequal lengths cannot be anagrams.
Key Observations
Frequency Mapping:
The algorithm uses the fact that lowercase English letters can be indexed efficiently using char - 'a'.
Efficiency:
The frequency arrays provide a direct, O(1) access mechanism to count and compare character occurrences.
Edge Cases Handled:
Different string lengths: Automatically detected if lengths differ.
Empty strings: Both empty strings are anagrams by definition.
Time Complexity
Frequency Count: O(n+m), where n=s1.length() and m=s2.length().
Frequency Comparison: O(26), which is constant.
Total: O(n+m).
Space Complexity
Frequency Arrays: O(26+26)=O(1) (since size is fixed and does not grow with input size).
Total: O(1).



bool areAnagrams(string& s1, string& s2) {
        // Your code here
        vector<int>f1(26,0);
        vector<int>f2(26,0);
        for(int i=0;i<s1.length();i++){
            f1[s1[i]-'a']++;
        }
         for(int i=0;i<s2.length();i++){
            f2[s2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(f1[i]!=f2[i]){
                return false;
            }
        }
        return true;
        
    }
