 Approach
Use an unordered map (ump) to store elements from both arrays as keys.
Iterate through array a and insert its elements into the map.
Iterate through array b and insert its elements into the map.
Return the size of the unordered map, which represents the count of unique elements (union).

Time Complexity
O(m + n): Iterating through arrays a and b, where m is the size of a and n is the size of b.
Space Complexity
O(m + n): Storing all unique elements in the unordered map.

int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,int>ump;
        for(int i=0;i<a.size();i++){
            ump[a[i]]++;
        }
        for(int i=0;i<b.size();i++){
            ump[b[i]]++;
        }
        return ump.size();
    }
