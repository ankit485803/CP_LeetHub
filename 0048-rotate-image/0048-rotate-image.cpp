class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> res(n, vector<int>(n));   //sc=O(n^2)

        for(int i=0; i < n; i++) {  //tc=O(n^2)
            for(int j=0; j<n; j++) {
                res[j][n - 1 - i] = matrix[i][j];  //mainLogic lastRow into firstCol
            }
        }

        //copyToOriginal
        matrix = res;
    }
};