 void lpsm(vector<int>& lps, string pat) {
    int pre = 0;
    int suf = 1;
    while (suf < pat.length()) {
        if (pat[pre] == pat[suf]) {
            lps[suf] = pre + 1;
            suf++;
            pre++;
        } else {
            if (pre == 0) {
                lps[suf] = 0;
                suf++;
            } else {
                pre = lps[pre - 1];
            }
        }
    }
}

vector<int> search(string& pat, string& txt) {
    vector<int> ans;
    vector<int> lps(pat.length(), 0); // LPS array should be of size `pat.length()`
    lpsm(lps, pat); // Build LPS array for the pattern

    int first = 0; // Index for txt
    int second = 0; // Index for pat

    while (first < txt.length()) {
        if (txt[first] == pat[second]) {
            first++;
            second++;
        }

        if (second == pat.length()) { // Found a match
            ans.push_back(first - second);
            second = lps[second - 1]; // Reset `second` using the LPS array
        } else if (first < txt.length() && txt[first] != pat[second]) {
            if (second == 0) {
                first++;
            } else {
                second = lps[second - 1];
            }
        }
    }

    return ans;
}
