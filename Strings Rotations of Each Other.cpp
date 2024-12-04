How the Code Works
Step 1: Build the Combined String
Create a string str that includes s2 + $ + s1 + s1.
s2 + "$" is used as the pattern.
s1 + s1 is the text where we look for s2.
Example: If s1 = "abcd" and s2 = "cdab", then str = "cdab$abcdabcd".
Step 2: Use KMP to Search for s2
Treat s2 (the part before $) as the pattern and s1 + s1 as the text.
Compute the LPS (Longest Prefix Suffix) array for str, which helps determine how much of the pattern has matched so far.
Step 3: Match the Pattern
Slide through str using the KMP algorithm:
If characters match, increase the match length (i).
If the match reaches the length of s2 (i == m), return true.
If characters don’t match, use the LPS array to skip unnecessary comparisons.
Step 4: Return Result
If the pattern (s2) is found in the text (s1 + s1), return true; otherwise, return false.
5. Why the $ in the Combined String?
The $ separates s2 from s1 + s1 to ensure we don’t falsely match characters from overlapping parts of s2 and s1.


bool areRotations(string &s1, string &s2) {
        // Your code here
        string str = s2+'$'+s1+s1;
        int n = str.length(),i=0,j=1,m=s2.length();
        vector<int> lps(n,0);
        while(j<n){
            if(str[i]==str[j]){
                lps[j++]=++i;
                if(i==m)return true;
            }
            else if(i)i=lps[i-1];
            else j++;
        }
        return false;
    
    }
