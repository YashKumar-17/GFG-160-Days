Approach
Initialization:

buy is initialized to -1: Represents the buying price. If -1, it indicates no stock has been bought yet.
sell is initialized to -1: Represents the selling price. If -1, it indicates no stock has been sold yet.
sum is initialized to 0: Keeps track of the total profit made.
clear is unused in the logic and can be removed.
n holds the size of the prices vector.
Iterate Through the Prices:

Loop through each day (index i) to determine the best times to buy and sell.
Buy Logic:

If no stock is currently bought (buy == -1), set buy to the current day's price (prices[i]).
Sell Logic:

If a stock is bought (buy != -1), and the price on the next day (prices[i+1]) is less than the current price (prices[i]), then sell the stock by setting sell = prices[i].
Adjust Buy Price:

If no stock has been sold (sell == -1) but the price on the next day (prices[i+1]) is less than the buying price (buy), update buy to the current day's price (prices[i]). This ensures you minimize the buying price for future profit.
Calculate Profit:

If both buy and sell are valid (!= -1), add the difference (sell - buy) to sum, and reset buy and sell to -1 for the next transaction.
Handle the Last Day:

If the loop reaches the last day (i == n-1), check if the stock price is greater than the buying price. If so, calculate the profit for this transaction and add it to sum.
Return the Total Profit:

Finally, return the accumulated profit (sum).

Time Complexity:
O(n): The algorithm iterates through the array once.
Space Complexity:
O(1): Only a few variables are used for tracking states, independent of the input size.





int maximumProfit(vector<int> &prices) {
        // code here
        int buy=-1;
       int sell=-1;
       int sum=0;
       int n=prices.size();
       int clear=0;
       for(int i=0;i<n;i++){
           if(buy==-1){
               buy=prices[i];
           }
           if(buy!=-1 && i<n-1 && prices[i+1]<prices[i] && sell==-1){
               sell=prices[i];
           }
           if(buy!=-1 && sell==-1 && i<n-1 && prices[i+1]<buy){
               buy=prices[i];
               continue;
           }
           
           if(buy!=-1 && sell!=-1){
               sum+=sell-buy;
               sell=-1;
               buy=-1;
           }
           if(buy!=-1 &&sell==-1 && i==n-1){
               if(prices[i]>buy){
                   sum+=prices[i]-buy;
               }
           }
       }
       return sum;
           
       
    }
