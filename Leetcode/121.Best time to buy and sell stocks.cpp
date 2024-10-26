// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minimum = prices[0], maxProf = 0;
        for(int &val : prices)
        {
            if(val < minimum)
                minimum = val;
            else
                maxProf = max(maxProf, val - minimum);
        }
        return maxProf;
    }
};