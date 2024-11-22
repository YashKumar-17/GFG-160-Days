Approach: Sliding Window/Two Pointer Technique
1. Initialization
Goal: Keep track of the lowest buying price (l) and calculate the potential profit at each day (r).
Use two pointers:
l: Points to the day with the lowest buying price so far.
r: Points to the current day where we might sell.
Variables:
maxi: Tracks the maximum profit obtained so far. Initialize it to 0.
2. Iteration Setup
Start both pointers at the beginning of the list:
l = 0: Represents the initial buy day.
r = 1: Represents the next day (sell day).
Iterate over the prices array until r reaches the end (r < n).
3. Decision-Making for Each Step
Case 1: Price on day r is lower than or equal to the price on day l:

Update l to r (reset the buying day to the current day).
This is because a lower price has been found, which offers a better buying opportunity.
Move r forward (r++).
Case 2: Price on day r is higher than the price on day l:

Calculate the profit: profit=prices[r]−prices[l]
Update maxi if the calculated profit is greater than the current maxi.
Move r forward (r++).
4. End Condition
Continue iterating until r reaches the end of the prices list.
At the end of the loop, maxi will contain the maximum profit obtained.
5. Return Value
Return maxi as the result. If no profit was possible, maxi remains 0.

Time Complexity: O(n);
Auxiliary Space: O(1);


int maximumProfit(vector<int> &prices) {
        // code here
        int maxi=0;
        int l=0;
        int r=1;
        int n=prices.size();
        while(r<n){
            if(prices[r]<=prices[l]){
                l=r;
                r++;
            }
            else{
                maxi=max(maxi,prices[r]-prices[l]);
                r++;
            }
            }
            return maxi;
    }
