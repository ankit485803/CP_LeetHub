class Solution {
public:
    int countOverlaps(vector<vector<int>>& A, vector<vector<int>>& B,
                      int rowOff, int colOff) {
        int n = A.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int ni = i + rowOff;
                int nj = j + colOff;

                // Check if translated position is inside B
                if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                    if (A[i][j] == 1 && B[ni][nj] == 1) {
                        count++;
                    }
                }
            }
        }

        return count;
    }

    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {
        int n = img1.size();
        int maxOverlap = 0;

        // Try every possible translation
        for (int rowOff = -n + 1; rowOff < n; rowOff++) {
            for (int colOff = -n + 1; colOff < n; colOff++) {

                maxOverlap = max(
                    maxOverlap,
                    countOverlaps(img1, img2, rowOff, colOff)
                );
            }
        }

        return maxOverlap;
    }
};
