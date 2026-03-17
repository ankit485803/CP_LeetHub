class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {  //tc=O(m* nLogN), sc=O(1)
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] && i > 0) {
                    matrix[i][j] += matrix[i-1][j];   //heightMatrix
                }
            }

            vector<int> row = matrix[i];
            sort(row.begin(), row.end(), greater<int>());

            for(int j=0; j<n; j++) {
                ans = max(ans, row[j] * (j + 1)); //greedy about Area = height[j] * [j+1]
            }
        }

        return ans;
    }
};