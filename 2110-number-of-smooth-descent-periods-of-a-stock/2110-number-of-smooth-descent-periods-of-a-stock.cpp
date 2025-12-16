class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {  //tc=O(n), sc=O(1)
        long long totalPeriods = 0;
        int count = 1;  

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] == prices[i - 1] - 1) {
                count++;  
            } else {
                totalPeriods += (long long) count * (count + 1) / 2;
                count = 1;
            }
        }

        totalPeriods += (long long) count * (count + 1) / 2;

        return totalPeriods;
    }
};
