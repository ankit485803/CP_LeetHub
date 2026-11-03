class Solution {
public:
    int minMoves(vector<int>& nums) { //tc=O(n), sc=O(1)
        int maxElem = *max_element(nums.begin(), nums.end());
        int moves = 0;

        for(int &num : nums) {
            moves += maxElem - num;
        }

        return moves;
    }
};