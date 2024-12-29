 Approach:

Make a frequency hash you can use map or hash array it is totally up to you. I have done using both of them in different codes.
Take the first array and flag the hash array on those particular indexes.
Traverse through the second array and look for common elements, make sure to make the set flag to 0 in the hash array, once you have taken that element to avoid repetition or you can use a set.

vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,int>ump;
        vector<int>ans;
        for(int i=0;i<a.size();i++){
            ump[a[i]]++;
        }
        for(int i=0;i<b.size();i++){
            int chk=b[i];
            if(ump.find(chk)!=ump.end()){
                if(ump[chk]>0){
                    ans.push_back(chk);
                    ump[chk]=0;
                }
            }
        }
        return ans;
    }

Code 2//

 vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        vector<int>res(1000000,0);
        vector<int>ans;
        for(int i=0;i<a.size();i++){
            res[a[i]]++;
        }
        for(int i=0;i<b.size();i++){
           if(res[b[i]]>0){
               ans.push_back(b[i]);
               res[b[i]]=0;
           }
        }
        return ans;
    }
