class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int minCap = INT_MAX;
        int idx = -1;

        for(int i = 0; i < capacity.size(); i++) {
            if(capacity[i] >= itemSize && capacity[i] < minCap) {
                minCap = capacity[i];
                idx = i;
            }
        }

        return idx;
    }
};