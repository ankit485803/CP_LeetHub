class Solution {
public:
    int maxDistance(vector<int>& colors) {  //tcO(n^2) due to nestedLoop, sc=O(1) 
        int n = colors.size();
        int ans = 0;  //maxDist

        for(int i=0; i<n; i++) {
            for(int j=n-1; j>i; j--) {  //when j > i hoga tab tak
                if(colors[i] != colors[j]) {
                    ans = max(ans, abs(i - j)); 
                }
            }
        }

        return ans;
    }
};