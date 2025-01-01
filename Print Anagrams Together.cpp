Approach

Copy Original Strings: Create a temporary vector tmp to store all the strings from the input arr.
Sort Each String: Sort the characters in each string of tmp to standardize anagrams.
Initialize Flags: Use a flag1 vector to track whether a string has been processed in the grouping.
Group Anagrams:
For each string i in the array, compare its sorted version with subsequent strings j.
If two strings are anagrams (same sorted value), group them into a res vector.
Mark processed strings using flag1.
Handle Unmatched Strings: If a string is not grouped with others, include it as a standalone group.
Sort Final Groups: Sort the final ans to ensure consistent order of anagram groups.
Return Result: Return the grouped anagrams.




vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        vector<vector<string>>ans;
        vector<string>tmp;
        for(int i=0;i<arr.size();i++){
            tmp.push_back(arr[i]);
        }
        for(int i=0;i<arr.size();i++){
            sort(tmp[i].begin(),tmp[i].end());
        }
        vector<int>flag1(arr.size(),0);
        for(int i=0;i<arr.size();i++){
            int flag=0;
            vector<string>res;
            for(int j=i+1;j<arr.size();j++){
                
                if(tmp[i]==tmp[j]){
                    if(flag==0){
                        if(flag1[i]==0){
                        res.push_back(arr[i]);
                        res.push_back(arr[j]);
                        flag=1;
                        }
                    }
                    else{
                        if(flag1[j]==0){
                        res.push_back(arr[j]);
                        }
                    }
                    flag1[i]=1;
                    flag1[j]=1;
                    
                }
            }
            if(flag==1){
            ans.push_back(res);
            }
            else if(flag1[i]==0){ 
                res.push_back(arr[i]);
                ans.push_back(res);
            }
        }
        sort(ans.begin(),ans.end());
        
        return ans;
    }
