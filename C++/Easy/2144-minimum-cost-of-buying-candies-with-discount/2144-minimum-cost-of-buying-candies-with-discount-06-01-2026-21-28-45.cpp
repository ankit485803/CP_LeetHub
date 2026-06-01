class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int idx = 1;
        int minCost = 0;

        for(int i=cost.size()-1; i>=0; i--) {
            if(idx % 3 != 0) {
                minCost += cost[i];
            }
            idx++;
        }

        return minCost;
    }
};