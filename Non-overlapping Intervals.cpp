Approach for the Code

1. Sorting the Intervals
The intervals are sorted based on their end times (intervals[i][1]) using a custom comparator function cust.
Sorting by end time ensures that we consider intervals that finish earlier first, which helps in minimizing overlapping intervals.

2. Initializing Variables
count: Keeps track of the number of non-overlapping intervals. Initially set to 1 because the first interval is always counted.
comp: Stores the end time of the last added interval to the set of non-overlapping intervals. Initially set to the end time of the first interval.

3. Iterating Through the Sorted Intervals
For each interval in the sorted list (starting from the second interval):
Check if the start time of the current interval (intervals[i][0]) is greater than or equal to the end time of the last non-overlapping interval (comp).
If the condition is true: Increment count to include this interval as part of the non-overlapping set.
Update comp to the end time of this interval (intervals[i][1]).
Otherwise, the interval overlaps and is not included in the set of non-overlapping intervals.

4. Calculating the Result
The number of intervals to remove is given by the total number of intervals (n) minus the count of non-overlapping intervals (count).
5. Return Value
The function returns n - count, which represents the minimum number of intervals to remove.

Complexity Analysis
Time Complexity:
Sorting takes O(nlogn).
The iteration through intervals takes O(n).
Overall complexity: O(nlogn).
Space Complexity:
Sorting uses O(1).

static bool cust(const vector<int>&a,const vector<int>&b){
        return a[1]<b[1];
    }
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        sort(intervals.begin(),intervals.end(), cust);
        int count=1;
        int n=intervals.size();
        int comp=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=comp){
                count++;
                comp=intervals[i][1];
            }
        }
        return n-count;
        
        
    }
