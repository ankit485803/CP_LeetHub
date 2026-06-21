class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {  //tc=O(n + maxCost), sc=O(maxCost)
        int maxCost = *max_element(costs.begin(), costs.end());

        vector<int> freq(maxCost + 1, 0);

        // Counting sort frequency array
        for (int cost : costs) {
            freq[cost]++;
        }

        int count = 0;

        // Buy cheapest bars first
        for (int cost = 1; cost <= maxCost && coins >= cost; cost++) {
            if (freq[cost] == 0) continue;

            int canBuy = min(freq[cost], coins / cost);

            count += canBuy;
            coins -= canBuy * cost;
        }

        return count;
    }
};


/*

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) { //tc=O(n logN), sc=O(1)
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

*/