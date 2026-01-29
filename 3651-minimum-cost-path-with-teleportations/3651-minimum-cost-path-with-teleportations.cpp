class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // store all cell coordinates
        vector<pair<int,int>> cells;
        cells.reserve(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cells.emplace_back(i, j);
            }
        }

        // sort cells by grid value
        sort(cells.begin(), cells.end(),
             [&](const pair<int,int>& a, const pair<int,int>& b) {
                 return grid[a.first][a.second] < grid[b.first][b.second];
             });

        // cost to reach destination from each cell
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));

        // repeat k+1 times
        for (int t = 0; t <= k; t++) {

            // teleportation update
            int mincost = INT_MAX;
            int start = 0;

            for (int i = 0; i < (int)cells.size(); i++) {
                int x = cells[i].first;
                int y = cells[i].second;

                mincost = min(mincost, cost[x][y]);

                if (i + 1 < (int)cells.size() &&
                    grid[x][y] == grid[cells[i + 1].first][cells[i + 1].second]) {
                    continue;
                }

                // update all cells with same grid value
                for (int j = start; j <= i; j++) {
                    cost[cells[j].first][cells[j].second] = mincost;
                }
                start = i + 1;
            }

            // DP from bottom-right to top-left
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j == n - 1) {
                        cost[i][j] = 0;
                    }

                    // move down
                    if (i != m - 1) {
                        cost[i][j] = min(cost[i][j],
                                          grid[i + 1][j] + cost[i + 1][j]);
                    }

                    // move right
                    if (j != n - 1) {
                        cost[i][j] = min(cost[i][j],
                                          grid[i][j + 1] + cost[i][j + 1]);
                    }
                }
            }
        }

        return cost[0][0];
    }
};
