class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sell_stack = 0, keep_stock = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            sell_stack = max(sell_stack, keep_stock + prices[i] - fee);
            keep_stock = max(keep_stock, sell_stack - prices[i]);
        }
        return sell_stack;
    }
};