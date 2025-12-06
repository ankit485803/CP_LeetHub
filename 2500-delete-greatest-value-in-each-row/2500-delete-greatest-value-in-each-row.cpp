#include <algorithm>
#include <climits>

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {  //tc=O(m * n),sc=O(1)
        int m = grid.size();
        int n = grid[0].size();
        int total = 0;

        // Perform the operation until all columns are removed
        for (int j = 0; j < n; ++j) {
            int maxDeletedValue = INT_MIN;

            // Find the maxVal in each row and remove it
            for (int i = 0; i < m; ++i) {
                int rowMax = *max_element(grid[i].begin(), grid[i].end());
                maxDeletedValue = max(maxDeletedValue, rowMax);

                // Remove the max value from the row
                auto it = find(grid[i].begin(), grid[i].end(), rowMax);
                grid[i].erase(it);
            }

            total += maxDeletedValue;
        }

        return total;
    }
};
