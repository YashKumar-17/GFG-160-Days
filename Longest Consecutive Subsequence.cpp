Approach:
Frequency Map: Use a map to store the frequency of each element in the array. This also sorts the elements in ascending order due to the properties of map.
Find Minimum Element: Track the smallest element (low) in the array during the traversal.
Traverse Sorted Keys:
Start with the smallest element and check if the next element in sequence exists.
Increment the count if the next consecutive element exists.
Reset the count if there is a break in the sequence and update max_count.
Update Maximum Sequence: After completing the iteration, compare and update max_count with the last count.

int longestConsecutive(vector<int>& arr) {
        // Your code here
        map<int,int>mpp;
        int count=1;
        int low=INT_MAX;
        int max_count=INT_MIN;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
            if(arr[i]<low){
                low=arr[i];
            }
        }
        int a=low;
        for(auto it: mpp){
            if(it.first==a){
                continue;
            }
            else{
                if(it.first==a+1){
                    count++;
                    a=it.first;
                }
                else{
                    max_count=max(count,max_count);
                    count=1;
                    a=it.first;
                }
                
            }
        }
        max_count=max(count,max_count);
        return max_count;
    
    }
