class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {  //O(m*n), sc=O(1)
        int m = grid.size();
        int n = grid[0].size();  //firstBox

        int count = 0;
        for(int i=0; i<m; i++) {
            for(int j=n-1; j>=0; j--) {
                if(grid[i][j] < 0) {   //whenNegative
                    count++;
                } else {
                    break;
                }
            }
        }

        return count;
    }
};