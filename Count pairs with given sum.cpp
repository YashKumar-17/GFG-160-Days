Steps:
Initialize an unordered_map (ump) and a counter (count):

ump stores the frequency of numbers encountered so far in the array.
count keeps track of the total number of valid pairs.
Iterate through the array (arr):

For each element, calculate the complementary value (a = target - arr[i]) that would form a valid pair with the current element to achieve the target sum.
Check if the complementary value exists:

If a exists in the ump, it means there are elements before the current one that, when paired with arr[i], sum to the target. Add the frequency of a in ump to count.
Update the map: Increment the frequency of the current element (arr[i]) in ump.

Return the count:After iterating through the array, count will contain the total number of valid pairs.

int countPairs(vector<int> &arr, int target) {
        // Code here
        unordered_map<int,int>ump;
        int count=0;
        for(int i=0;i<arr.size();i++){
            int a=target-arr[i];
            count+=ump[a];
            ump[arr[i]]++;
        }
        return count;
    }

