class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {  //tc=O(nlogN), sc=O(1)
        sort(prices.begin(), prices.end());

        int first = prices[0];
        int second = prices[1];

        if(first + second > money) {
            return money;
        }

        return money - (first + second);
    }
};