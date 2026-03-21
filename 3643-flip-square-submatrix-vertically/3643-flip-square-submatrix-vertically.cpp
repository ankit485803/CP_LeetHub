class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {  //tc=O(k^2), sc=O(1)
        int stRow = x, endRow = x+k-1;
        int stCol = y, endCol = y + k-1;

        for(int i=stRow; i<=endRow; i++) {
            for(int j=stCol; j<=endCol; j++) {
                swap(grid[i][j], grid[endRow][j] );
            }
            endRow--;
        }

        return grid;
    }
};