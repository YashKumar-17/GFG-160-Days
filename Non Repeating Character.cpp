Intuition Behind the Code:
The goal of this function is to find the first non-repeating character in the input string s. The algorithm achieves this using a sliding window approach coupled with a frequency counting mechanism.

Key Observations:
Frequency Tracking:

To determine whether a character is repeating, we need to know how many times it has appeared so far in the string. This is achieved using a vector<int> array flag of size 26 (one for each lowercase letter of the English alphabet). The flag array keeps the count of occurrences for each character.
Sliding Window:

A start pointer is maintained to track the first candidate for the non-repeating character. If the character at start is found to be repeating (flag[pointer] > 1), the start pointer is incremented until it points to a non-repeating character or reaches the end of the string.
Character Validity Check:

If the start pointer reaches the end of the string, it means there is no non-repeating character, so the function returns '$'.
Otherwise, the character at the start pointer is returned, which is guaranteed to be the first non-repeating character.
Approach:
Initialize Data Structures:

Use the flag array to track character frequencies. Start with all counts set to 0.
Iterate Through the String:

For each character s[i], increment its count in the flag array.
Update the Sliding Window:

Check if the character pointed to by start is repeating. If it is (flag[pointer] > 1), increment start until you find a character with flag[pointer] == 1 or reach the end of the string.
Return the Result:

If the start pointer reaches the length of the string, return '$' indicating no non-repeating character exists.
Otherwise, return the character at position start.

Complexity:
Time Complexity: O(n)
Each character in the string is processed at most twice: once during the iteration and once while adjusting the start pointer.
Space Complexity: O(1)
The flag array is fixed at size 26, regardless of the input size.




char nonRepeatingChar(string &s) {
        // Your code here
        vector<int>flag(26,0);
        int start=0;
        int pointer=s[start]-'a';
        
        for(int i=0;i<s.length();i++){
            flag[s[i]-'a']++;
            if(flag[pointer]>1){
                while(flag[pointer]>1 && start<s.length()){
                start++;
                pointer=s[start]-'a';
                }
            }
        }
        if(start==s.length()){
            return '$';
        }
        else{
            return s[start];
        }
        
    }
