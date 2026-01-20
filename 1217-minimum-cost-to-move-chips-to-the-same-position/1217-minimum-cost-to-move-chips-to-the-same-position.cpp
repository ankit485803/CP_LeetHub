class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int evenChips = 0;
        int oddChips = 0;

        for(int i=0; i<position.size(); i++) {
            if(position[i] % 2 == 0) {
                evenChips++;
            } else {
                
                oddChips++;
            }
        }
        int minCost = min(evenChips, oddChips);
        return minCost;
    }
};