/*
 * 问题本质在于找出有顺序要求的最大和最小数值。小数要在大数前面。自然想到逆向遍历，然后逐个与当前元
 * 素相减，然后保留最大的差值即为结果。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        int max_profit = 0, profit;
        
        for (int i = length - 1; i > 0; i--)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                profit = prices[i] - prices[j];
                if (profit > max_profit)
                    max_profit = profit;
            }
        }
        
        return max_profit;
    }
};
