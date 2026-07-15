class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int l = prices.size();
        int minPrice = INT_MAX;
        int maxP = 0;
        for(int i = 0; i < l; i++){
            minPrice = min(minPrice, prices[i]);
            maxP = max(maxP, prices[i] - minPrice);
        }
        return maxP;
    }
};