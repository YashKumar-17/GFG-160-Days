Initialize Variables: Use a sliding window with pointers l (left) and r (right), 
a frequency array flag for character counts, and variables to track cnt (current substring length), dsc (discarded characters), and lenmax (maximum unique substring length).

Expand Window: Move r to expand the window while ensuring the character at r is unique (flag[s[r]-'a'] < 1).

Handle Duplicates: If a duplicate is found:

Increment l to shrink the window until the duplicate is resolved.
Adjust cnt and reset temporary discard (dsc).
Update Maximum: Continuously update lenmax with the maximum unique substring length during traversal.

Return Result: Return lenmax after processing the entire string.

int longestUniqueSubstr(string &s) {
        // code here
        int n=s.length();
        int lenmax=INT_MIN;
        vector<int>flag(26,0);
        int l=0;
        int r=0;
        int cnt=0;
        int flg=0;
        int dsc=0;
        while(r<n){
             if(flag[s[r]-'a']<1 && flg==0){
                flag[s[r]-'a']++;
                cnt++;
                r++;
            }
            else{
                flg=1;
                flag[s[l]-'a']--;
                dsc++;
                l++;
                if(flag[s[r]-'a']<2){
                    flg=0;
                    cnt-=dsc;
                    dsc=0;
                }
            }
            lenmax=max(lenmax,cnt);
        }
        return lenmax;
    }
