class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(prices);  // Start by assuming no discounts (same as prices)

        for (int i = 0; i < n; ++i) {  //t=O(n*n) nestedLoop
            // Find the next item with price <= prices[i]
            for (int j = i + 1; j < n; ++j) {
                if (prices[j] <= prices[i]) {
                    result[i] = prices[i] - prices[j];  // Apply the discount
                    break;  
                }
            }
        }

        return result;
    }
};
