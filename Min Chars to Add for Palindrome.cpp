Approach: Minimum Characters to Make a String Palindrome
Reverse the String:

Create a reversed version of the input string s, called comp.
Combine Strings:

Concatenate comp (the reversed string) and s (the original string) into a new string concatenated = comp + s.
Build LPS Array:

Construct the LPS (Longest Prefix Suffix) array for concatenated. This array helps us find the longest prefix of comp that matches a suffix of s.
Find Matching Length:

The last value in the LPS array (lps[concatenated.length() - 1]) tells us how much of the end of s matches the start of comp.
Calculate Result:

Subtract the matching length from the length of s to determine the minimum characters required to make the string a palindrome.


int minChar(string& s) {
    string comp = s;
    reverse(comp.begin(), comp.end());
    string combined = s + "$" + comp;
    int n = combined.length();
    
    // Construct LPS array for the combined string
    vector<int> lps(n, 0);
    int len = 0; // Length of previous longest prefix suffix
    int i = 1;
    while (i < n) {
        if (combined[i] == combined[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    // The length of the longest suffix of `s` that is also a prefix of `comp`
    int match = lps[n - 1];
    return s.length() - match;
}
