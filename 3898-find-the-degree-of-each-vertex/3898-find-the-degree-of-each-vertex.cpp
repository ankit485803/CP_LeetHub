class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {  //tc=O(n^2) due to nestedLoop
        int n = matrix.size();
        vector<int> ans(n, 0);  //sc=O(n)

        for(int i=0; i<n; i++) {  //outerLoop- selectNode
            int deg = 0; 
            for(int j=0; j<n; j++) {  //innerLoop-count its connections n*n works
                if(matrix[i][j] == 1) {
                    deg++;
                }
            }
            ans[i] = deg;  //reassig to ans
        }

        return ans;
    }
};