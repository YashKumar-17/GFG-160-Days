Initialize Variables:

Start with count = 0 to keep track of the number of subarrays with XOR equal to k.
Use xorsum = 0 to store the cumulative XOR of elements as you traverse the array.
Create a hash map ump to store the frequency of XOR values seen so far, and initialize ump[0] = 1 to handle cases where the subarray itself has XOR k starting from the first element.
Iterate Through the Array:

For each element arr[i], compute the cumulative XOR:xorsum=xorsum⊕arr[i] where ⊕ is the XOR operator.
Check for Subarrays:

Calculate the value xr=xorsum⊕k.
This represents the XOR value that must have occurred before the current position for a subarray with XOR k to exist.
Check if xr is present in the hash map:
If yes, add the frequency of xr in the hash map to count. This is because every occurrence of xr represents a starting point of a subarray ending at the current position i with XOR k.
Update the Hash Map:

Increment the frequency of xorsum in the hash map:ump[xorsum]++
This step ensures that the current cumulative XOR is available for future calculations.
Return the Count:

After iterating through the array, count will contain the total number of subarrays with XOR equal to k.

long subarrayXor(vector<int> &arr, int k) {
        // code here
        int count=0;
        int xorsum=0;
        int n=arr.size();
        unordered_map<int,int>ump;
        ump[0]=1;
        for(int i=0;i<n;i++){
            xorsum=xorsum^arr[i];
            int xr=xorsum^k;
            count+=ump[xr];
            ump[xorsum]++;
        }
        return count;
    }
