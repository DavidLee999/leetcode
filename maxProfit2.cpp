/*
 * 仔细思考，我们想要的是一个局部最小值（不是全局最小），然后找它后面的一个最大值，二者之间的差异就
 * 是最大利润。在第一次遍历的时候，可以用一个变量记录这个最小值，在遍历时不断计算后面的数和它的差值，
 * 最大者即为当前的最大利润；如果碰到一个更小值，记录下来，并看后面能不能遇到更大的利润。这样既只需要一次遍历了。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if (length < 2)
            return 0;
        int max_profit = 0, profit, min_price = prices[0];
        
        for (int i = 1; i < length; i++)
        {
            if (prices[i] < min_price)
            {
                min_price = prices[i];
                // max_profit = 0;
            }
            
            profit = prices[i] - min_price;
            if (profit > max_profit)
                max_profit = profit;
        }
        
        return max_profit;
    }
};
