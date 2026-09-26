class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {

        // Impossible to create m*n cells
        if (original.size() != m * n) {
            return {};
        }

        vector<vector<int>> ansMatr(m, vector<int>(n));  //sc=O(m * n) =sc

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ansMatr[i][j] = original[i * n + j];
            }
        }

        return ansMatr;
    }
};
