class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) { //tc=O(n), sc=O(1)
        //step1: sort arr costs using countingSort as per req
        sort(costs.begin(), costs.end());

        int count = 0;   //no of ice creams bars

        //step2: iterate each idx to count
        for(int i=0; i < costs.size(); i++) {
            if(costs[i] <= coins) {
                count++;
                coins = coins - costs[i];   //subtract 
            } else {
                break;
            }
        }

        return count;
    }
};