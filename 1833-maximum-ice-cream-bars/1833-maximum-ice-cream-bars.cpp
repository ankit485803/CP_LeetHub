class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {  //tc=O( logN), sc=O(1)
        sort(costs.begin(), costs.end());
        int maxIceBar = 0;

        for(int i=0; i<costs.size(); i++) {
            if(coins >= costs[i]) {
                coins -= costs[i];
                maxIceBar++;
            } else {
                break;
            }
        }

        return maxIceBar;
    }
};