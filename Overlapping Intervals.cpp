Explanation:

Sorting the Intervals:
The first step is to sort the intervals based on their starting points. This helps to process the intervals in a logical sequence, making it easier to merge overlapping intervals.

Initialization:
We initialize two variables:

start: To track the starting point of the current interval being considered.
comp: To track the ending point of the current interval being considered.
Initially, these are set to the start and end of the first interval in the sorted list.

Iterating Through Intervals:

For each interval in the sorted list:
If the current interval's start point (arr[i][0]) is less than or equal to comp (the end of the previous interval), it means the intervals overlap. 
In this case, we update comp to the maximum of the current interval's end point and comp.
If the intervals do not overlap, it means the previous interval has ended. So, we save the current start and comp as a merged interval and reset start and comp to the start and end of the current interval.
Finalizing the Last Interval:
After the loop ends, the last interval may still need to be added to the result list. We push this interval to the result.

Returning the Result:
Finally, we return the list of merged intervals.

vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        int comp=arr[0][1];
        int start=arr[0][0];
        for(int i=1;i<arr.size();i++){
            if(arr[i][0]<=comp){
                comp=max(arr[i][1],comp);
            }
            else{
                vector<int>qr;
                qr.push_back(start);
                qr.push_back(comp);
                ans.push_back(qr);
                start=arr[i][0];
                comp=arr[i][1];
            }
        }
        vector<int>qr1;
        qr1.push_back(start);
        qr1.push_back(comp);
        ans.push_back(qr1);
        return ans;
        
    }
